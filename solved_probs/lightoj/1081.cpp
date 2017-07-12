// LightOJ
// 1081 - Square Queries
// RMQ (Sparse Table)
// Using 4D array for sparse table causes MLE, used 3D array instead, this is possible as the sub matrix moves S on both x and y axis

#include <bits/stdc++.h>
#define MAX 510
using namespace std;


int table[MAX][MAX][10], val[MAX][MAX], n;


void buildSparseTableRMQ() {
	for(int i = 0; (1 << i) <= n; ++i) 
		for(int x = 0; x + (1 << i) - 1 < n; ++x)
			for(int y = 0; y + (1 << i) - 1 < n; ++y) {
				if(i == 0)
					table[x][y][i] = val[x][y];
				else {
					table[x][y][i] = max(max(table[x][y][i-1], table[x + (1 << (i-1))][y][i-1]), 
						max(table[x][y + (1 << (i-1))][i-1], table[x + (1 << (i-1))][y + (1 << (i-1))][i-1]));
				}
			}
}

int sparseQueryRMQ(int x1, int y1, int x2, int y2, int s) {
		int l = log2(s);
		return max(max(table[x1][y1][l], table[x2 - (1 << l) + 1][y1][l]), 
			max(table[x1][y2 - (1 << l) + 1][l], table[x2 - (1 << l) + 1][y2 - (1 << l) + 1][l]));
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
			// X1 = I
			// X2 = I+S-1
			// Y1 = J
			// Y2 = J+S-1
			--I, --J;
			int t = sparseQueryRMQ(I, J, I+S-1, J+S-1, S);
			printf("%d\n", t);
		}
	}
	return 0;
}
