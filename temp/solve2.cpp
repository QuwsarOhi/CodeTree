#include <bits/stdc++.h>
using namespace std;
#define MAX                 225
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

vi G[MAX], W[MAX], dist[MAX];
bool block[MAX][MAX];
int parent[MAX];//, dist[MAX];
pii lstEdge;

void BlockEdge(int src, int dest) {
    if(src == dest) return;
    block[dest][parent[dest]] = block[parent[dest]][dest] = 1;
    // lstEdge.fi = parent[dest], lstEdge.se = dest;
    BlockEdge(src, parent[dest]);
}

int KthDikjstra(int Start, int End, int Kth = 5) {      // Kth Shortest Path (Visits Edge Only Once)
    for(int i = 0; i < MAX; ++i)
        dist[i].clear();
    priority_queue<pii>pq;                  // Weight, Node
    pq.push(make_pair(0, Start));
   
    while(!pq.empty()) {
        int u = pq.top().second;
        int w = -pq.top().first;
        pq.pop();
       
        if((int)dist[End].size() == Kth)    // We can also break if the Kth path is found
            return dist[End].back();
        if(dist[u].empty())
            dist[u].push_back(w);
        //else if(dist[u].back() != w)        // Not taking same cost paths
            dist[u].push_back(w);           // As priority queue greedily chooses edge, it's guranteed that this edge is bigger than previous
        if((int)dist[u].size() > Kth)       // Like basic dikjstra, we'll not take the Kth+ edges
            continue;
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            int _w = w + W[u][i];
            if((int)dist[v].size() == Kth)
                continue;
            if(parent[u] == v) continue;
            parent[v] = u;
            cerr << u << " to " << v << " : " << _w << endl;
            pq.push(make_pair(-_w, v));
    }}
    return -1;
}
    
/*
int Dikjstra(int s, int d) {
    for(int i = 0; i <= d; ++i) dist[i] = INT_MAX;
    queue<int>q;
    q.push(s);
    dist[s] = 0;
    
    while(not q.empty()) {
        int u = q.front();
        q.pop();
        if(u == d) return dist[u];
        for(int i = 0; i < G[u].size(); ++i) {
            if(not block[u][G[u][i]] and (dist[u] + W[u][i] < dist[G[u][i]])) {
                parent[G[u][i]] = u;
                dist[G[u][i]] = dist[u] + W[u][i];
                //cerr << u << " " << G[u][i] << " " << dist[G[u][i]] << endl;
                q.push(G[u][i]);
    }}}
    return -1;
}*/


int main() {
    //fileRead("in");
    //fileWrite("out");
    int u, v, w, E, n;
    while(sf("%d", &n) == 1 and n) {
        sf("%d", &E);
        while(E--) {
            sf("%d%d%d", &u, &v, &w);
            G[u].pb(v), G[v].pb(u), W[u].pb(w), W[v].pb(w);
        }
        
        memset(block, 0, sizeof block);
        
        /*int ans = INT_MAX;
        int x = Dikjstra(1, n), y;
        
        while(1) {
            if(x == -1) break;
            BlockEdge(1, n);
            y = Dikjstra(1, n);
            if(y == -1) break;
            ans = min(ans, x+y);
            swap(x, y);
        }*/
        
        
       // cerr << x << " " << y << endl;
        /*if(ans == INT_MAX)
            pf("Back to jail\n");
        else
            pf("%d\n", ans);*/
        
        KthDikjstra(1, n, (n*(n+1))/2);
        for(int i = 0; i < n*(n+1)/2; ++i)
            cout << i << " " << dist[n][i] << endl;
        
        for(int i = 1; i <= n; ++i) G[i].clear(), W[i].clear();
    }
    return 0;
}
