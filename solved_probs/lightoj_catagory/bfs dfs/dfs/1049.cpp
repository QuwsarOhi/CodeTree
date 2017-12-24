// LightOJ
// 1049 - One Way Roads

#include <bits/stdc++.h>
using namespace std;
#define MAX                 150
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

vi G[MAX], W[MAX];
bitset<MAX>visited;

int bfs(int start, int n) {         // Not used
    visited.reset();
    priority_queue<pii>pq;
    pq.push(mp(0, start));
    visited[start] = 1;
    
    while(!pq.empty()) {
        int u = pq.top().se;
        int w = pq.top().fi;
        pq.pop();
        
        for(int i = 0; i < SIZE(G[u]); ++i) {
            int v = G[u][i];
            int _w = w + W[u][i];
            
            if((int)visited.count() == n && v == start) {
                pf("lst from %d to %d : %d\n", u, v, _w);
                return _w;
            }
            
            if(!visited[v]) {
                pf("from %d to %d : %d\n", u, v, _w);
                visited[v] = 1;
                pq.push(mp(_w, v));
            }
        }
    }
    
    return -1;
}

int dfs(int start, int u, int n, int w) {       // Search for all options
    int ans = INF;
    for(int i = 0; i < SIZE(G[u]); ++i) {
        int v = G[u][i];
        int _w = W[u][i] + w;
        
        if((int)visited.count() == n && v == start) {       // Input Graphs are Rings, so at one time, it will come to the start node
            //pf("ans found %d -> %d : %d\n", u, v, _w);     // This is the graph which is Strongly Connected
            ans = min(ans, _w);
        }
        
        if(!visited[v]) {
            //pf("%d -> %d\n", u, v);
            visited[v] = 1;
            ans = min(dfs(start, v, n, _w), ans);
            //pf("back %d -> %d\n", u, v);
            visited[v] = 0;
        }
    }
    
    return ans;
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, u, v, w, n;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d", &n);
        pf("Case %d: ", Case);
        
        for(int i = 0; i < n; ++i) {
            sf("%d %d %d", &u, &v, &w);
            G[u].pb(v);         // Connect the road that is already stated in input
            W[u].pb(0);         // Connected edges are 0 weighted
            G[v].pb(u);         // Also add the reverse edges
            W[v].pb(w);         // To construct this edge, the weight/cost is w
        }
        
        //pf("%d\n", bfs(1, n));
        visited[1] = 1;
        pf("%d\n", dfs(1, 1, n, 0));
        
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            W[i].clear();
        }
    }
    
    return 0;
}
