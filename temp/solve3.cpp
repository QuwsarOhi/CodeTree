#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long ll;

int parent[MAX], level[MAX], nextNode[MAX], chain[MAX], num[MAX], val[MAX], numToNode[MAX], top[MAX], ChainSize[MAX];
set<ll>Set[MAX*5];

inline void fastIn(int &num) {          // Fast IO, with space and new line ignoring
    bool neg = false;
    register int c;
    num = 0;
    c = getchar_unlocked();
    for( ; c != '-' && (c < '0' || c > '9'); c = getchar_unlocked());
    if (c == '-') {
        neg = true;
        c = getchar_unlocked();
    }
    for(; (c>47 && c<58); c=getchar_unlocked())
        num = (num<<1) + (num<<3) + c - 48;
    if(neg)
        num *= -1;
}

// Heavy Light Decomposition Start
void dfs(int u, int Parent) {
    parent[u] = Parent;             // Parent of u
    ChainSize[u] = 1;               // Number of child (initially the size is 1, contains only 1 node. itself) (resued array in hld)
    
    for(auto v : G[u]) {
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
    
    for(auto v : G[u]) {
        int v = G[u][i];
        if(v == Parent || v == nextNode[u])     // if this node is parent node or, this node is already included in the chain, skip
            continue;
        ChainNo++;                          // this is a new (light) chain, so increment the chain no. counter
        hld(v, u);
    }
}


void numToNodeConv(int n) {
    for(int i = 1; i <= n; ++i)
        numToNode[num[i]] = i;
}

void Merge(set<ll> &s1, set<ll> &s2, set<ll> &s3) {
    s1.clear();
    for(auto it : s2)
        s1.insert(it);
    for(auto it : s3)
        s1.insert(it);
}

void init(int pos, int l, int r) {
    if(l == r) {
        Set[pos].insert(val[numToNode[l]]);
        return;
    }
    int mid = (l+r)>>1;
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    Merge(Set[pos], Set[pos<<1], Set[pos<<1|1]);
}

int query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l)
        return;
    if(L <= l && r <= R)
        return Set[pos].size();
    int mid = (l+r)>>1;
    return query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R);
}

int HLDquery(int u, int v) {
    int ans = 0;
    
}


int main() {
    int n, q;
    
    fastIn(&n), fastIn(&q);
    
    for(int i = 1; i <= n; ++i)
        fastIn(&val[i]);
    
    for(int i = 1; i < n; ++i) {
        fastIn(&u), fastIn(&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    // HLD
    memset(nextNode, -1, sizeof nextNode);
    dfs(1, -1);
    memset(ChainSize, 0, ChainSize);
    hld(1, -1);
    numToNodeConv(n);
    
    // SEGTREE
    init(1, 1, n);
    
    while(q--) {
        fastIn(u), fastIn(v);
        printf("%d\n", query(1, 1, n, start[]));
    }
    
    return 0;
}

