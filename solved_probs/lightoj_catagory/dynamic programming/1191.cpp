// LightOJ
// 1191 - Bar Codes
// Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
#define MAX                 6
#define EPS                 1e-7
#define INF                 0x3f3f3f3f
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
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

int n, k, m;
ll dp[52][52][52];

ll recur(int pos, int bars) {
    if(pos <= 0 || bars <= 0) {
        if(pos == 0 && bars == 0)
            return 1;
        return 0;
    }

    ll &ret = dp[pos][bars][m];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 1; i <= m; ++i)
        ret += recur(pos-i, bars-1);
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d", &n, &k, &m);
        printf("Case %d: %lld\n", Case, recur(n, k));
    }
    return 0;
}