// LightOJ
// 1019 - Brush (V) 

#include <bits/stdc++.h>
using namespace std;

int dist[1010];
vector<int>G[1010], W[1010];

int dikjstra(int Start, int End, int V) {
	priority_queue<pair<int, int> >pq;
	for(int i = 1; i <= V; ++i)
		dist[i] = 1e7;
	dist[Start] = 0;
	
	pq.push(make_pair(0, Start));
	
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		
		if(u == End)
			return dist[u];
		
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			
			if(dist[v] > dist[u] + W[u][i]) {
				dist[v] = dist[u] + W[u][i];
				pq.push(make_pair(-dist[v], v));
			}
		}
	}
	
	return -1;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, V, E, u, v, w;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &V, &E);
		
		for(int i = 0; i < E; ++i) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(v);
			G[v].push_back(u);
			W[u].push_back(w);
			W[v].push_back(w);
		}
		
		printf("Case %d: ", Case);
		int ans = dikjstra(1, V, V);
		
		if(ans == -1)
			printf("Impossible\n");
		else
			printf("%d\n", ans);
		
		for(int i = 1; i <= V; ++i) {
			G[i].clear();
			W[i].clear();
		}
	}
	return 0;
}
