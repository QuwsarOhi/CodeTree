#include <bits/stdc++.h>
using namespace std;

int r[] = {-1, -1, -1, 0, 0, 1, 1, 1}, c[] = {-1, 0, 1, -1, 1, -1, 0, 1}, counter, mat[710][710], N, M;
bool visited[710][710];


void dfs(int x, int y) {
	if(!visited[x][y]) {
		for(int i = 0; i < 8; ++i) {
			int _x = x + r[i];
			int _y = y + c[i];
		
			if(_x >  N || _x < 0 || _y > M || _y < 0)
				continue;
			
			if(mat[_x][_y] > mat[x][y] || visited[_x][_y])
				return;
		}
		printf("peak %d %d\n", x, y);
		counter++;
	}
	visited[x][y] = 1;
	for(int i = 0; i < 8; ++i) {
		int _x = x + r[i];
		int _y = y + c[i];
		visited[_x][_y] = 1;
	}
}

void floodfill(int x, int y) {
	//printf("%d %d\n", x, y);
	visited[x][y] = 1;
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j) {
			int _x = x + r[i];
			int _y = y + c[i];
			
			if(_x < 0 || _y < 0 || _x > N || _y > M)
				continue;
			if(mat[_x][_y] > mat[x][y])
				continue;
			if(!visited[_x][_y])
				floodfill(_x, _y);
		}
}
		
int main() {
	//freopen("in", "r", stdin);
	
	while(scanf("%d %d", &N, &M) == 2) {
		memset(visited, 0, sizeof visited);
		counter = 0;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				scanf("%d", &mat[i][j]);
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				if(!visited[i][j]) {
					//dfs(i, j);
					floodfill(i, j);
					counter++;
				}
		printf("%d\n", counter);
	}
	return 0;
}
