// QuwsarOhi

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
bool inQueue[MAX];
const int source = 0, offset1 = 2, offset2 = 105, sink = 210;
int cap[MAX][MAX], parent[MAX];
vii v[2];
vector<tuple<ll ,int, int> >Edge;

bool bfs(int s, int t) {
    queue<int>q;
    q.push(s);
    while(not q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = 0;
        for(int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if(v == t) return 1;
            if(cap[u][v] > 0) {
                parent[v] = u;
                if(not inQueue[v]) {
                    inQueue[v] = 1;
                    q.push(v);
    }}}}
    return 0;
}

int MaxFlow(int s, int t) {
    int max_flow = 0, flow;
    while(bfs(s, t)) {
        flow = INF;
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, cap[u][v]);
        }
        for(int v= t; v != s; v = parent[v]) {
            int u = parent[v];
            cap[u][v] -= flow;
            cap[v][u] += flow;
        }
        max_flow += flow;
    }
    return max_flow;
}

void AddEdge(int u, int v, int cost) {
    G[u].pb(v), G[v].pb(u);
    cap[u][v] = cap[v][u] = cost;
}



int main() {
    int t, E, K, x, y;
    sf("%d", &t);
    char typ[50];

    while(t--) {
        sf("%d%d", &E, &K);
        for(int i = 0; i < E; ++i) {
            sf("%d%d %s", &x, &y, typ);
            v[strcmp(typ, "blue")].pb({x, y});
        }

        for(int i = 0; i < v[0].size(); ++i)
            for(int j = 0; j < v[1].size(); ++j) {
                ll w = dist(v[0][i].fi, v[0][i].se, v[1][j].fi, v[1][j].se);
                Edge.pb(make_tuple(w, i+offset1, j+offset2));
            }
        sort(Edge.begin(), Edge.end());

        ll lo = 0, hi = INF;
        while(lo <= hi) {
            ll k = (lo+hi)>>1;

            AddEdge(source, 1, INF);
            for(auto it : Edge) {
                ll w = get<0>(it), u = get<1>(it), v = get<2>(it);
                if(w > k) break;
                AddEdge(1, u, 1);
                AddEdge(u, v, 1);
                AddEdge(v, sink, 1);
            }

            ll flow = MaxFlow(source, sink);

            if(flow >= k) {
                ans = min(flow, ans);
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
    }

    return 0;
}
