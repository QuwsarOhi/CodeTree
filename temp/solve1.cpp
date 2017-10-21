#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};


bitset<410>vis, Node;
bool scan[25][25];
int lft[410], rht[410], visited[410];
vector<int>G[410];
char mat[25][25];

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
		
		for(auto v : G[u]) {
			if(visited[v] == -1) {
				if(visited[v] == 1)
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
				
				if(x < 0 || y < 0 || x >= r || y >= c || scan[i][j] || scan[x][y])
					continue;
				
				scan[i][j] = scan[x][y] = 1;
				if(mat[i][j] == '*' && mat[x][y] == '*') {
					G[i+j+1].push_back(x+y+1);
					G[x+y+1].push_back(i+j+1);
					Node[x+y+1] = Node[i+j+1] = 1;
					cout << i+j+1 << " -- " << x+y+1 << endl;
				}
				else if(mat[i][j] == '*')		// Only Single Point
					Node[i+j+1] = 1;
				else if(mat[x][y] == '*')
					Node[x+y+1] = 1;
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
		
		
		//NodeCount = 0;
		Node.reset();
		memset(scan, 0, sizeof scan);
		GridToList(n, m);
		
		memset(visited, -1, sizeof visited);
		int totalNode = n*m, MinVertexCover = 0;
		
		for(int i = 1; i <= totalNode; ++i) {
			if(visited[i] == -1)
				Bipartite(i);
		}
		
		for(int i = 1; i <= totalNode; ++i) {
			vis.reset();
			MinVertexCover += VertexCover(i);
		}
		
		cout << Node.count() << endl;
		printf("Case %d: %d\n", Case, (int)Node.count() - MinVertexCover);		// Min Edge Cover
		
	}
	
	return 0;
} 
