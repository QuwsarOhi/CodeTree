// UVa
// 11331 - The Joys of Farming
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2306&mosmsg=Submission+received+with+ID+21796354

#include <bits/stdc++.h>
using namespace std;
#define MAX                 2100
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

vi G[MAX];
vii V;
int black, white;
int color[MAX];

bool bfs(int u) {
    color[u] = 1;
    black++;
    queue<int>q;
    q.push(u);
    
    while(not q.empty()) {
        u = q.front();
        q.pop();
        for(auto v : G[u]) {
            if(color[v] == -1) {
                if(color[u] == 1) {
                    color[v] = 2;
                    ++white;
                }
                else {
                    color[v] = 1;
                    ++black;
                }
                q.push(v);
            }
            else if(color[u] == color[v])
                return 0;
        }
    }
    return 1;
}
                

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, a, b, c, u, v;
    sf("%d", &t);
    
    while(t--) {
        bool ok = 1;
        sf("%d%d%d", &b, &c, &a);
        int tot = b+c;
        
        while(a--) {
            sf("%d%d", &u, &v);
            G[u].pb(v), G[v].pb(u);
        }
        
        memset(color, -1, sizeof color);
        V.clear();
        
        for(int i = 1; i <= tot; ++i) {
            if(color[i] == -1) {
                black = white = 0;
                if(not bfs(i)) {
                    ok = 0;
                    break;
                }
                else
                    V.pb({max(white, black), min(white, black)});
        }}
        
        for(int i = 0; i <= tot; ++i) G[i].clear();
        if(not ok) {
            puts("no");
            continue;
        }
        
        sort(V.begin(), V.end(), greater<pii>());
        
        int x = 0, y = 0;
        for(auto it : V) {
            if(b-x > c-y)
                x += it.fi, y += it.se;
            else
                x += it.se, y += it.fi;
        }
        
        if(x == b and y == c)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
