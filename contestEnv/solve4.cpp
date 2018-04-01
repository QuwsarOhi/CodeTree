#include <bits/stdc++.h>
using namespace std;
#define MAX                 110000
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
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }


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

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}, minCst, n, m;
char g[110][110];
bool vis[110][110];

void dfs(int x, int y, int cst) {
    vis[x][y] = 1;
    
    if(x == 0 or y == 0 or x == n-1 or y == m-1) {
        minCst = min(cst, minCst);
        return;
    }
    
    for(int i = 0; i < 4; ++i) {
        int X = x+dx[i];
        int Y = y+dy[i];
        
        if(minCst <= cst)
            return;
        
        if(X < 0 or Y < 0 or X >= n or Y >= m or vis[X][Y] or g[X][Y] == '*')
            continue;
        
        if(g[X][Y] == '#')
            dfs(X, Y, cst+1);
        else
            dfs(X, Y, cst);
    }
}


int main() {
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);
        int p, q;
        memset(vis, 0, sizeof vis);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                sf(" %c", &g[i][j]);
                if(g[i][j] == '$')
                    p = i, q = j;
            }
        
        minCst = 10000000;
        dfs(p, q, 0);
        
        pf("Case %d: ", Case);
        if(minCst == 10000000)
            pf("Impossible\n");
        else
            pf("%d\n", minCst);
    }
    
    return 0;
}
