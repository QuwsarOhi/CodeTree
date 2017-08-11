// LightOJ
// 1026 - Critical Links
// Articulation Point

#include <bits/stdc++.h>
using namespace std;

vector<int>G[100010];

int dfs_num[100010], dfs_low[100010], dfsCounter, parent[100010];
priority_queue<pair<int, int> >bridges;


void bridge(int u) {
	dfs_low[u] = dfs_num[u] = ++dfsCounter;
	
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		
		if(dfs_num[v] == 0) {					// Not visited yet
			parent[v] = u;
			bridge(v);
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			
			if(dfs_num[u] < dfs_low[v])
				bridges.push(make_pair(-min(u, v), -max(u, v)));
		}
		
		else if(parent[u] != v)						// Visited and the node v is not the parent of u (Backedge)
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, u, v, V, E;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &V);
		
		for(int i = 0; i < V; ++i) {
			scanf(" %d (%d)", &u, &E);
			while(E--) {
				scanf("%d", &v);
				G[u].push_back(v);
			}
		}
		
		memset(dfs_num, 0, sizeof(dfs_num));
		memset(dfs_low, 0 ,sizeof(dfs_low));
		memset(parent, -1, sizeof(parent));

		
		for(int i = 0; i < V; ++i) {
			if(dfs_num[i] == 0) {
				dfsCounter = 0;
				bridge(i);
			}
		}
		
		printf("Case %d:\n", Case);
		printf("%d critical links\n", (int)bridges.size());
		while(!bridges.empty()) {
			printf("%d - %d\n", -bridges.top().first, -bridges.top().second);
			bridges.pop();
		}
		
		for(int i = 0; i < V; ++i)
			G[i].clear();
	}
	
	return 0;
}
