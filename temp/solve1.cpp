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

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}, n, m, lstX, lstY;
char G[50][50];
bool visited[50][50];

int dfs(int x, int y, int gold, int cst) {
    if(gold == 0) {
        lstX = x, lstY = y;
        return cst;
    }
    
    for(int i = 0; i < 8; ++i) {
        int _x = x+dx[i];
        int _y = y+dy[i];
       
        if(_x < 0 || _y < 0 || _x >=n || _y >= m)
            continue;
        
        if(visited[_x][_y] == 2)
            continue;
        
        visited[_x][_y]+=1;
        dfs(_x, _y, gold-(G[_x][_y] == 'g' || G[_x][_y] == 'x'), cst+1);
        visited[]
    }
}
        
        
int main() {
    fileRead("in");
    fileWrite("out");
    
    int t, x, y, gold;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d %d", &n, &m);
        gold = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                sf(" %c", &G[i][j]);
                if(G[i][j] == 'g')
                    ++gold;
                if(G[i][j] == 'x')
                    x = i, y = j;
            }
        
        memset(visited, 0, sizeof visited);
        int ans = bfs(x, y, gold);
        ans = ans + abs(x-lstX) + abs(y-lstY);
        pf("%d added %d\n", ans, abs(x-lstX) + abs(y-lstY));
        pf("Case %d: %d\n", Case, ans);
    }
    
    return 0;
}
