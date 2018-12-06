// LightOJ
// 1175 - Jane and the Frost Giants

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

char G[202][202];
int n, m, visF[202][202], visE[202][202], dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int print(int x[][202]) {
	printf("\n");
	for(int i = 0; i < 5; ++i, printf("\n"))
		for(int j = 0; j < 5; ++j)
			printf(" %2d", x[i][j]==INF? -1:x[i][j]);
}

void bfsFire(int x, int y) {
	//memset(visF, INF, sizeof visF);
	queue< pair<int, int> >q;
	q.push(make_pair(x, y));
	visF[x][y] = 0;

	int xx, yy, tt;
	while(not q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		tt = visF[x][y]+1;
		for(int i = 0; i < 4; ++i) {
			xx = dx[i] + x;
			yy = dy[i] + y;

			if(xx < 0 or yy < 0 or xx >= n or yy >= m)
				continue;

			if(visF[xx][yy] <= tt or G[xx][yy] == '#')
				continue;

			visF[xx][yy] = tt;
			q.push(make_pair(xx, yy));
		}
	}
}

int bfsEscape(int x, int y) {
	memset(visE, INF, sizeof visE);
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visE[x][y] = 0;

	int xx, yy, tt;
	while(not q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if(x == 0 or y == 0 or x == n-1 or y == m-1)
			return visE[x][y];

		tt = visE[x][y]+1;
		for(int i = 0; i < 4; ++i) {
			xx = dx[i] + x;
			yy = dy[i] + y;

			if(xx < 0 or yy < 0 or xx >= n or yy >= m)
				continue;

			if(visE[xx][yy] <= tt or G[xx][yy] == '#' or G[xx][yy] == 'F')
				continue;

			if(visF[xx][yy] <= tt and visF[xx][yy] != 0)
				continue;
			//cerr << xx << " " << yy << endl;
			visE[xx][yy] = tt;
			q.push(make_pair(xx, yy));
		}
	}
	return -1;
}

int main() {
	int t, Jx, Jy;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; ++i)
			scanf("%s", G[i]);

		memset(visF, INF, sizeof visF);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				if(G[i][j] == 'F')
					bfsFire(i, j);
				if(G[i][j] == 'J')
					Jx = i, Jy = j;
			}

		//cerr << "DONE\n";
		//bfsFire(Fx, Fy);
		//print(visF);

		printf("Case %d: ", Case);
		int ans = bfsEscape(Jx, Jy);

		//print(visE);
		if(ans == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans+1);
	}

	return 0;
}