//UVa
//10449 - Traffic
//Negative Cycle, Single Source Shortest Path, bellman ford

#include <bits/stdc++.h>
#define INF 1e6
using namespace std;

vector<int> G[210];
int dist[210], W[210], V;

void bellmanFord()
{
	for(int i = 0; i <= V; i++)
		dist[i] = INF;

	dist[1] = 0;
	for(int i = 0; i < V-1; i++) {
		bool not_updated = 1;
		for(int u = 1; u <= V; u++)
			for(int j = 0; j < G[u].size(); j++) {
				int v = G[u][j];
				int w = (W[v] - W[u])*(W[v] - W[u])*(W[v] - W[u]);

				if(dist[u] != INF)  //avoiding +- INF cases
					if(dist[u] + w < dist[v]) {
						not_updated = 0;
						dist[v] = dist[u] + w;
					}
			}
		if(not_updated) {   //if not relaxed, then no need to go for second loop
			break;
		}
	}
}


void dfs(int u)
{
	dist[u] = -INF;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(dist[v] != -INF)
			dfs(v);
	}
}

void negativeCycle()
{
	for(int u = 1; u <= V; u++)
		for(int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			int w = W[v] - W[u];
			w = w * w * w;

			if(dist[v] > dist[u] + w && dist[u] != INF) {
				//all nodes have negative distance connected with v
				dfs(v);
			}
		}
}

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	int E, u, v, Case = 1;
	while(scanf(" %d ", &V) == 1) {
		for(int i = 1; i <= V; i++)
			scanf("%d", &W[i]);
		scanf("%d", &E);
		while(E--) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}
		int q;
		scanf("%d", &q);
		bellmanFord();
		negativeCycle();
		printf("Set #%d\n", Case++);
		while(q--) {
			int x;
			scanf("%d", &x);
			if(dist[x] < 3 || dist[x] == INF)
				printf("?\n");
			else
				printf("%d\n", dist[x]);
		}
		for(int i = 0; i <= V; i++)
			G[i].clear();
	}
	return 0;
}

