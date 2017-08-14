// LightOJ
// 1300 - Odd Personality
// Bridge, Bipartite

// We need to find out the number of nodes if and only if the graph has odd cycle
// Bridges don't perform any cycle, so we need to cut off all the bridges, otherwiese, the bridges will affect our counting
// If there is any odd cycle (a cycle may be a part of anoter cycle) in a graph, then the entire graph is odd cycled (the small/big even cycles will also become a part of the odd cycle, draw some graphs!)
// a graph is Bipartite if there is even cycles in the entire graph, So we'll check if the graph is bipartite or not, if not, then all the nodes (except the bridge nodes that don't ifterfere in any cycle) are the answer

// Some Graphs:
// 0 -- 1 - 4
// | \  |
// 2 -- 3

// note here 1 - 4 is a bridge, but 1 is still in a loop, so we need to count it
// loop 0 - 1 - 3 - 2 is even
// but loop 0 - 1 - 3 and loop 0 - 2 - 3 is odd so we found total four unique nodes, ans is 4
//
// 0 -- 1 - 4			ans is zero
// |    |
// 2 -- 3

#include <bits/stdc++.h>
using namespace std;

vector<int>G[10010];
int dfs_num[10010], dfs_low[10010], parent[10010], dfsCounter, ans, bipartiteNodes;
map<pair<int, int>, bool>bridges;
bitset<10010>visited;


bool bipartite(int u) {
	bool ok = 1;
	queue<pair<int, int> >q;
	q.push(make_pair(-1, u));
	visited[u] = 1;
	while(!q.empty()) {
		u = q.front().second;
		bipartiteNodes++;
		q.pop();
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			if(bridges.find(make_pair(u, v)) != bridges.end())
				continue;
			if(!visited[v]) {
				visited[v] = 1;
				if(dfs_num[u] == 0)
					dfs_num[v] = 1;
				else
					dfs_num[v] = 0;
				q.push(make_pair(u, v));
			}
			else if(dfs_num[v] == dfs_num[u]) {
				ok = 0;
			}
		}
	}
	return ok;
}


void findBridges(int u) {
	dfs_low[u] = dfs_num[u] = ++dfsCounter;
	
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		
		if(dfs_num[v] == 0) {
			parent[v] = u;
			findBridges(v);
			
			if(dfs_num[u] < dfs_low[v]) {
				bridges[make_pair(u, v)] = 1;
				bridges[make_pair(v, u)] = 1;
			}
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
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
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		memset(dfs_num, 0, sizeof(dfs_num));
		memset(parent, -1, sizeof(parent));
		
		for(int i = 0; i < V; ++i) {
			if(dfs_num[i] == 0) {
				dfsCounter = 0;
				findBridges(i);
			}
		}
		
		visited.reset();
		memset(dfs_num, 0, sizeof(dfs_num));
		ans = 0;
		for(int i = 0; i < V; ++i) {
			if(!visited[i]) {
				bipartiteNodes = 0;
				if(!bipartite(i)) {
					ans+= bipartiteNodes;
				}
			}
		}
		
		printf("Case %d: %d\n", Case, ans);
		for(int i = 0; i < V; ++i)
			G[i].clear();
		bridges.clear();
	}
	
	return 0;
	
}
