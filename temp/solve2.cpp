#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
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

#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

vector<int> G[MAX], Tree[MAX];
vector<pair<int, int> >ans;
int dfs_num[MAX], dfs_low[MAX], parent[MAX], dfsCounter;

void bridge(int u) {
    // dfs_num[u] is the dfs counter of u node
    // dfs_low[u] is the minimum dfs counter of u node (it is minimum if a backedge exists)
    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(dfs_num[v] == 0) {
            parent[v] = u;
            bridge(v);
            // if dfs_num[u] is lower than dfs_low[v], then there is no back edge on u node
            // so u - v can be a bridge
            if(dfs_num[u] < dfs_low[v])
                ans.push_back(make_pair(min(u, v), max(u, v)));
            // obtainig lower dfs counter (if found) from child nodes
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        // if v is not parent of u then it is a back edge
        // also dfs_num[v] must be less than dfs_low[u]
        // so we update it
        else if(parent[u] != v)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}}

int BuildNewTree(int V) {
    memset(dfs_num, 0, sizeof dfs_num);
    int ncnt = 1;                                   // Tree's node starts from 1
    for(int i = 1; i <= V; ++i)                     // dfs_low[i] contains new tree node mapping
        if(dfs_num[dfs_low[i]] == 0)                // from the previous graph
            dfs_num[dfs_low[i]] = ncnt++;

    for(int i = 1; i <= V; ++i)
        dfs_low[i] = dfs_num[dfs_low[i]];

    for(auto it : ans) {
        int u = it.first, v = it.second;
        Tree[dfs_low[u]].pb(dfs_low[v]);
        Tree[dfs_low[v]].pb(dfs_low[u]);
        cerr << dfs_low[u] << " -- " << dfs_low[v] << endl;
        cerr << "Actual " << u << " -- " << v << endl;
    }
    return ncnt;
}

int FindBridge(int V){                             //Bridge finding code
    memset(dfs_num, 0, sizeof(dfs_num));
    dfsCounter = 0;
    for(int i = 1; i <= V; i++)
        if(dfs_num[i] == 0) 
            bridge(i);
    for(int i = 1; i <= V; ++i)
        cerr << i << " :: " << dfs_num[i] << " :: " << dfs_low[i] << endl;
    return BuildNewTree(V);
}

int level[MAX], sparse[MAX][20];

void dfs(int u, int par, int lvl) {                 // Tracks distance as well (From root 1 to all nodes)
    level[u] = lvl;                                 // parent[] and level[] is necessary
    parent[u] = par;                                
    for(int i = 0; i < (int)Tree[u].size(); ++i)
        if(parent[u] != G[u][i])
            dfs(Tree[u][i], u, lvl+1);
}

void LCAinit(int V) {
    memset(parent, -1, sizeof parent);
    dfs(1, -1, 0);                               // DFS first
    memset(sparse, -1, sizeof sparse);              // Main initialization of sparse table LCA starts here
    for(int u = 1; u <= V; ++u)                     // node u's 2^0 parent
        sparse[u][0] = parent[u];
    for(int p = 1, v; (1LL<<p) <= V; ++p)
        for(int u = 1; u <= V; ++u)
            if((v = sparse[u][p-1]) != -1)      // node u's 2^x parent = parent of node v's 2^(x-1) [ where node v : (node u's 2^(x-1) parent) ]
                sparse[u][p] = sparse[v][p-1];
}

int LCA(int u, int v) {
    if(level[u] > level[v]) swap(u, v);         // v is deeper
    int p = ceil(log2(level[v]));
    for(int i = p ; i >= 0; --i)                // Pull up v to same level as u
        if(level[v] - (1LL<<i) >= level[u])
            v = sparse[v][i];
    if(u == v) return u;                // if u WAS the parent
    for(int i = p; i >= 0; --i)                                     // Pull up u and v together while LCA not found
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i])      // -1 check is if 2^i is out of calculated range
            u = sparse[u][i], v = sparse[v][i];
    return parent[u];
}

int main() {
    int V, E, Q, u, v;
    sf("%d%d%d", &V, &E, &Q);

    for(int i = 0; i < E; ++i){
        sf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }

    int treeV = FindBridge(V);
    LCAinit(treeV);
    return 0;
}