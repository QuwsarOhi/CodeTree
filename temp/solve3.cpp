// UVa
// 4857 - Halloween Costumes
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=383&page=show_problem&problem=2858

#include <bits/stdc++.h>
using namespace std;
#define MAX                 102
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define x                  first
#define y                  second
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

vi p;
int dp[MAX][MAX], c[MAX];

int recur(int l, int r) {
    if(l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int ret = min(recur(l+1, r), recur(l, r-1))+1;
    for(int i = l+1; i <= r; ++i)
        if(p[i] == p[l])
            ret = min(ret, recur(l+1, i)+recur(i+1, r));
    return dp[l][r] = ret;
}

int main() {
    int n, m, t;
    sf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
            sf("%d%d", &n, &m);

            for(int i = 0; i < n; ++i)
                sf("%d", &c[i]);

            p.clear();
            p.pb(c[0]);
            for(int i = 1; i < n; ++i)
                if(c[i] != c[i-1])
                    p.pb(c[i]);

            memset(dp, -1, sizeof dp);
            pf("Case %d: %d\n", Case, recur(0, SIZE(p)-1));
    }
    return 0;
}
