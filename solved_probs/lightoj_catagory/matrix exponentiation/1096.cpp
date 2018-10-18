// LightOJ
// 1096 - nth Term

#include <bits/stdc++.h>
#define MAXN 4
#define MOD 10007
using namespace std;

struct matrix {
	matrix() { memset(mat, 0, sizeof(mat)); }
	long long mat[MAXN][MAXN];
};

matrix mul(matrix a, matrix b, int p, int q, int r) {		// O(n^3) :: r1, c1, c2  [c1 = r2]
	matrix ans;
	for(int i = 0; i < p; ++i)
		for(int j = 0; j < r; ++j) {
			ans.mat[i][j] = 0;
			for(int k = 0; k < q; ++k)
				ans.mat[i][j] = (ans.mat[i][j]%MOD + (a.mat[i][k]%MOD * b.mat[k][j]%MOD)%MOD)%MOD;
		}
	return ans;
}

matrix matPow(matrix base, int p, int s) {               // O(logN), s : size of square matrix
	if(p == 1) return base;
	if(p & 1)  return mul(base, matPow(base, p-1, s), s, s, s);
	matrix tmp = matPow(base, p/2, s);
	return mul(tmp, tmp, s, s, s);
}

int a, b, c;

// Legend : ? represents unknown value which depends on a, b and c
// 
// 0, 1, 2, 3, 4, 5, 6
// 0, 0, 0, ?, ?, ?, ?
//
//     Count How Many Times C occurs!
//       ^
//       |
// a 0 b 1   ? F(3)      F(4)
// 1 0 0 0   0 F(2)      F(3)
// 0 1 0 0   0 F(1)  =   F(2)
// 0 0 0 1   0 F(0)      F(0)

int F(int n) {
    if(n <= 2)
        return 0;
    return ((a*F(n-1))%MOD + (b*F(n-3))%MOD + c)%MOD;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, n;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d%d", &n, &a, &b, &c);
        a %= MOD, b %= MOD, c %= MOD;
        printf("Case %d: ", Case);
        
        if(n <= 3) {
            if(n == 3)  printf("%d\n", c);
            else        printf("0\n");
            continue;
        }
        
        matrix B;
        B.mat[0][0] = a, B.mat[0][2] = b, B.mat[0][3] = 1, B.mat[1][0] = 1, B.mat[2][1] = 1, B.mat[3][3] = 1;
        matrix A;
        
        B = matPow(B, n-3, 4);
        int ans = ((B.mat[0][0]*F(3))%MOD + (B.mat[0][3]*c)%MOD)%MOD;           // As F(2) = F(1) = 0
        printf("%d\n", ans);
    }
    return 0;
}
