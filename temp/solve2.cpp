// LightOJ
// 1070 - Algebraic Problem
// Matrix Expo

#include <bits/stdc++.h>
using namespace std;
#define MAX                 15
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define MOD					1000000007
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

/*
How the Eqn works...
a^2 + b^2 = (a+b)^2 - 2ab
a^3 + b^3 = (a^2+b^2)*(a+b) - ab*(a+b)
.
.
a^n + b^n = (a^(n-1)+b^(n-1))*(a+b) - ab*(a^(n-2)+b^(n-2))
*/


struct matrix {
	ull mat[3][3];
	matrix() {memset(mat, 0, sizeof mat);}
};

matrix mul(matrix a, matrix b, int p, int q, int r) {
	matrix ans;
	for(int i = 0; i < p; ++i)
		for(int j = 0; j < r; ++j)
			for(int k = 0; k < q; ++k)
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
	return ans;
}

matrix matPow(matrix base, ll p, int s) {
	if(p == 1) return base;
	if(p&1) return mul(base, matPow(base, p-1, s), s, s, s);
	matrix tmp = matPow(base, p/2, s);
	return mul(tmp, tmp, s, s, s); 
}

int main() {
	int t;
	ull AplusB, AmulB, n;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%llu%llu%llu", &AplusB, &AmulB, &n);
		printf("Case %d: ", Case);
		ull AsqBsq = ((AplusB*AplusB) - (2ULL*AmulB));

		if(n <= 2) {
			if(n == 0)
				printf("2\n");
			else if(n == 1)
				printf("%llu\n", AplusB);
			else
				printf("%llu\n", AsqBsq);
			continue;
		}

		matrix base;
		base.mat[0][0] = AplusB, base.mat[0][1] = -AmulB;
		base.mat[1][0] = 1;

		base = matPow(base, n-2, 2);

		/*cerr << AsqBsq << endl;
		for(int i = 0; i < 2; ++i, cerr << endl)
			for(int j = 0; j < 2; ++j)
				cerr << base.mat[i][j] << " ";*/

		printf("%llu\n", base.mat[0][0]*AsqBsq+ base.mat[0][1]*AplusB);
	}
	return 0;
}