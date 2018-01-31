// LightOJ
// 1101 - A Secret Mission
// Segment Tree, Heavy Light Decomposition, LCA, MST

#include <bits/stdc++.h>
using namespace std;
#define MAX                 500000
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

int tree[5*MAX], parent[MAX], level[MAX], nextNode[MAX], chain[MAX], num[MAX], val[MAX], numToNode[MAX], top[MAX], ChainSize[MAX], mx[MAX], child[MAX];
int ChainNo = 1, all = 1;
vi G[MAX], W[MAX], u_list, u_set;
vector<pair<int, pii> > Edge;

int unionRoot(int n) {
    if(u_set[n] == n)
        return n;
    else
        return u_set[n] = unionRoot(u_set[n]);
}

int makeUnion(int a, int b) {
    int x = unionRoot(a);
    int y = unionRoot(b);

    if(x == y)
        return x;
    else if(u_list[x] > u_list[y]) {
        u_set[y] = x;
        u_list[x] += u_list[y];
        return x;
    }
    else {
        u_set[x] = y;
        u_list[y] += u_list[x];
        return y;
    }
}

void unionInit(int len) {
    u_list.resize(len+5, 1);
    u_set.resize(len+5);

    for(int i = 0; i <= len; i++)
        u_set[i] = i;
}

bool isSameSet(int a, int b) {
    if(unionRoot(a) == unionRoot(b))
        return 1;
    return 0;
}

// Segment tree operations start

void init(int pos, int L, int R) {
    if(L == R) {
        tree[pos] = val[numToNode[L]];
        return;
    }
    
    int mid = (L+R)>>1;
    init(pos<<1, L, mid);
    init(pos<<1|1, mid+1, R);
    
    tree[pos] = max(tree[pos<<1] ,tree[pos<<1|1]);
}

int query(int pos, int L, int R, int l, int r) {
    if(r < L || R < l)
        return 0;
    
    if(l <= L && R <= r)
        return tree[pos];
    
    int mid = (L+R)>>1;
    int lft = query(pos<<1, L, mid, l, r);
    int rht = query(pos<<1|1, mid+1, R, l, r);
    return max(lft, rht);
}

// Segment tree operations end
// Heavy Light Decomposition Start

void dfs(int u, int Parent, int NodeWeight) {
    parent[u] = Parent;             // Parent of u
    child[u] = 1;                   // Number of child (Can Be reused)
    val[u] = NodeWeight;
    
    for(int i = 0; i < SIZE(G[u]); ++i) {
        int v = G[u][i];
        if(v == Parent)
            continue;
        level[v] = level[u]+1;
        dfs(v, u, W[u][i]);
        
        child[u] += child[v];           // Increment the child numbers, to identify heavy chains
        if(nextNode[u] == -1 || child[v] > child[nextNode[u]])
            nextNode[u] = v;            // next selected node of u (select the node which has more child, (HEAVY))
    }
}

void hld(int u, int Parent) {
    chain[u] = ChainNo;                 // Chain Number
    num[u] = all++;                     // Numbering all nodes
    
    if(ChainSize[ChainNo] == 0)         // if this is the first node
        top[ChainNo] = u;               // mark this as the root node of the n'th chain
        
    ChainSize[ChainNo]++;
    
    if(nextNode[u] != -1)               // if this node has a child, go to it
        hld(nextNode[u], u);            // the next node is included in the chain
    
    for(int i = 0; i < SIZE(G[u]); ++i) {
        int v = G[u][i];
        if(v == Parent || v == nextNode[u])     // if this node is parent node or, this node is already included in the chain, skip
            continue;
        ChainNo++;                          // this is a new (light) chain, so increment the chain no. counter
        hld(v, u);
    }
}


int GetMax(int u, int v, int V) {
    int res = 0;
    
    while(chain[u] != chain[v]) {                           // While two nodes are not in same chain
        if(level[top[chain[u]]] < level[top[chain[v]]])     // u is the chain which's topmost node is deeper
            swap(u, v);
        //cout << u << " ? " << v << endl;
        int start = top[chain[u]];
        res = max(query(1, 1, V, num[start], num[u]), res);             // Run query in u node's chain
        u = parent[start];                                              // go to the upper chain of u
        //cout << "res " << res <<endl;
    }
    
    //cout << u << " ?* " << v << endl;
    if(num[u] > num[v])
        swap(u, v);
    //cout << "num " << num[u] << " " << num[v] << endl;
    res = max(query(1, 1, V, num[u]+1, num[v]), res);
    return res;
}


void numToNodeConv(int n) {
    for(int i = 1; i <= n; ++i)
        numToNode[num[i]] = i;
}


int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, q, w, u, v, V, E;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d %d", &V, &E);
        
        for(int i = 1; i <= E; ++i) {
            sf("%d %d %d", &u, &v, &w);
            Edge.pb(mp(w, mp(u, v)));
        }
        
        sort(Edge.begin(), Edge.end());
        unionInit(V);
        
        int takenEdge = 0;
        for(int i = 0; i < E; ++i) {
            u = Edge[i].se.fi;
            v = Edge[i].se.se;
            w = Edge[i].fi;
            
            if(!isSameSet(u, v)) {
                takenEdge++;
                makeUnion(u, v);
                G[u].pb(v);
                G[v].pb(u);
                W[u].pb(w);
                W[v].pb(w);
                //cout << u << " + " << v << endl;
            }
        }
        
        //cout << "MST done\n";
        
        ChainNo = all = 1;
        memset(nextNode, -1, sizeof nextNode);
        memset(level, 0, sizeof level);
        dfs(1, 1, 0);
        memset(ChainSize, 0, sizeof ChainSize);
        //cout << "DFS done\n";
        hld(1, 1);
        numToNodeConv(V);
        
        //memset(tree, 0, sizeof tree);
        init(1, 1, V);
        //cout << "HLD done\n";
        sf("%d", &q);
        
        pf("Case %d:\n", Case);
        while(q--) {
            sf("%d %d", &u, &v);
            pf("%d\n", GetMax(u, v, V));
        }
        
        for(int i = 0; i <= V; ++i)
            G[i].clear(), W[i].clear();
        Edge.clear();
    }
    
    return 0;
}
