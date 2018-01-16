// UVa
// 820 - Internet Bandwidth
// MaxFlow

#include <bits/stdc++.h>
using namespace std;
#define MAX                 120
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


vector<int>edge[MAX];
int V, E, rG[MAX][MAX], parent[MAX];

bool bfs(int s, int d) {                // augment path : source, destination
    memset(parent, -1, sizeof parent);
    queue<int>q;
    q.push(s);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(auto v : edge[u])
            if(parent[v] == -1 && rG[u][v] > 0) {                
                parent[v] = u;
                q.push(v);
            }
    }
    
    return parent[d] != -1;
}
                

int maxFlow(int s, int d) {             // source, destination
    int max_flow = 0;

    while((bfs(s, d))) {
        int flow = INT_MAX;
        
        for(int v = d; v != s; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, rG[u][v]);
        }
        
        for(int v = d; v != s; v = parent[v]) {
            int u = parent[v];
            rG[u][v] -= flow;
            rG[v][u] += flow;
        }
        max_flow += flow;
    }
    
    return max_flow;
}
    

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int u, v, w, source, destination, Case = 1;
    map<pair<int, int>, bool>Map;
    
    while(scanf("%d", &V) && V) {
        scanf("%d%d%d", &source, &destination, &E);
        
        memset(rG, 0, sizeof rG);
        for(int i = 0; i < E; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            rG[u][v] += w;                          // edges are undirected
            rG[v][u] += w;                          // remove this line if edges are directed
            
            if(Map.find({u, v}) == Map.end()) {             // same edges might occur more than once
                edge[u].push_back(v);                       // to avoid n^2 calculation
                edge[v].push_back(u);
                Map[{u, v}] = Map[{v, u}] = 1;
            }
        }
        
        printf("Network %d\n", Case++);
        printf("The bandwidth is %d.\n\n", maxFlow(source, destination));
        
        for(int i = 0; i <= V; ++i)
            edge[i].clear();
        Map.clear();
    }
    
    return 0;
}
