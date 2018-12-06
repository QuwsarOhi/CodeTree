#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};
char dir[] = {'E', 'N', 'S', 'W'};

char G[20][20];
int dist[20][20], n, m;

vector<pair<int, int> > st;

int bfs(int x, int y) {
	memset(dist, INF, sizeof dist);
	queue<pair<int, int> >q;
	q.push(make_pair(x, y));
	dist[x][y] = 0;

	while(not q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if(x == 0 or x == n-1 or y == 0 or y == m-1)
			return dist[x][y];

		for(int i = 0; i < 4; ++i) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if(xx < 0 or yy < 0 or xx >= n or yy >= m or G[xx][yy] == '#')
				continue;

			if(dist[xx][yy] != INF)
				continue;

			dist[xx][yy] = dist[x][y] + 1;
			q.push(make_pair(xx, yy));
		}
	}
	return -1;
}

vector<string> paths;
string s;
void recur(int pos) {
	if(pos == 12)
		return;

	if(not s.empty())
		paths.push_back(s);

	for(int i = 0; i < 4; ++i) {
		s.push_back(dir[i]);
		recur(pos+1);
		s.pop_back();
	}
}

int main() {
	int t;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; ++i) {
			scanf("%s", G[i]);
			for(int j = 0; j < m; ++j)
				if(G[i][j] == '.')
					st.push_back(make_pair(i, j));
		}

		int pathLen = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(G[i][j] == '.')
					pathLen = max(pathLen, bfs(i, j));

		cerr << "DONE " << pathLen << endl;

		recur(0);
		cout << paths.size() << endl;
	}
	return 0;
}