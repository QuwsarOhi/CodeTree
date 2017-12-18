#include <bits/stdc++.h>
using namespace std;
#define MAX                 1000
#define EPS                 1e-9
#define INF                 1e9+10
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


int tree[4*MAX], size[MAX], parent[MAX], level[MAX], nextNode[MAX], chain[MAX], num[MAX], val[MAX], numToNode[MAX], top[MAX], ChainSize[MAX], mx[MAX];
int ChainNo = 1, all = 1, n;
vi G[MAX];


// Segment tree operations

void init(int pos, int L, int R) {
    if(L == R) {
        tree[pos] = val[numToNode[L]];
        return;
    }
    
    int mid = (L+R)>>1;
    init(pos<<1, L, mid);
    init(pos<<1|1, mid+1, R);
    
    tree[pos] = tree[pos<<1] + tree[pos<<1|1];
}

void update(int pos, int L, int R, int idx, int val) {
    if(idx < L || R < idx)
        return;
    
    if(L == R) {
        tree[pos] = val;
        return;
    }
    
    int mid = (L+R)>>1;
    update(pos<<1, L, mid, idx, val);
    update(pos<<1|1, mid+1, R, idx, val);
    
    tree[pos] = max(tree[pos<<1], tree[pos<<1|1]);
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

// Segment tree operations done


void dfs(int u, int Parent) {
    parent[u] = Parent;             // Parent of u
    size[u] = 1;                    // Number of child (initially the size is 1, contains only 1 node. itself)
    
    for(int i = 0; i < SIZE(G[u]); ++i) {
        int v = G[u][i];
        if(v == Parent)             // if the connected node is parent, skip
            continue;
        level[v] = level[u]+1;      // level of the child node is : level of parent node + 1
        dfs(v, u);
        size[u] += size[v];         // Increment the child numbers
        if(nextNode[u] == -1 || size[v] > size[nextNode[u]])
            nextNode[u] = v;            // next selected node of u (select the node which has more child, (HEAVY))
    }
}

// size is only used in dfs, this can be used as ChainSize ?

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


int GetMax(int u, int v) {
    int res = 0;
    
    while(chain[u] != chain[v]) {           // While two nodes are not in same chain
        if(level[top[chain[u]]] < level[top[chain[v]]])     // u is the chain which's topmost node is deeper
            swap(u, v);
        int start = top[chain[u]];
        
        //if(num[u] == num[start] + ChainSize[chain[u]] - 1)  // if this node is the last node of the chain
            //res = max(res, mx[chain[u]]);
        //else
            res = max(res, query(1, 1, n, num[start], num[u]));
        u = parent[start];
    }
    
    if(level[u] > level[v])
        swap(u, v);
    
    res = max(res, query(1, 1, n, num[u], num[v]));
    return res;
}

void updateNodeVal(int u, int val) {
    update(1, 1, n, num[u], val);                   // Updating the value of chain
    //int Start = num[top[chain[u]]];                 // Start position of chain
    //int End = Start + ChainSize[chain[u]] - 1;      // End position of chain
    //mx[chain[u]] = query(1, 1, n, Start, End);      // Calculating RMQ of the modified chain
}

void numToNodeConv(int n) {
    for(int i = 1; i <= n; ++i)
        numToNode[num[i]] = i;
}

void infoPrint(int n) {
    pf("Size ----------\n");
    for(int i = 1; i <= n; ++i)
        pf("%d = %d\n", i, size[i]);
    
    pf("parent ----------\n");
    for(int i = 1; i <= n; ++i)
        pf("%d : %d\n", i, parent[i]);
    
    pf("num -------------\n");
    for(int i = 1; i <= n; ++i)
        pf("%d : %d\n", i, num[i]);
    
    pf("total chains %d\nChain Size\n", ChainNo);
    for(int i = 1; i <= ChainNo; ++i)
        pf("%d : %d\n", i, ChainSize[i]);
    
    pf("next node -------------\n");
    for(int i = 1; i <= n; ++i)
        pf("%d -> %d\n", i, nextNode[i]);
    
    pf("Chain Top nodes -----------\n");
    for(int i = 1; i <= ChainNo; ++i)
        pf("%d : %d\n", i, top[i]);
}

int main() {
    fileRead("in");
    
    int u, v, q, Val, t;
    sf("%d", &n);
    
    for(int i = 1; i <= n; ++i)     // value of each node
        sf("%d", &val[i]);
    
    for(int i = 1; i < n; ++i) {    // tree edges
        sf("%d %d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    
    memset(nextNode, -1, sizeof nextNode);
    memset(ChainSize, 0, sizeof ChainSize);
    
    dfs(1, 1);
    hld(1, 1);
    infoPrint(n);
    
    sf("%d", &q);
    
    while(q--) {
        sf("%d", &t);        // 0 to query, 1 to update
        if(t == 0) {
            sf("%d %d", &u, &v);
            pf("%d", GetMax(u, v));
        }
        else {
            sf("%d %d", &u, &Val);
            updateNodeVal(u, Val);
        }
    }
    
    return 0;
}