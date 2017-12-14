// LightOJ
// 1036 - A Refining Company

#include <bits/stdc++.h>
using namespace std;
#define MAX                 510
#define EPS                 1e-9
#define INF                 1e9+10
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

int R[MAX][MAX], U[MAX][MAX], RSum[MAX][MAX], USum[MAX][MAX], dp[MAX][MAX];

void calSum(int n, int m) {
    memset(RSum, 0, sizeof RSum);
    memset(USum, 0, sizeof USum);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            RSum[i][j] = R[i][j] + RSum[i-1][j];
            USum[i][j] = U[i][j] + USum[i][j-1];
        }
}

int recur(int x, int y) {
    if(x < 0 || y < 0)
        return 0;
    
    if(dp[x][y] != -1)
        return dp[x][y];
    
    int Max = 0;
    Max = max(Max, max(recur(x-1, y-1), recur(x, y-1))+RSum[x][y]);
    Max = max(Max, max(recur(x-1, y-1), recur(x-1, y))+USum[x][y]);
    
    return dp[x][y] = Max;
}

int main() {
    //fileRead("in");
    int t, n, m;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d %d", &n, &m);
        pf("Case %d: ", Case);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                sf("%d", &U[i][j]);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                sf("%d", &R[i][j]);
        
        calSum(n, m);
        memset(dp, -1, sizeof dp);
        pf("%d\n", recur(n-1, m-1));
    }
    
    return 0;
}
