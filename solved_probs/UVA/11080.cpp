//UVa
//11080 - Place the Guards
//Bipartite Check

#include <bits/stdc++.h>
using namespace std;

vector<int> G[210];
int color[210];
bitset<210>visited;

int bipartite(int U)
{
	int total = 0, black = 0;
	queue<int>q;
	q.push(U);
	color[U] = 0;
	black++;
	visited[U] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		++total;
		for(int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			if(!visited[v]) {
				visited[v] = 1;
				color[v] = 1 - color[u];
				if(color[v] == 0)
					black++;
				q.push(v);
			}
			else if(color[u] == color[v])
				return -1;
		}
	}
	if(total == 1)
		return 1;
	else
		return min(black, total - black);
}

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int V, E, u, v;
		scanf("%d %d", &V, &E);
		
		while(E--) { 
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		visited.reset();
		int guards = 0;
		for(int i = 0; i < V; i++)
			if(!visited[i]) {
				int tmp = bipartite(i);
				if(tmp == -1) {
					guards = tmp;
					break;
				}
				else
					guards += tmp;
			}
		
		printf("%d\n", guards);
		
		for(int i = 0; i < V; i++)
			G[i].clear();
	}
	return 0;
}
