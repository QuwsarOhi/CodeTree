//UVa
//929 - Number Maze
//Single Source Shortest Path Dikjstra 2D Grid

#include <bits/stdc++.h>
#define MAX 1010
#define INF 1e6

using namespace std;

int dist[MAX][MAX], mat[MAX][MAX], R, C;
int r[] = {-1, 0, 1, 0}, c[] = {0, 1, 0, -1};



void dikjstra(int start_x, int start_y)
{
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			dist[i][j] = INF;
	dist[start_x][start_y] = mat[start_x][start_y];
	
	priority_queue<pair<int, pair<int, int> > >pq;
	pq.push(make_pair(-mat[start_x][start_y], make_pair(-start_x, -start_y)));
	
	while(!pq.empty()) {
		int _x = -pq.top().second.first;
		int _y = -pq.top().second.second;
		int _w = -pq.top().first;
		
		pq.pop();
		
		if(_w > dist[_x][_y]) {
			continue;
		}
			
		for(int i = 0; i < 4; i++) {
			int x = _x + r[i];
			int y = _y + c[i];
			int w = mat[x][y];
	
			if(x < 0 || y < 0 || x >= R || y >= C) {
				continue;
			}
			
			if(_w + w < dist[x][y]) {
				dist[x][y] = w + _w;
				pq.push(make_pair(-dist[x][y], make_pair(-x, -y)));
			}
		}
	}
}

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &R, &C);
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				scanf(" %d ", &mat[i][j]);
		dikjstra(0, 0);
		printf("%d\n", dist[R-1][C-1]);	
	}
	return 0;
}
