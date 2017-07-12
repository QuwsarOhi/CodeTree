// Sparse Table 
// 2D RMQ

#include <bits/stdc++.h>
#define MAX 510
using namespace std;


int table[MAX][MAX][10][10], val[MAX][MAX], n;


void buildSparseTableRMQ() {
	for(int i = 0; (1 << i) <= n; ++i)
		for(int j = 0; (1 << j) <= n; ++j)
			for(int x = 0; x + (1 << i) - 1 < n; ++x)
				for(int y = 0; y + (1 << j) - 1 < n; ++y) {
					if(i == 0 && j == 0)
						table[x][y][i][j] = val[x][y];
					else if(i == 0)
						table[x][y][i][j] = max(table[x][y][i][j-1], table[x][y + (1 << (j-1))][i][j-1]);
					else if(j == 0)
						table[x][y][i][j] = max(table[x][y][i-1][j], table[x + (1 << (i-1))][y][i-1][j]);
					else {
						table[x][y][i][j] = max(max(table[x][y][i-1][j-1], table[x + (1 << (i-1))][y][i-1][j-1]), 
							max(table[x][y + (1 << (j-1))][i-1][j-1], table[x + (1 << (i-1))][y + (1 << (j-1))][i-1][j-1]));
					}
				}
}

int sparseQueryRMQ(int x1, int y1, int x2, int y2) {
		int k = log2(x2-x1+1), l = log2(y2-y1+1);
		return max(max(table[x1][y1][k][l], table[x2 - (1 << k) + 1][y1][k][l]), 
			max(table[x1][y2 - (1 << l) + 1][k][l], table[x2 - (1 << k) + 1][y2 - (1 << l) + 1][k][l]));
}


int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int q, t, I, J, S;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &q);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &val[i][j]);
		printf("Case %d:\n", Case);
		buildSparseTableRMQ();
		while(q--) {
			scanf("%d%d%d", &I, &J, &S);
			--I, --J;
			int t = sparseQueryRMQ(I, J, I+S-1, J+S-1);
			printf("%d\n", t);
		}
	}
	return 0;
}
