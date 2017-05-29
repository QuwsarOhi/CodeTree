#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

int r[] = {-1, -1, -1, 0, 0, 1, 1, 1}, c[] = {-1, 0, 1, -1, 1, -1, 0, 1}, mat[710][710], N, M;
bool visited[710][710];
long long counter;

void floodfill(int x, int y) {
	//printf("%d %d\n", x, y);
	visited[x][y] = 1;
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j) {
			int _x = x + r[i];
			int _y = y + c[i];
			
			if(_x < 0 || _y < 0 || _x >= N || _y > M)
				continue;
			if(mat[_x][_y] > mat[x][y])
				continue;
			if(!visited[_x][_y])
				floodfill(_x, _y);
		}
}

bool dfs2(int x, int y, int val) {
	visited[x][y] = 1;
	bool isPeak = 1;
	for(int i = 0; i < 8; ++i) {
		int _x = x + r[i];
		int _y = y + c[i];
		
		if(_x >=  N || _x < 0 || _y >= M || _y < 0)
			continue;
		if(mat[_x][_y] > val) {
			isPeak = 0;
			printf("not Peak on %d %d\n", _x, _y);
			return 0;
		}
		if(!visited[_x][_y] && mat[_x][_y] == mat[x][y])
			isPeak = isPeak && dfs2(_x, _y, val);
	}
	return isPeak;
}
		
int main() {
	freopen("in", "r", stdin);
	
	while(2==scanf("%d %d", &N, &M)) {
		memset(visited, 0, sizeof visited);
		counter = 0;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				scanf("%d", &mat[i][j]);
		bool found = 0;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j) {
				if(mat[i][j] != 0)
					found = 1;
				printf("ON %d %d\n", i, j);
				if(!visited[i][j]) {
					if(dfs2(i, j, mat[i][j])) {
						floodfill(i, j);
						counter++;
						printf("peak %d %d\n", i, j);
					}
				}
			}
		if(counter == 0 && found)
			counter++;
		printf("%lld\n", counter);
	}	
	return 0;
}
