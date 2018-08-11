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
vii point[2];
ll cost[MAX][MAX], cap[MAX][MAX], dist[MAX];
int parent[MAX];
bool inQueue[MAX];

bool Dikjstra(int s, int t) {
    queue<int>q;
    q.push(s);
    for(int i = 0; i < MAX; ++i) dist[i] = INF;
    dist[s] = 0, inQueue[s] = 1;        //
    
    while(not q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = 0;
        for(int i = 0; i <(int)G[u].size(); ++i) {
            int v = G[u][i];
            if(cap[u][v] > 0 and dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
                if(!inQueue[v])
                    inQueue[v] = 1, q.push(v);
    }}}
    return dist[t] != INF;
}

ll MaxChainLen; 
ll MinCostFlow(int s, int t, ll &max_flow) {
    ll flow = 0, min_cost = 0;
    max_flow = 0;
    while(Dikjstra(s, t)) {
        flow = INT_MAX;
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, cap[u][v]);
            //cerr << u << " " << v << endl;
        }
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            cap[u][v] -= flow, cap[v][u] += flow;
            cost[u][v] -= cost[v][u];
        }
        min_cost += flow*dist[t], max_flow += flow;
        MaxChainLen = max(MaxChainLen, dist[t]);
        cerr << "Flow " << flow << " dist " << dist[t] << endl;
    }
    return min_cost;
}

void AddEdge(int u, int v, int _cost, int _cap) {
    G[u].pb(v), G[v].pb(u);
    cap[u][v] = cap[v][u] = _cap;
    cost[u][v] = cost[v][u] = _cost;
}

double DIST(ll x1, ll y1, ll x2, ll y2) {
    ll x = x1-x2, y = y1-y2;
    return sqrt(x*x + y*y);
}

const int source = 0, sink = 210, offset1 = 2, offset2 = 104;

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int n, k, t, x, y;
    char typ[20];
    
    sf("%d", &t);
    
    while(t--) {
        sf("%d%d", &n, &k);
        
        for(int i = 0; i < n; ++i) {
            sf("%d%d %s", &x, &y, typ);
            point[strcmp(typ, "blue")].pb({x, y});
        }
        
        AddEdge(source, 1, 0, k);
        for(int i = 0; i < (int)point[0].size(); ++i) {
            AddEdge(1, offset1+i, 0, 1);
            for(int j = 0; j < (int)point[1].size(); ++j) {
                double w = DIST(point[0][i].first, point[0][i].second, point[1][j].first, point[1][j].second);
                //cerr << point[0][i].fi << ", " << point[0][i].se << " + " << point[1][j].fi <<  " " << point[1][j].se << " : " << w << " " << ceil(w) << endl;
                AddEdge(offset1+i, offset2+j, ceil(w), 1);
            }
        }

        for(int i = 0; i < (int)point[1].size(); ++i)
            AddEdge(offset2+i, sink, 0, 1);
        
        MaxChainLen = -1;
        ll flow = 0;
        ll ans = MinCostFlow(source, sink, flow);
        
        
        if(abs(cap[1][source] -k) < k)
            pf("Impossible\n");
        else
            pf("%d\n", MaxChainLen);
        
        for(int i = 0; i < MAX; ++i) G[i].clear();
        memset(cap, 0, sizeof cap);
        memset(cost, 0, sizeof cost);
        point[0].clear(), point[1].clear();
    }
    
    return 0;
}
