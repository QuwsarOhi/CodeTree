// UVa
// 11262 - Weird Fence
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2229&mosmsg=Submission+received+with+ID+21790809

#include <bits/stdc++.h>
using namespace std;
#define MAX                 220
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

vi G[MAX];
const int offset1 = 2, offset2 = 105;
vii v[2];
vector<tuple<ll ,int, int> >Edge;
bool vis[MAX];
int lft[MAX], rht[MAX];


void AddEdge(int u, int v, int cost) {
    G[u].pb(v);
}

ll dist(ll x1, ll y1, ll x2, ll y2) {
    ll x = x1-x2, y = y1-y2;
    return ceil(sqrt(x*x + y*y));
}

void ClearGraph() {
    for(int i = 0; i < MAX; ++i)
        G[i].clear();
}

int VertexCover(int u) {                    // Min Vertex Cover
    vis[u] = 1;
    for(int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) continue;                // If v is used earlier, skip
		vis[v] = 1;
        if(lft[v] == -1) {                  // If there is no node present on left of v
            lft[v] = u, rht[u] = v;
            return 1;
        }
        else if(VertexCover(lft[v])) {      // If there is one node present on the left side of v (Let it be u')
            lft[v] = u, rht[u] = v;         // and if it is possible to match u' with another node (not v ofcourse!)
            return 1;                       // then we can match this u with v, and u' is matched with another node as well
    }}
    return 0;
}

int BPM(int n) {                            // Bipartite Matching
    int cnt = 0;
    memset(lft, -1, sizeof lft);
    memset(rht, -1, sizeof rht);
    for(int i = 2; i <= n; ++i) {           // Nodes are numbered from 1 to n
        memset(vis, 0, sizeof vis);
        cnt += VertexCover(i);              // Check if there exists a match for node i
    }
    return cnt;
}

int BPMTRY(int weight) {
    ClearGraph();
    for(auto it : Edge) {
    ll w = get<0>(it), u = get<1>(it), v = get<2>(it);
        if(w > weight) break;
        AddEdge(u, v, 1);
    }
    return BPM(104);
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, E, K, x, y;
    sf("%d", &t);
    char typ[50];

    while(t--) {
        sf("%d%d", &E, &K);
        for(int i = 0; i < E; ++i) {
            sf("%d%d %s", &x, &y, typ);
            v[strcmp(typ, "blue")].pb({x, y});
        }

        for(int i = 0; i < (int)v[0].size(); ++i)
            for(int j = 0; j < (int)v[1].size(); ++j) {
                ll w = dist(v[0][i].fi, v[0][i].se, v[1][j].fi, v[1][j].se);
                Edge.pb(make_tuple(w, i+offset1, j+offset2));
            }
        sort(Edge.begin(), Edge.end());

        ll lo = 0, hi = 1000000;
        int ans = INF;
        while(lo <= hi) {
            int mxWeight = (lo+hi)>>1;

            int flow = BPMTRY(mxWeight);
            
            if(flow >= K) {
                cerr << "w " << mxWeight << endl;
                ans = min(ans, mxWeight);
                hi = mxWeight-1;
            }
            else
                lo = mxWeight+1;
        }
        
        if(ans == INF)
            pf("Impossible\n");
        else
            pf("%d\n", ans);

        v[0].clear(), v[1].clear();
        Edge.clear();
    }

    return 0;
}
