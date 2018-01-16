// UVa
// 10285 - Longest Run on a Snowboard
// Longest Path on DAG

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000003
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

vector<int>G[10010];
int n, m, mat[105][105], dis[10010];
int dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};

int dfs(int u) {
    if(dis[u] != -1)
        return dis[u];

    int len = 0;
    for(auto v : G[u]) {
        //pf("%d -> %d\n", u, v);
        len = max(dfs(v), len);
    }
    return dis[u] = len+1;
}

int toNode(int x, int y) {
    return m*x + y;
}

void makeGraph(int x, int y) {
    int h1 = mat[x][y];
    for(int i = 0; i < 4; ++i) {
        int _x = x + dr[i];
        int _y = y + dc[i];
        
        if(_x < 0 || _y < 0 || _x >= n || _y >= m)
            continue;
        
        if(mat[_x][_y] < h1) {
            //pf("Connect %d - > %d\n(%d, %d) - > (%d, %d)\n%d %d\n", toNode(x, y), toNode(_x, _y), x, y, _x, _y, h1, mat[_x][_y]);
            G[toNode(x, y)].pb(toNode(_x, _y));
        }
    }
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t;
    char str[200];
    sf("%d", &t);   
    
    while(t--) {
        sf(" %s %d %d", str, &n, &m);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                sf("%d", &mat[i][j]);
            
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                makeGraph(i, j);
        
        int totNode = n*m;
                
        int ans = 0;
        memset(dis, -1, sizeof dis);
        for(int i = 0; i < totNode; ++i)
            if(dis[i] == -1) {
                //pf("start %d\n", i);
                ans = max(dfs(i), ans);
            }
        
        pf("%s: %d\n", str, ans);
        
        for(int i = 0; i < totNode; ++i)
            G[i].clear();
    }
    
    return 0;
}
