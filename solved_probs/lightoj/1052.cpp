// LightOJ
// 1052 - String Growth
// Matrix Exponentiation, Matirx Chain Multiplication

// If the problem is observed carefully it can be seen that ab -> bba -> babab
// f(n-1) + f(n-2) = f(n)   fibonacci series

// This section is taken from pin3da

// a0 : number of a's,  b0 : number of b's

// Let's write the length function as a matrix multiplication, if you are not familiar with this concept, read this first:
// |0 1| x |a0| = |a1| = |b0     |
// |1 1|   |b0|   |b1|   |a0 + b0|

// In this form, the Nth state of the function can be computed as:
// |0 1| ^ N x |a0|
// |1 1|       |b0|

// We know that:
// |0 1| ^ N x |a0| = |a b| x |a0| = |bn |
// |1 1|       |b0|   |c d|   |b0|   |X  |
// and
//
// |0 1| ^ M x |a0| = |ap bp| x |a0| = |bn |
// |1 1|       |b0|   |cp dp|   |b0|   |Y  |
// At this moment we have a system of two equations with two unkowns:
//
// X = c * a0 + d * b0
// Y = cp * a0 + dp * b0
// We can find a0 and b0 using the Cramer's rule and finally compute the answer as:

// |0 1| ^ K x |a0|
// |1 1|       |b0|

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
		long long a0, b0, Cn, Dn, Cm, Dm;
		Cn = p.mat[1][0], Dn = p.mat[1][1];
		Cm = q.mat[1][0], Dm = q.mat[1][1];
		
		if(Cn * Dm - Dn * Cm == 0) {
			printf("Impossible\n");
			continue;
		}
		
		a0 = (x*Dm - Dn*y)/(Cn*Dm - Dn*Cm);
		b0 = (Cn*y - x*Cm)/(Cn*Dm - Dn*Cm);
		if(a0 < 0 || b0 < 0 || (x*Dm - Dn*y)%(Cn*Dm - Dn*Cm) || (Cn*y - x*Cm)%(Cn*Dm - Dn*Cm)) {
			printf("Impossible\n");
			continue;
		}
		
		s.mat[0][0] = a0, s.mat[1][0] = b0;
		r.mat[0][1] = r.mat[1][0] = r.mat[1][1] = 1;
		r = matPow(r, k);
		s = mul(r, s, 2, 2, 2);
		printf("%lld\n", s.mat[1][0]);
	}
	return 0;
}


