#include <bits/stdc++.h>
#define MAX 509
using namespace std;

int c[MAX], mem[MAX], memT[MAX];
bool vis[MAX];
vector<int> G[MAX], G_T[MAX];

int dfs(int u) {
	if(vis[u])
		return 0;
	vis[u] = 1;
	int ret = c[u];
	if(mem[u] != -1)
		return mem[u];
	for(auto v : G[u])
		ret += dfs(v);
	mem[u] = ret;
	return ret;
}

int dfsT(int u) {
	if(vis[u])
		return 0;
	vis[u] = 1;
	int ret = c[u];
	if(memT[u] != -1)
		return memT[u];
	for(auto v : G_T[u])
		ret += dfsT(v);
	memT[u] = ret;
	return ret;
}

int main() {
	int V, E, u, v;

	for(int Case = 1; ; ++Case) {
		cin >> V >> E;
		if(V == 0 and E == 0)
			break;

		for(int i = 0; i < MAX; ++i) {
			G[i].clear();
			G_T[i].clear();
		}

		int tot = 0;
		for(int i = 1; i <= V; ++i) {
			cin >> c[i];
			tot += c[i];
		}

		for(int i = 0; i < E; ++i) {
			cin >> u >> v;
			G_T[u].push_back(v);
			G[v].push_back(u);
		}

		int q;
		cin >> q;

		memset(mem, -1, sizeof mem);
		memset(memT, -1, sizeof memT);

		cout << "Case #" << Case << ":\n";
		while(q--) {
			cin >> u;
			int mn = dfsT(u);
			memset(vis, 0, sizeof vis);
			int mx = tot - dfs(u) + c[u];
			memset(vis, 0, sizeof vis);
			cout << mx << " " << mn << endl;
			cout << mx - mn << "\n";
		}
		cout << "\n";
	}

	return 0;
}


/*

6 5
4 3 2 1 2 2
2 1
2 4
3 1
3 4
5 6
6
1 2 3 4 5 6

5 4
1 2 3 4 5
2 1
4 2
5 2
3 1
5
1 2 3 4 5

3 3
1 2 3
2 1
3 2
3 1
3
1 2 3

0 0

*/
