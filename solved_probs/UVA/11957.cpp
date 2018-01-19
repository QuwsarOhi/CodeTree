// UVa
// 11957 - Checkers

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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


int dr[] = {-1, -1}, dc[] = {1, -1}, n;
char g[105][105];
ll dp[105][105];

ll dfs(int r, int c) {
    if(r == 0)
        return 1;
    if(dp[r][c] != -1)
        return dp[r][c];
    
    ll ans = 0;
    for(int i = 0; i < 2; ++i) {
        int _r = r+dr[i];
        int _c = c+dc[i];
        
        if(_r < 0 || _c < 0 || _r >= n || _c >= n)
            continue;
        
        if(g[_r][_c] == 'B')        // if Black occurs
            _r += dr[i], _c += dc[i];
        
        if(_r < 0 || _c < 0 || _r >= n || _c >= n)
            continue;
        
        if(g[_r][_c] == 'B')        // still another black
            continue;
        
        //pf("%d %d - > %d %d\n", r, c, _r, _c);
        ans += dfs(_r, _c);
        ans %= MOD;
    }
    
    return dp[r][c] = (ans%MOD);
}
        
        
        
int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, pX, pY;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d", &n);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                sf(" %c", &g[i][j]);
                if(g[i][j] == 'W')
                    pX = i, pY = j;
            }
        
        memset(dp, -1, sizeof dp);
        pf("Case %d: %lld\n", Case, dfs(pX, pY));
    }
    
    return 0;
}
