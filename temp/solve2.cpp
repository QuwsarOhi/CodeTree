#include <bits/stdc++.h>
#define MAXN 20
using namespace std;

struct matrix {
	int mat[MAXN][MAXN];
};

/*
  p-> 0 1  q-> 0 1
		     
0 :  |1 2|^   |1 2|^   |7  12|
1 :  |3 4|| X |3 4|| = |15 22|
2 :  |5 6|q		   r   |23 34|

*/

matrix mul(matrix a, matrix b) {		// O(n^3)
	matrix ans;
	for(int i = 0; i < MAXN; ++i) {
		for(int j = 0; j < MAXN; ++j) {
			ans.mat[i][j] = 0;
			for(int k = 0; k < MAXN; ++k) {
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
			}
		}
	}
	return ans;
}

matrix matPow(matrix base, int p) {
	matrix ans;
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j)
			ans.mat[i][j] = (i == j);		// Identity Matrix
	
	while(p) {
		if(p & 1) ans = mul(ans, base);
		base = mul(base, base);
		p >>= 1;
	}
	return ans;
}


int main() {
	
	return 0;
}
