#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

int dx[] = {0, -1, 1, 0}, dy[] = {-1, 0, 0, 1}, lft[700], rht[700];

char mat[30][30];
vector<int> G[700], W[700], GostNode;
bitset<700>vis;

int NodeNumber(int i, int j, int n) {
	return i*n + j + 1;
}

void BFS(int i, int j, int n) {
	queue<pair<int, pair<int, int> > >q;
	map<pair<int, int>, bool> visited;
	int u = NodeNumber(i, j, n);
	
	q.push(mp(0, mp(i, j)));

	visited[mp(i, j)] = 1;
	
	while(!q.empty()) {
		int d = q.front().first;
		int _x = q.front().second.first;
		int _y = q.front().second.second;
		q.pop();
		
		if(mat[_x][_y] == 'H') {
			int v = NodeNumber(_x, _y, n);
			cout << "Adding " << u << " -- " << v << endl;
			G[u].push_back(v);
			G[v].push_back(u);
			W[u].push_back(d);
			W[v].push_back(d);
			cout << "done" << endl;
			//continue;
		}
		
		for(int k = 0; k < 4; ++k) {
			int x = _x + dx[k];
			int y = _y + dy[k];
			
			if(x < 0 || y < 0 || x >= n || y >= n)
				continue;
			
			if(!visited[make_pair(x, y)]) {
				if(mat[x][y] != '#') {
					visited[mp(x, y)] = 1;
					q.push(mp(d+1, mp(x, y)));
				}
			}
		}
	}
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

bool VertexCoverCount(int MaxWeight) {
	memset(lft, -1, sizeof lft);
	memset(rht, -1, sizeof rht);
	
	int cnt = 0;
	
	for(int i = 0; i < (int)GostNode.size(); ++i) {
		vis.reset();		
		cnt += VertexCover(GostNode[i]);	
	}
	
	if(cnt == (int)GostNode.size())
		return 1;
	return 0;
}

int BinarySearch(int lo, int hi) {
	int ans = -1, mid;
	
	while(lo < hi) {
		mid = (lo+hi)/2;
		
		if(VertexCoverCount(mid)) {
			lo = mid + 1;
			ans = mid;
		}
		else
			hi = mid;
	}
	
	return ans;
}

int main() {
	int t, n;
	
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf(" %c", &mat[i][j]);
				
		
		cout << "Input Taken\n";
				
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(mat[i][j] == 'G') {
					BFS(i, j, n);
					GostNode.push_back(NodeNumber(i, j, n));
				}
		
		cout << "BFS Done\n";
		
		int ans = BinarySearch(0, 700);
					
		printf("Case %d: %d\n", Case, ans);
	}
	
	return 0;
}
		
		
		
