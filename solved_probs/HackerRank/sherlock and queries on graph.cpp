// Hackerrank
// https://www.hackerrank.com/contests/101hack26/challenges/sherlock-and-queries-on-the-graph

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
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
int dfs_num[MAX], dfs_low[MAX], dfsCounter, timeToNode[MAX];

void bridge(int u, int par = -1) {
    // dfs_num[u] is the dfs counter of u node
    // dfs_low[u] is the minimum dfs counter of u node (it is minimum if a backedge exists)
    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    //timeToNode[dfs_num[u]] = u;
    for(auto v : G[u]) {
        if(v == par) continue;
        if(dfs_num[v] == 0) {
            bridge(v, u);
            // if dfs_num[u] is lower than dfs_low[v], then there is no back edge on u node
            // so u - v can be a bridge
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if(dfs_num[u] < dfs_low[v])
                ans.push_back(make_pair(min(u, v), max(u, v)));
        }
        // if v is not parent of u then it is a back edge
        // also dfs_num[v] must be less than dfs_low[u]
        // so we update it
        else if(v != par)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
    timeToNode[dfs_num[u]] = u;         // if BuildNewTree is used otherwise ignore it
}


int conv[MAX] = {0}, ncnt;
int Convert(int u) {
    if(conv[dfs_low[u]] == 0)
        conv[dfs_low[u]] = ++ncnt;
    return conv[dfs_low[u]];
}

int findMin(int u) {
    if(dfs_low[u] == dfs_num[u]) return dfs_low[u];
    return dfs_low[u] = findMin(timeToNode[dfs_low[u]]);
}

int BuildNewTree(int V) {
    ncnt = 0;
    for(int i = 1; i <= V; ++i) 
        findMin(i);
    for(auto it : ans) {
        int u = Convert(it.first), v = Convert(it.second);
        Tree[u].pb(v);
        Tree[v].pb(u);
    }
    return ncnt;
}

int FindBridge(int V){                             //Bridge finding code
    memset(dfs_num, 0, sizeof(dfs_num));
    dfsCounter = 0;
    for(int i = 1; i <= V; i++)
        if(dfs_num[i] == 0) 
            bridge(i);
    return BuildNewTree(V);
}

int level[MAX], sparse[MAX][25], parent[MAX];
void dfs(int u, int par, int lvl) {                 // Tracks distance as well (From root 1 to all nodes)
    level[u] = lvl;                                 // parent[] and level[] is necessary
    parent[u] = par;                             
    for(auto v : Tree[u])
        if(par != v)
            dfs(v, u, lvl+1);
}

void LCAinit(int V) {
    memset(parent, -1, sizeof parent);
    dfs(1, -1, 0);                                  // DFS first
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
    if(u == v) return u;                        // if u WAS the parent
    for(int i = p; i >= 0; --i)                                     // Pull up u and v together while LCA not found
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i])      // -1 check is if 2^i is out of calculated range
            u = sparse[u][i], v = sparse[v][i];
    return parent[u];
}

int startTime[MAX], endTime[MAX], Time = 1;
void dfsTiming(int u = 1, int par = -1) {
    startTime[u] = Time;
    for(auto v : Tree[u])
        if(v != par) {
            ++Time;
            dfsTiming(v, u);
        }
    endTime[u] = Time;
}

int dist(int a, int b, int lca) {
    return level[a]+level[b]-2*level[lca];
}

bool isChild(int child, int par) {                                  // returns true if a is child of b
    return ((child == par) or ((startTime[par] <= startTime[child]) and (endTime[par] >= endTime[child])));
}

// a is upper node of path a-b and c is upper node of path c-d
pii overlapPath(int a, int b, int c, int d) {      // returns number of common path of c-d and a-b
    // path a-b and c-d overlaps iff b is a child of c or d or both of c&d
    if(not isChild(b, c)) return {0, 0};
    int u = LCA(b, d);              // u is the lowest point on which c-d and a-b overlaps
    if(level[a]>level[c]) {             // a is below c 
        if(isChild(u, a))           // also u is child of a
            return {a, u};
    }
    else {                          // c is above a
        if(isChild(u, c))
            return {c, u};
    }
    return {0, 0};                  // no common path found
}

int Solve(int a, int b, int c, int d) {
    a = Convert(a), b = Convert(b), c = Convert(c), d = Convert(d);

    int u = LCA(a, b);
    int v = LCA(c, d);
    int ans = dist(c, d, v);
    pii tt;

    // connected paths are u->a & u->b
    // query paths are v->c & v->d
    // cases:
    // u->a overlaps v->c
    tt = overlapPath(v, c, u, a);
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    // u->a overlaps v->d
    tt = overlapPath(v, c, u, b);
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    // u->b overlaps v->c
    tt = overlapPath(v, d, u, a);
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    // u->b overlaps v->d
    tt = overlapPath(v, d, u, b);
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    return ans;
}

/*
9 11 0
2 1
6 2
5 4
7 2
3 4
5 3
1 3
6 7
2 3
1 8
4 9
*/



int main() {
    //fileRead("in");
    //fileWrite("out");

    int V, E, Q, u, v, a, b, c, d;
    sf("%d%d%d", &V, &E, &Q);

    for(int i = 0; i < E; ++i) {
        if(u > v) swap(u, v);
        sf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);

    }

    int treeV = FindBridge(V);
    LCAinit(treeV);
    dfsTiming();

    while(Q--) {
        sf("%d%d%d%d", &a, &b, &c, &d);
        int ret = Solve(a, b, c, d);
        pf("%d\n", ret);
    }
    return 0;
}