#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

typedef long long ll;

int par[MAX][21], lvl[MAX];
vector<int>G[MAX];

int getPar(int u, int p) {
	for(int i = 20; i >= 0; --i)
		if(p & (1 << i))
			u = par[u][i];
	return u;
} 

void dfs(int u, int p = 0) {
	par[u][0] = p;
	lvl[u] = lvl[p]+1;

	for(int i = 1; i <= 20; ++i)
		par[u][i] = par[par[u][i-1]][i-1];

	for(int i = 0; i < G[u].size(); ++i)
		if(G[u][i] != p)
			dfs(G[u][i], u);
}

int LCA(int u, int v) {
	if(lvl[u] < lvl[v]) swap(u, v);

	for(int p = 20; p >= 0; --p)
		if(lvl[u] - (1 << p) >= lvl[v])
			u = par[u][p];

	if(u == v) return u;

	for(int p = 20; p >= 0; --p)
		if(par[u][p] != par[v][p])
			u = par[u][p], v = par[v][p];

	return par[u][0];
}


int main() {
	int t, u, v, x, y, n, typ, q;
	
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}

		dfs(0);
		scanf("%d", &q);

		while(q--) {
			scanf("%d", &typ);

			if(typ == 0) {
				scanf("%d%d", &x, &y);
				par[y][0] = x;

				for(int p = 1; p <= 20; ++p)
					par[y][p] = par[par[y][p-1]][p-1];
			}
			else if(typ == 1) {
				scanf("%d", &x);
				memset(par[x], 0, sizeof par[x]);
			}
			else {
				scanf("%d%d", &x, &y);
				printf("%d\n", getPar(x, y));
			}
		}

		for(int i = 0; i < MAX; ++i)
			G[i].clear();
		memset(par, 0, sizeof par);
	}
}