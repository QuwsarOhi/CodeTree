// Sparse Table
// 1D RMQ

#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int table[MAX][10], val[MAX];								// table[MAX][log2(MAX)]

void buildSparseTableRMQ(int n) {							//  O(n Log n)
	for(int i = 0; i < n; ++i)
		table[i][0] = i;

	for(int j = 1; (1 << j) <= n; ++j)						// 2^j
		for(int i = 0; i + (1 << j) - 1< n; ++i) {			// For every node
			if(val[table[i][j-1]] < val[table[i + (1 << (j-1))][j-1]])
				table[i][j] = table[i][j-1];
			else
				table[i][j] = table[i + (1 << (j-1))][j-1];
		}
}

int sparseQueryRMQ(int l, int r) {							// O(1)
	int k = log2(r - l + 1); 								// log(2);
	return min(val[table[l][k]], val[table[r - (1 << k) + 1][k]]);
}

int main() {
	int n = 10;
	//val[] = {1, 2, 7, 4, 12, 9, 3, 23, 1, 2};
	for(int i = 0; i < n; ++i)
		printf("%d ", val[i]);
	printf("\n");
	buildSparseTableRMQ(n);
	printf("%d\n", sparseQueryRMQ(2, 5));
	return 0;
} 
	
