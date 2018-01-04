// LightOJ
// 1057 - Collecting Gold
// http://lightoj.com/volume_showproblem.php?problem=1057

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
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


char G[50][50];
vii v;
int dp[18][(1<<16)+100];


int dist(int a, int b) {
    return max(abs(v[a].fi-v[b].fi), abs(v[a].se-v[b].se));
}


int TSP(int u, int mask) {
    if(mask == (1<<(SIZE(v)))-1)
        return dist(u, 0);
    
    if(dp[u][mask] != -1)
        return dp[u][mask];
    
    int ans = INF;
    for(int i = 0; i < SIZE(v); ++i)
        if(!isOn(mask, i))
            ans = min(TSP(i, mask|(1<<i))+dist(i, u), ans);
        
    return dp[u][mask] = ans;
}


int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, n, m;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d%d", &n, &m);
        v.clear();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                sf(" %c", &G[i][j]);
                if(G[i][j] == 'x')
                    v.pb(mp(i, j));
            }
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(G[i][j] == 'g')
                    v.pb(mp(i, j));
        
        memset(dp, -1, sizeof dp);
        pf("Case %d: %d\n", Case, TSP(0, 1));
    }
    
    return 0;
}
