//UVa
//11838 - Come and Go
//Strongly Connected Components

#include <bits/stdc++.h>
using namespace std;

vector<int> G[2010];
bitset<2010>visited;
int dfs_num[2010], dfs_low[2010], dfsCounter;
stack<int> SCC;


bool tarjanSCC(int u, int V)
{
	SCC.push(u);
	dfs_num[u] = dfs_low[u] = ++dfsCounter;
	visited[u] = 1;
	
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		
		if(dfs_num[v] == 0)
			tarjanSCC(v, V);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	
	if(dfs_num[u] == dfs_low[u]) {
		int connected_components = 0;
		while(1) {
			int v = SCC.top();
			SCC.pop();
			visited[v] = 0;
			connected_components++;
			if(v == u)
				break;
		}

		if(connected_components == V)
			return 1;
	}
	
	return 0;
}
			

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int V, E, u, v, w;
	while(scanf(" %d %d", &V, &E) && (V || E)) {
		while(E--) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(v);
			if(w == 2)
				G[v].push_back(u);
		}
		memset(dfs_num, 0, sizeof(dfs_num));
		visited.reset();
		dfsCounter = 0;
		while(!SCC.empty())
			SCC.pop();
		if(tarjanSCC(1, V))
			printf("1\n");
		else
			printf("0\n");
		
		for(int i = 0; i <= V; i++)
			G[i].clear();
	}
	return 0;
}
