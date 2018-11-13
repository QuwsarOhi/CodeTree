// LightOJ
// 1131 - Just Two Functions
// Matrix Expo

#include <bits/stdc++.h>
using namespace std;
#define MAX                 6
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

/* How it works :

| a1 b1 0  0  0  0  c1 |		| f(n)   |		| f(n+1) |
| 1  0  0  0  0  0  0  |		| f(n-1) |		| f(n)   |
| 0  1  0  0  0  0  0  |		| f(n-2) |		| f(n-1) |
| 0  0  c2 0  0  a2 b2 |	X	| g(n)   |	=	| g(n+1) |
| 0  0  0  0  1  0  0  |		| g(n-1) |		| g(n)   |
| 0  0  0  0  0  1  0  |		| g(n-2) |		| g(n-1) |

*/  

ll MOD;

struct matrix {
    matrix() { memset(mat, 0, sizeof(mat)); }
    ll mat[MAX][MAX];
};
matrix mul(matrix a, matrix b, int p, int q, int r) {		// O(n^3) :: r1, c1, c2  [c1 = r2]
    matrix ans;
    for(int i = 0; i < p; ++i)
        for(int j = 0; j < r; ++j) {
            ans.mat[i][j] = 0;
            for(int k = 0; k < q; ++k)
                ans.mat[i][j] = (ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j])%MOD)%MOD;
        }
    return ans;
}
matrix matPow(matrix base, ll p, int s = 6) {               // O(logN), s : size of square matrix
    if(p == 1) return base;
    if(p & 1)  return mul(base, matPow(base, p-1, s), s, s, s);
    matrix tmp = matPow(base, p/2, s);
    return mul(tmp, tmp, s, s, s);
}

ll a[3], b[3], f[3], g[3];

int main() {
	//fileRead("in");
	//fileWrite("out");

	int t, q;
	ll p;
	sf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		for(int i = 0; i < 3; ++i) sf("%lld", &a[i]);
		for(int i = 0; i < 3; ++i) sf("%lld", &b[i]);
		for(int i = 0; i < 3; ++i) sf("%lld", &f[i]);
		for(int i = 0; i < 3; ++i) sf("%lld", &g[i]);
		sf("%lld%d", &MOD, &q);

		for(int i = 0; i < 3; ++i) a[i] %= MOD;
		for(int i = 0; i < 3; ++i) b[i] %= MOD;
		for(int i = 0; i < 3; ++i) f[i] %= MOD;
		for(int i = 0; i < 3; ++i) g[i] %= MOD;

		matrix base;
		base.mat[0][0] = a[0], base.mat[0][1] = a[1], base.mat[0][5] = a[2];
		base.mat[1][0] = 1;
		base.mat[2][1] = 1;
		base.mat[3][2] = b[2], base.mat[3][3] = b[0], base.mat[3][4] = b[1];
		base.mat[4][3] = 1;
		base.mat[5][4] = 1;

		pf("Case %d:\n", Case);
		while(q--) {
			sf("%lld", &p);
			
			if(p < 3) {
				pf("%lld %lld\n", f[p]%MOD, g[p]%MOD);
				continue;
			}

			matrix ans = matPow(base, p-2);
			ll ff = 0, gg = 0;

			ff = ((ans.mat[0][0] * f[2])%MOD + (ans.mat[0][1] * f[1])%MOD + (ans.mat[0][2] * f[0])%MOD)%MOD;
			ff += ((ans.mat[0][3] * g[2])%MOD + (ans.mat[0][4] * g[1])%MOD + (ans.mat[0][5] * g[0])%MOD)%MOD;
			ff %= MOD;

			gg = ((ans.mat[3][0] * f[2])%MOD + (ans.mat[3][1] * f[1])%MOD + (ans.mat[3][2] * f[0])%MOD)%MOD;
			gg += ((ans.mat[3][3] * g[2])%MOD + (ans.mat[3][4] * g[1])%MOD + (ans.mat[3][5] * g[0])%MOD)%MOD;
			gg %= MOD;

			pf("%lld %lld\n", ff, gg);
		}
	}
	return 0;
}