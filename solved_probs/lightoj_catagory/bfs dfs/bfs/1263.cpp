// LightOJ
// 1263 - Equalizing Money

#include <bits/stdc++.h>
using namespace std;

vector<int>G[1010];
int c[1010];
bitset<1010>vis;

int dfs(int u) {
	if(vis[u]) return 0;
	vis[u] = 1;
	int ret = 0;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		ret += dfs(v);
	}

	return ret += c[u];
}

int main() {
	int t, V, E, u, v;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &V, &E);

		for(int i = 0; i < V; ++i)
			scanf("%d", &c[i]);

		for(int i = 0; i < E; ++i) {
			scanf("%d%d", &v, &u);
			--u, --v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		vis.reset();
		bool ok = 1;
		int pst, pres, cst, fx = -1;
		for(int i = 0; i < V and ok; ++i) {
			pst = vis.count();
			cst = dfs(i);
			pres = vis.count();
			pres -= pst;

			if(pres == 0)
				continue;

			if(cst%pres != 0) {
				ok = 0;
				continue;
			}

			if(fx == -1)
				fx = cst/pres;
			else if(fx != cst/pres)
				ok = 0;
		}

		printf("Case %d: %s\n", Case, ok == 1 ? "Yes":"No");

		for(int i = 0; i < V; ++i)
			G[i].clear();
	}

	return 0;
}