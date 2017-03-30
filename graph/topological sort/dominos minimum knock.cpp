//UVa
//11504 - Dominos
//Topological Sort, Checking

#include <bits/stdc++.h>
using namespace std;

vector<int> G[100010];
bitset<100010> visited;
stack<int>st;


void topsort(int u)
{
	visited[u] = 1;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(!visited[v])
			topsort(v);
	}
	
	st.push(u);
}

void dfs(int u)
{
	visited[u] = 1;
	
	for(int i= 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(!visited[v])
			dfs(v);
	}
}

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		int V, E, u, v, knock = 0;
		scanf("%d %d", &V, &E);
		while(E--) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}
		visited.reset();
		for(int i = 1; i <= V; i++)
			if(!visited[i])
				topsort(i);
		visited.reset();
		while(!st.empty()) {
			int u = st.top();
			st.pop();
			if(!visited[u]) {
				knock++;
				dfs(u);
			}
		}

		printf("%d\n", knock);
		
		for(int i = 0; i <= V; i++)
			G[i].clear();
	}
	return 0;
}
