// LightOJ
// 1052 - String Growth

#include <bits/stdc++.h>
#define MAXN 2
#define MOD 1000000007
using namespace std;

struct matrix {
	matrix() {
		memset(mat, 0, sizeof(mat));
	}
	long long mat[MAXN][MAXN];
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
			printf("%lld ", a.mat[i][j]);
		printf("\n");
	}
}

matrix mul(matrix a, matrix b, int p, int q, int r) {		// O(n^3)
	matrix ans;
	for(int i = 0; i < p; ++i) {
		for(int j = 0; j < r; ++j) {
			ans.mat[i][j] = 0;
			for(int k = 0; k < q; ++k)
				ans.mat[i][j] = (ans.mat[i][j]%MOD + (a.mat[i][k]%MOD * b.mat[k][j]%MOD)%MOD)%MOD;
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
	long long n, x, m, y, k;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%lld %lld %lld %lld %lld", &n, &x, &m, &y, &k);
		printf("Case %d: ", Case);
		matrix p, q, r, s;
		p.mat[0][1] = p.mat[1][0] = p.mat[1][1] = q.mat[0][1] = q.mat[1][0] = q.mat[1][1] = 1;
		p = matPow(p, n);
		q = matPow(q, m);
		//printf("p-------------------\n");
		//matprint(p, 2, 2);
		//printf("q-------------------\n");
		//matprint(q, 2, 2);		
		long long a0, b0, Cn, Dn, Cm, Dm;
		Cn = p.mat[1][0], Dn = p.mat[1][1];
		Cm = q.mat[1][0], Dm = q.mat[1][1];
		
		if(Cn * Dm - Dn * Cm == 0) {
			printf("Impossible\n");
			continue;
		}
		
		a0 = (x*Dm - Dn*y)/(Cn*Dm - Dn*Cm);
		b0 = (Cn*y - x*Cm)/(Cn*Dm - Dn*Cm);
		//printf("a0 : %lld, b0 : %lld\n", a0, b0);
		if(a0 < 0 || b0 < 0 || (x*Dm - Dn*y)%(Cn*Dm - Dn*Cm) || (Cn*y - x*Cm)%(Cn*Dm - Dn*Cm)) {
			printf("Impossible\n");
			continue;
		}
		
		s.mat[0][0] = a0, s.mat[1][0] = b0;
		r.mat[0][1] = r.mat[1][0] = r.mat[1][1] = 1;
		r = matPow(r, k);
		//printf("r-------------------\n");
		//matprint(r, 2, 2);	
		//printf("s-------------------\n");
		//matprint(s, 2, 2);	
		s = mul(r, s, 2, 2, 2);
		//printf("new-s-------------------\n");
		//matprint(s, 2, 2);
		printf("%lld\n", s.mat[1][0]);
	}
	return 0;
}


