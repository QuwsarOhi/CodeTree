// LightOJ
// 1065 - Number Sequence

// Not ADDED YET!!!!!!!!!!!1
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

void matprint(matrix a, int x, int y) {
	for(int i = 0; i < x; ++i) {
		for(int j = 0; j < y; ++j)
			printf("%d ", a.mat[i][j]);
		printf("\n");
	}
}

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
			//printf("m : %d\n", m);
			Base.mat[0][0] = b%m;
			Base.mat[1][0] = a%m;
			
			//matprint(Base, 2, 2);
			//printf("------------------\n");
			x.mat[0][0] = x.mat[0][1] = x.mat[1][0] = 1;
			x.mat[1][1] = 0;
			//matprint(x, 2, 2);
			//printf("------------------\n");
			x = matPow(x, n-1);
			//matprint(x, 2, 2);
			//printf("------------------\n");
			x = mul(x, Base, 2, 2, 2);
			//matprint(x, 2, 2);
			//printf("------------------\n");
			printf("%d\n", x.mat[0][0]);
		}
	}
	return 0;
}

