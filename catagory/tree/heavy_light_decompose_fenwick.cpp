// LightOJ
// 1348 - Aladdin and the Return Journey
// Heavy Light Decompose + Fenwick Tree

#include <bits/stdc++.h>
using namespace std;
#define MAX                 31000
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


int tree[MAX], parent[MAX], level[MAX], nextNode[MAX], chain[MAX], num[MAX], val[MAX], numToNode[MAX], top[MAX], ChainSize[MAX];
int ChainNo = 1, all = 1, n, MaxVal = 30100;
vi G[MAX];


// Fenwick tree operations start

void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int read(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void init(int n) {
    for(int i = 1; i <= n; ++i)
        update(num[i], val[i]);
}

// Fenwick tree operations end

// Heavy Light Decomposition Start

void dfs(int u, int Parent) {
    parent[u] = Parent;             // Parent of u
    ChainSize[u] = 1;               // Number of child (initially the size is 1, contains only 1 node. itself) (resued array in hld)
    
    for(int i = 0; i < SIZE(G[u]); ++i) {
        int v = G[u][i];
        if(v == Parent)             // if the connected node is parent, skip
            continue;
        level[v] = level[u]+1;      // level of the child node is : level of parent node + 1
        dfs(v, u);
        ChainSize[u] += ChainSize[v];         // Increment the child numbers
        if(nextNode[u] == -1 || ChainSize[v] > ChainSize[nextNode[u]])
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


int GetSum(int u, int v) {
    int res = 0;
    
    while(chain[u] != chain[v]) {                           // While two nodes are not in same chain
        if(level[top[chain[u]]] < level[top[chain[v]]])     // u is the chain which's topmost node is deeper
            swap(u, v);
        int start = top[chain[u]];
        res += read(num[u]) - read(num[start]-1);           // Run query in u node's chain
        u = parent[start];                                  // go to the upper chain of u
    }
    
    if(num[u] > num[v])
        swap(u, v);
    
    res += read(num[v]) - read(num[u]-1);
    return res;
}

void updateNodeVal(int u, int Val) {        // Modify node value
    update(num[u], -val[u]);                 // Update value of chain (in which the node is)
    val[u] = Val;
    update(num[u], Val);
}

// Heavy light Decomposition End

void infoPrint(int n) {                 // Debugger
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
    //fileRead("in");
    //fileWrite("out");
    
    int u, v, q, Val, t, c;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d", &n);
    
        for(int i = 1; i <= n; ++i)     // value of each node
            sf("%d", &val[i]);
    
        for(int i = 1; i < n; ++i) {    // tree edges
            sf("%d %d", &u, &v);
            u++, v++;                   // node starts from 0 to n-1
            G[u].pb(v);
            G[v].pb(u);
        }
        
        MaxVal = n+1;
        memset(tree, 0, sizeof tree);
        memset(nextNode, -1, sizeof nextNode);
        ChainNo = 1, all = 1;
        dfs(1, 1);
        memset(ChainSize, 0, sizeof ChainSize);     // array reused in hld
        hld(1, 1);
        init(n);
        pf("Case %d:\n", Case);
        sf("%d", &q);
    
        while(q--) {
            sf("%d", &c);        // 0 to query, 1 to update
            if(c == 0) {
                sf("%d %d", &u, &v);
                u++, v++;
                pf("%d\n", GetSum(u, v));
            }
            else {              // assign new value to node u
                sf("%d %d", &u, &Val);
                u++;
                updateNodeVal(u, Val);
            }
        }
        
        for(int i = 1; i <= n; ++i)
            G[i].clear();
    }
    
    return 0;
}