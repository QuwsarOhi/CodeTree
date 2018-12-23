#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define XX first
#define YY second
using namespace std;
typedef pair<int, int> pii;

bool vis[1010][1010][3], mark[1010][1010][3];
pii pst[1010][1010][3];

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};


void recur(int x, int y, pii s, int mrk) {
	cerr << x << " " << y << " " << mrk << endl;
	mark[x][y][mrk] = 1;
	if(x == s.XX and y == s.YY)
		return;
	recur(pst[x][y][mrk].XX, pst[x][y][mrk].YY, s, mrk);
}

int bfs(pii s, pii t, const int mrk) {
	queue< pair<pii, int> >q;

	q.push({s, 0});
	vis[s.XX][s.YY][mrk] = 1;

	pii u, v;
	int mn = 1000000000, d;

	while(not q.empty()) {
		u = q.front().XX;
		d = q.front().YY+1;
		q.pop();

		if(d > mn)
			continue;

		/*if(u == t) {
			if(d > mn)
				return mn;
			mn = d;
			recur(u.XX, u.YY, s, mrk);
			cerr << endl;
			continue;
		}*/

		for(int i = 0; i < 4; ++i) {
			int xx = u.XX + dx[i];
			int yy = u.YY + dy[i];

			if(xx > 1000 or yy > 1000 or xx < 0 or yy < 0) continue;

			if(make_pair(xx, yy) != t and vis[xx][yy][mrk]) continue;
			vis[xx][yy][mrk] = 1;
			pst[xx][yy][mrk] = make_pair(u.XX, u.YY);

			if(make_pair(xx, yy) == t) {
				if(d > mn)
					continue;
				mn = d;
				recur(t.XX, t.YY, s, mrk);
				cerr << endl;
				continue;
			}

			q.push({{xx, yy}, d});
		}
	}

	return mn;
}

vector<pii> ans;

int main() {
	int sx[3], sy[3];

	for(int i = 0; i < 3; ++i) {
		scanf("%d%d", &sx[i], &sy[i]);
	}

	int p = bfs({sx[0], sx[0]}, {sx[1], sx[1]}, 0);
	int q = bfs({sx[0], sx[0]}, {sx[2], sx[2]}, 1);
	int r = bfs({sx[1], sx[1]}, {sx[2], sx[2]}, 2);

	cout << p << " " << q << " " << r << endl;

	for(int i = 0; i <= 1000; ++i)
		for(int j = 0; j <= 1000; ++j) {
			if(mark[i][j][0] and mark[i][j][1] and mark[i][j][2])
				ans.push_back({i, j});
		}

	printf("%d\n", ans.size());
	for(auto it : ans)
		printf("%d %d\n", it.XX, it.YY);

	return 0;
}