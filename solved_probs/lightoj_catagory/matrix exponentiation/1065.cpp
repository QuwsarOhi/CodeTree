// LightOJ
// 1065 - Number Sequence
// Matrix Exponentiation, Matrix Chain Multiplication

// Some Reference (Bangla): http://www.progkriya.org/gyan/matrix-expo.html?fref=gc 
//				English : http://zobayer.blogspot.com/2010/11/matrix-exponentiation.html

// The Formula is
//					| 1  1 |     | f(n-1) |   | f(n-1)+f(n) |   |  f(n)  |
//					| 1  0 |  X  | f(n-2) | = | f(n-1)      | = | f(n-1) |
// The base idea
//							
//				| b |   | 1  1 |^(N-1)			// N-1 is because the series starts from 0
//				| a | X | 1  0 |				// and we already have 0th and 1st value when N = 1


#include <bits/stdc++.h>
#define MAXN 2
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

matrix Base, x;
int a, b, n, m;

matrix mul(matrix a, matrix b, int p, int q, int r) {		// O(n^3)
	matrix ans;
	for(int i = 0; i < p; ++i) {
		for(int j = 0; j < r; ++j) {
			ans.mat[i][j] = 0;
			for(int k = 0; k < q; ++k)
				ans.mat[i][j] = (ans.mat[i][j]%m + (a.mat[i][k]%m * b.mat[k][j]%m)%m)%m;
		}
	}
	return ans;
}

matrix matPow(matrix base, int p) {
	if(p == 1)
		return base;
	if(p & 1)
		return mul(base, matPow(base, p-1), 2, 2, 2);
	matrix tmp = matPow(base, p/2);
	return mul(tmp, tmp, 2, 2, 2);
}


int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d%d%d", &a, &b, &n, &m);
		printf("Case %d: ", Case);
		memset(Base.mat, 0, sizeof(Base.mat));
		m = pow(10, m);
		if(n == 0)
			printf("%d\n", a%m);
		else if(n == 1)
			printf("%d\n", b%m);
		else  {
			Base.mat[0][0] = b%m;
			Base.mat[1][0] = a%m;

			x.mat[0][0] = x.mat[0][1] = x.mat[1][0] = 1;
			x.mat[1][1] = 0;
			x = matPow(x, n-1);
			x = mul(x, Base, 2, 2, 2);
			printf("%d\n", x.mat[0][0]);
		}
	}
	return 0;
}

