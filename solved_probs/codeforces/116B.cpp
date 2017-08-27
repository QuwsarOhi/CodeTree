// CodeForces
// B. Little Pigs and Wolves
// http://codeforces.com/problemset/problem/116/B
// Graph, Greedy

#include <bits/stdc++.h>
using namespace std;

int r[4] = {-1, 0, 0, 1}, c[4] = {0, -1, 1, 0}, cnt = 0, n, m;
char g[15][15];
bool visited[15][15];

void fill(int x, int y) {
	for(int i = 0; i < 4; ++i) {
		int _x = x + r[i];
		int _y = y + c[i];
		if(_x >= 0 && x < n && _y >= 0 && y < m) {
			if(g[_x][_y] == 'W' && !visited[_x][_y]) {
				visited[_x][_y] = 1;
				++cnt;
				return;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	memset(visited, 0, sizeof visited);
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf(" %c", &g[i][j]);
		}
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(g[i][j] == 'P')
				fill(i, j);
		}
	}
	
	printf("%d\n", cnt);
	return 0;
}

