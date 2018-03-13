#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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


void dfs(int u, int par, int lvl) {           // Tracks distance as well (From root 1 to all nodes)
    level[u] = lvl;                                 // parent[] and level[] is necessary
    parent[u] = par;
    start[u] = ++timer;
    
    for(auto v : G[u])
        if(par != v)
            dfs(v, u, lvl+1);
    finish[u] = timer;
}

void LCAinit(int V) {
    // Main initialization of sparse table LCA starts here
    memset(sparse, -1, sizeof sparse);
    
    for(int u = 1; u <= V; ++u)                 // node u's 2^0 parent
        sparse[u][0] = parent[u];
    
    int v;
    for(int p = 1; (1LL<<p) <= V; ++p)
        for(int u = 1; u <= V; ++u)
            if((v = sparse[u][p-1]) != -1)      // node u's 2^x parent = parent of node v's 2^(x-1) [ where node v : (node u's 2^(x-1) parent) ]
                sparse[u][p] = sparse[v][p-1];
}


int LCA(int u, int v) {
    if(level[u] > level[v])     // v is deeper
        swap(u, v);
    
    int p = ceil(log2(level[v]));
    
    // Pull up v to same level as u
    for(int i = p ; i >= 0; --i)
        if(level[v] - (1LL<<i) >= level[u])
            v = sparse[v][i];
    
    // if u WAS the parent
    if(u == v)
        return u;
    
    // Pull up u and v together while LCA not found
    for(int i = p; i >= 0; --i)
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i])      // -1 check is if 2^i is out of calculated range
            u = sparse[u][i], v = sparse[v][i];
    
    return parent[u];
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
        Set[pos].insert(val[revStart[i]]);
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
    
    // LCA + DFS Tree
    memset(parent, -1, sizeof parent);
    dfs(1, -1, 0);
    LCAinit(n);
    
    for(int i = 1; i <= n; ++i)
        revStart[start[i]] = i;
    
    init(1, 1, n);
    
    while(q--) {
        fastIn(u), fastIn(v);
        int lca = LCA(u, v);
        
    }
