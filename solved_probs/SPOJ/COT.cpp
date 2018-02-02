// SPOJ COT
// Tree, LCA

#include <bits/stdc++.h>
using namespace std;
#define MAX 111111
typedef vector<int> vi;

struct node {
    int val;
    node *lft, *rht;
    node(node *L = NULL, node *R = NULL, int v = 0) {
        val = v;
        L = lft;
        R = rht;
    }
};

node *presis[MAX];
vi G[MAX];
vector<pair<int, int> >vec;
int parent[MAX], sparse[MAX][19], level[MAX], val[MAX];
map<int, int>Map, ReMap;

node *null = new node(NULL, NULL, 0);

node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->lft = x->lft;
        tmp->rht = x->rht;
        tmp->val = x->val;
    }
    else {                  // Rewire
        tmp->lft = null;
        tmp->rht = null;
        tmp->val = 0;
    }
    return tmp;
}

inline void fastIn(int &num) {          // Fast IO
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


inline void update(node *pos, int l, int r, int idx, int val) {
    if(l == r) {
        pos->val += 1;
        return;
    }
    
    int mid = (l+r)>>1;
    
    pos->lft = nCopy(pos->lft);
    pos->rht = nCopy(pos->rht);
    
    if(idx <= mid)
        update(pos->lft, l, mid, idx, val);
    else
        update(pos->rht, mid+1, r, idx, val);
    
    pos->val = 0;
    if(pos->lft)
        pos->val += pos->lft->val;
    if(pos->rht)
        pos->val += pos->rht->val;
}

inline int query(node *lca0, node *lca, node *u, node *v, int l, int r, int k) {        // More fast Query?
    if(l == r)
        return l;
    
    int mid = (l+r)>>1;
    int Count = u->lft->val + v->lft->val - lca->lft->val - lca0->lft->val;
    
    if(Count >= k)
        return query(lca0->lft, lca->lft, u->lft, v->lft, l, mid, k);
    else
        return query(lca0->rht, lca->rht, u->rht, v->rht, mid+1, r, k-Count);
}


void dfs(int u, int prnt, int lvl, int V) {
    // For Sparse Table
    level[u] = lvl;
    parent[u] = prnt;
    
    // Segment Tree
    if(prnt != -1)
        presis[u] = nCopy(presis[prnt]);
    update(presis[u], 1, V, Map[val[u]], 1);                // V or IDX??
    
    for(int i = 0; i < (int)G[u].size(); ++i)
        if(parent[u] != G[u][i])
            dfs(G[u][i], u, lvl+1, V);
}


void LCAinit(int V) {
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


int main() {
    //freopen("in", "r", stdin);
    int V, u, v, q, ans, k, LCAnode;

    fastIn(V), fastIn(q);
    
    for(int i = 1; i <= V; ++i) {
        fastIn(val[i]);
        Map[val[i]];
    }
    
    int idx = 0;
    
    // Normal Compress
    for(auto it = Map.begin(); it != Map.end(); ++it) {
        Map[it->first] = ++idx;
        ReMap[idx] = it->first;
    }    
    
    for(int i = 1; i < V; ++i) {
        fastIn(u), fastIn(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    null->lft = null;       // rewiring null itself
    null->rht = null;
    presis[1] = nCopy(presis[1]);
    dfs(1, -1, 0, idx);
    LCAinit(V);
    
    while(q--) {
        fastIn(u), fastIn(v), fastIn(k);
        LCAnode = LCA(u, v);
        
        ans = query((sparse[LCAnode][0] == -1 ? null:presis[sparse[LCAnode][0]]), presis[LCAnode] , presis[u], presis[v], 1, idx, k);
        printf("%d\n", ReMap[ans]);
    }
    
    return 0;
}
