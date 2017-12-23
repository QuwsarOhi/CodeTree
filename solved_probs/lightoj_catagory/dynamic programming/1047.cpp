// LightOJ
// 1047 - Neighbor House

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
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

int cost[30][5], dp[30][5], n;

int recur(int pos, int pst) {
    if(pos == n)
        return 0;
    
    if(pst != -1 && dp[pos][pst] != -1)
        return dp[pos][pst];
    
    int ret = INF;
    for(int i = 0; i < 3; ++i) {
        if(i == pst)
            continue;
        ret = min(ret, recur(pos+1, i)+cost[pos][i]);
    }
    
    return dp[pos][pst] = ret;
}


int main() {
    //fileRead("in");
    
    int t;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d", &n);
        pf("Case %d: ", Case);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 3; ++j)
                sf("%d", &cost[i][j]);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 3; ++j)
                dp[i][j] = -1;
        
        pf("%d\n", recur(0, -1));
    }
    
    return 0;
}
