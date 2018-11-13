// LightOJ
// 1244 - Tiles
// Matrix Expo

#include <bits/stdc++.h>
using namespace std;
#define MAX                 15
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define MOD                 10007
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

/* Recursive Function: F(n) = 2*F(n-1) + F(n-3) */

struct matrix {
    ull mat[3][3];
    matrix() {memset(mat, 0, sizeof mat);}
};

matrix mul(matrix a, matrix b, int p, int q, int r) {
    matrix ans;
    for(int i = 0; i < p; ++i)
        for(int j = 0; j < r; ++j)
            for(int k = 0; k < q; ++k)
                ans.mat[i][j] = (ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j])%MOD)%MOD;
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
    ll n;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld", &n);
        printf("Case %d: ", Case);

        if(n <= 3) {
            if(n == 3)
                printf("5\n");
            else if(n == 2)
                printf("2\n");
            else
                printf("1\n");
            continue;
        }

        matrix base;
        base.mat[0][0] = 2, base.mat[0][2] = 1;
        base.mat[1][0] = 1;
        base.mat[2][1] = 1;

        base = matPow(base, n-3, 3);

        printf("%llu\n", ((base.mat[0][0]*5)%MOD+ (base.mat[0][1]*2)%MOD + base.mat[0][2])%MOD);
    }
    return 0;
}