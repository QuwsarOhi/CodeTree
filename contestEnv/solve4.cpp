#include <bits/stdc++.h>
using namespace std;
#define MAX                 400100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
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

ll powerMOD(ll x, ll y) {                   // Can find modular inverse by a^(MOD-2),  a and MOD must be co-prime
    ll res = 1;
    x %= MOD;
    while(y > 0) {
        if(y&1) res = (res*x)%MOD;          // If y is odd, multiply x with result
        y = y >> 1, x = (x * x)%MOD;
    }
    return res%MOD;
}

/*
ll fa[2*MAX+100], invfa[2*MAX+100];
void calFactorial(int n) {
    fa[0] = 1;
    invfa[0] = powerMOD(1, MOD-2);
    for(int i = 1; i <= n; ++i) {
        fa[i] = (fa[i-1] * i)%MOD;
        invfa[i] = powerMOD(fa[i], MOD-2);
}}*/

ll fa[MAX], fainv[MAX];                     // fa must be in global
ll C(ll n, ll r) {                          // Usable if MOD value is present
    if(fa[0] == 0) {                        // Auto initialize
        fa[0] = 1, fainv[0] = powerMOD(1, MOD-2);
        for(int i = 1; i < MAX; ++i) {
            fa[i] = (fa[i-1]*i) % MOD;      // Constant MOD
            fainv[i] = powerMOD(fa[i], MOD-2);
        }
        //cerr << "DONE\n";
    }
    //cout << "C " << n << " " << r << endl;
    if(n < 0 || r < 0 || n-r < 0) return 0;     // Exceptional Cases
    return ((fa[n] * fainv[r])%MOD * fainv[n-r])%MOD;
}

ll CountWay(int x1, int y1, int x2, int y2) {           // Returns number of ways we can go from (x1, y1) to (x2, y2)
    return C(x2-x1+y2-y1, y2-y1);                       // if we can go only right and down of a 2D grid
}

vii v;
ll dp[MAX];

ll CountNumberofWays(int r, int c, int n) {         // rows, columns, number of unaccessable points
    v[n] = {r, c};                                  // also add the last point as unaccessable point, to find how many
    sort(v.begin(), v.end());                       // ways we can come to this point, which is the answer
    for(int i = 0; i <= n; ++i) {
        dp[i] = CountWay(1, 1, v[i].first, v[i].second);               // Number of ways we can come from starting square
        for(int j = 0; j < i; ++j)
            if(v[j].first <= v[i].first and v[j].second <= v[i].second)
                dp[i] = (dp[i] - (dp[j] * CountWay(v[j].first, v[j].second, v[i].first, v[i].second))%MOD + MOD)%MOD;
    }
    return dp[n];
}

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    v.resize(n+1);
    for(int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    
    cout << CountNumberofWays(r, c, n) << endl;
    return 0;
}
