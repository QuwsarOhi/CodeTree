// LightOJ
// 1152 - Hiding Gold 

#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
bitset<410>vis, Node;
int lft[410], rht[410], visited[410];
vector<int>G[410];
char mat[25][25];
map<pair<int, int>, bool>mp;


int NodeNumber(int r, int c, int n, int m) {
	return  m*r + c + 1;
}

bool VertexCover(int u) {
	vis[u] = 1;
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		if(vis[v])
			continue;
		vis[v] = 1;
		
		if(lft[v] == -1) {
			lft[v] = u;
			rht[u] = v;
			return 1;
		}
		
		else if(VertexCover(lft[v])) {
			lft[v] = u;
			rht[u] = v;
			return 1;
		}
	}
	return 0;
}

void Bipartite(int u) {
	queue<int>q;
	q.push(u);
	visited[u] = 1;
	
	while(!q.empty()) {
		u = q.front();
		q.pop();
		
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			if(visited[v] == -1) {
				if(visited[u] == 1)
					visited[v] = 2;
				else
					visited[v] = 1;
				q.push(v);
			}
		}
	}
}

void GridToList(int r, int c) {
	
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			for(int k = 0; k < 4; ++k) {
				int x = i + dx[k];
				int y = j + dy[k];
				
				if(x < 0 || y < 0 || x >= r || y >= c)
					continue;
				
				int u = NodeNumber(i, j, r, c), v = NodeNumber(x, y, r, c);
				if(mat[i][j] == '*' && mat[x][y] == '*') {
					if(mp.find({u, v}) != mp.end())
						continue;
					G[u].push_back(v);
					G[v].push_back(u);
					Node[v] = Node[u] = 1;
					mp[{u, v}] = mp[{v, u}] = 1;
				}
				else if(mat[i][j] == '*')		// Only Single Point
					Node[u] = 1;
				else if(mat[x][y] == '*')
					Node[v] = 1;
			}
		}
	}
}


int main() {
	int t, n, m;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &n, &m);
		
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf(" %c", &mat[i][j]);
		
		Node.reset();
		mp.clear();
		GridToList(n, m);
		
		memset(visited, -1, sizeof visited);
		int totalNode = n*m, MinVertexCover = 0;
		
		for(int i = 1; i <= totalNode; ++i) {
			if(visited[i] == -1)
				Bipartite(i);
		}
			
		memset(lft, -1, sizeof lft);
		memset(rht, -1, sizeof rht);
		
		for(int i = 1; i <= totalNode; ++i) {
			vis.reset();
			if(visited[i] == 1)
				MinVertexCover += VertexCover(i);
		}
		
		printf("Case %d: %d\n", Case, (int)Node.count() - MinVertexCover);		// Min Edge Cover
		
		for(int i = 1; i <= totalNode; ++i)
			G[i].clear();
	}
	
	return 0;
} 
