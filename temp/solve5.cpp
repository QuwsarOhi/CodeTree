#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

int sparse[MAX][22], lvl[MAX], tot[MAX];
vector<int>G[MAX];

int dfs(int u, int par, int l) {
	lvl[u] = l;
	sparse[u][0] = par;
	tot[u] = 1;
	for(auto v : G[u])
		if(v != par)
			tot[u] += dfs(v, u, l+1);
	return tot[u];
}

int FindPar(int u, int p) {
	for(int i = 20; i >= 0 and u >= 0; --i) {
		if(p & (1 << i))
			u = sparse[u][i];
	}
	return u;
}

int LCA(int a, int b) {
	if(lvl[a] < lvl[b])
		swap(a, b);

	for(int i = 20; i >= 0; --i)
		if(lvl[a] - (1 << i) >= lvl[b])
			a = sparse[a][i];

	if(a == b)
		return a;

	for(int i = 20; i >= 0; --i)
		if(sparse[a][i] != sparse[b][i] and sparse[a][i] != -1)
			a = sparse[a][i], b = sparse[b][i];

	return sparse[a][0];
}

int Nodes(int a, int b) {
	int d = abs(lvl[a] - lvl[b]) + 1;
	return d;
}


pair<int, int> SubLCA(int a, int b) {
	if(lvl[a] != lvl[b]) return make_pair(-MAX, -MAX);

	int c = 0;
	for(int i = 20; i >= 0; --i)
		if(sparse[a][i] != sparse[b][i] and sparse[a][i] != -1)
			a = sparse[a][i], b = sparse[b][i];

	return make_pair(a, b);
}

int solve(int a, int b) {
	if(a == b) return tot[1];

	if(lvl[a] < lvl[b])			// b is on top
		swap(a, b);

	int c = LCA(a, b);
	int d = lvl[a] + lvl[b] - 2*lvl[c] - 1;

	if(d <= 0 or d%2 == 0)
		return 0;

	// if LCA is the answer
	if(lvl[a] - lvl[c] == lvl[b] - lvl[c]) {
		pair<int, int> x = SubLCA(a, b);
		return tot[1] - tot[x.first] - tot[x.second];
	}

	// if answer is on left chain (parent of a)
	int p = (d+1)/2;
	return tot[FindPar(a, p)] - tot[FindPar(a, p-1)];
}

int main() {
	int n, u, v;
	cin >> n;

	for(int i = 1; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	memset(sparse, -1, sizeof sparse);
	tot[1] = dfs(1, -1, 0);

	for(int p = 1; (1 << p) <= n; ++p)
		for(u = 1; u <= n; ++u)
			if(sparse[u][p-1] != -1)
				sparse[u][p] = sparse[sparse[u][p-1]][p-1];

	int q;
	cin >> q;

	while(q--) {
		cin >> u >> v;
		cout << solve(u, v) << endl;
	}

	return 0;
}