// LightOJ
// 1071 - Baker Vai
// NOT SAVED

#include <bits/stdc++.h>
using namespace std;
#define MAX                 13333333
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

int dp[101][101][101][3];
int v[101][101];
int n, m;

// p2 will cover the upper right horizontal of the grid
// p1 will cover the lower left horizontal of the grid

int recur(int x, int y1, int y2, int nxtDir) {
    if(x == n-1 && y1 == m-2 && y2 == m-1)
        return 0;
    
    int &ret = dp[x][y1][y2][nxtDir];
    if(ret != -1) return ret;
    
    if(nxtDir == 0) {
        if(y2+1 < m) 
            ret = max(ret, recur(x, y1, y2+1, 0)+v[x][y2+1]);
        ret = max(ret, recur(x, y1, y2, 2));
    }
    else if(nxtDir == 1) {
        if(y1+1 < y2)
            ret = max(ret, recur(x, y1+1, y2, 1)+v[x][y1+1]);
        if(y1 < y2)
            ret = max(ret, recur(x, y1, y2, 0));
    }
    else {
        if(x+1 < n)
            ret = max(ret, recur(x+1, y1, y2, 1)+v[x+1][y1]+v[x+1][y2]);
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                scanf("%d", &v[i][j]);

        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", Case, recur(0, 0, 0, 0)+v[0][0]);
    }
    return 0;
}
