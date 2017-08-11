// LightOJ
// 1063 - Ant Hills
// Articulation Point

#include <bits/stdc++.h>
using namespace std;


vector<int>G[10010];
int dfs_low[10010], dfs_num[10010], parent[10010], dfsCounter, dfsRoot, rootChildren;
bitset<10010>articulationPoint;

void articulationPoints(int u) {
	dfs_num[u] = dfs_low[u] = ++dfsCounter;
	
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		
		if(dfs_num[v] == 0) {
			parent[v] = u;
			
			if(u == dfsRoot)
				rootChildren++;
			
			articulationPoints(v);
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			
			if(dfs_num[u] <= dfs_low[v] && u != dfsRoot)
				articulationPoint[u] = 1;
		}
		
		else if(parent[u] != v)
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, u, v, V, E;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &V, &E);
		for(int i = 0; i < E; ++i) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		articulationPoint.reset();
		memset(parent, -1, sizeof(parent));
		memset(dfs_num, 0, sizeof(dfs_num));
		
		for(int i = 1; i <= V; ++i) {
			if(dfs_num[i] == 0) {
				dfsCounter = rootChildren = 0;
				dfsRoot = i;
				articulationPoints(i);
				if(rootChildren > 1)
					articulationPoint[i] = 1;
			}
		}
		
		printf("Case %d: %d\n", Case, (int)articulationPoint.count());
		
		if(Case != t)
			for(int i = 1; i <= V; ++i)
				G[i].clear();
	}

	return 0;
}

/* Test Case
2

6 5
1 2
2 3
2 5
5 3
5 6

6 6
1 2
2 3
2 5
5 6
2 4
6 2

Case 1 : 2
Case 2 : 1
*/
