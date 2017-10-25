// LightOJ
// 1002 - Country Roads 

#include <bits/stdc++.h>
#define INF 1e7
using namespace std;

vector<int>G[510], W[510];
int dist[520];

void bfs(int start) {
	for(int i = 0; i <= 505; ++i)
		dist[i] = INF;
	queue<int>q;
	q.push(start);
	dist[start] = 0;
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			int mxDist = max(dist[u], W[u][i]);
			
			if(mxDist < dist[v]) {
				dist[v] = mxDist;
				q.push(v);
			}
		}
	}
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, hi, finish, u, v, w, V, E;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &V, &E);
		hi = 0;
		for(int i = 0; i < E; ++i) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(v);
			G[v].push_back(u);
			W[v].push_back(w);
			W[u].push_back(w);
			hi = max(hi, w);
		}
		
		scanf("%d", &finish);
		printf("Case %d:\n", Case);
		
		bfs(finish);
		
		for(int i = 0; i < V; ++i) {
			if(dist[i] == INF)
				printf("Impossible\n");
			else
				printf("%d\n", dist[i]);
		}
		
		for(int i = 0; i < V; ++i) {
			G[i].clear();
			W[i].clear();
		}
	}
	return 0;
}
