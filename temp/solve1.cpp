#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

typedef long long ll;

int in[MAX], out[MAX], lvl[MAX], par[MAX][21], cnt;
vector<int>G[MAX];

// Can generate LCA of a set of nodes
// Can Also calculate the Spanning Path (connected total distance) of the nodes
// must do dfs first, generate dfs in out time, and generate sparse table parent 'par'

struct LCATree {
    int tree[MAX*4], lca, n, cost;
    set<int>nodes;

    void init(int sz) { n = sz, lca = -1, cost = 0; }
    void update(int pos, int l, int r, int idx, int v) {
        if(l == r) {
            tree[pos] += v;
            return;
        }
        int mid = (l+r)>>1;
        if(idx <= mid)  update(pos<<1, l, mid, idx, v);
        else            update(pos<<1|1, mid+1, r, idx, v);
        tree[pos] = tree[pos<<1] + tree[pos<<1|1];
    }
    int query(int pos, int l, int r, int L, int R) {
        if(r < L or R < l)      return 0;
        if(L <= l and r <= R)   return tree[pos];
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R);
    }
    int getPar(int u, int p) {
        for(int i = 20; i >= 0; --i)
            if(p & (1 << i))
                u = par[u][i];          // parent sparse table
        return u;
    }
    int LCA() {
        int u = *nodes.begin(), tot = nodes.size(), v, ret = *nodes.begin();
        int lo = 0, hi = lvl[u]-1;
        while(lo <= hi) {
            int mid = (lo+hi)>>1;
            v = getPar(u, mid);
            if(query(1, 1, n, in[v], out[v]) == tot)
                hi = mid-1, ret = v;            // in : dfs in time
            else                                // out : dfs out time
                lo = mid+1;
        }
        return ret;
    }
    int findChainPar(int u, int t) {                // finds parent node of u having 
        int lo = 0, hi = lvl[u]-1, ret = u, v, mid; // active child node more than t
        while(lo <= hi) {
            mid = (lo+hi)>>1;
            v = getPar(u, mid);
            if(query(1, 1, n, in[v], out[v]) > t)
                hi = mid-1, ret = v;
            else
                lo = mid+1;
        }
        return ret;
    }
    void addNode(int u) {
        int pstLca = lca;
        nodes.insert(u), update(1, 1, n, in[u], 1);
        if(lca == -1) {
            lca = u;
            return;
        }
        else
            lca = LCA();
        // if new LCA is same but the new node is on different chain
        if(pstLca == lca and query(1, 1, n, in[u], out[u]) == 1) {
            int v = findChainPar(u, 1);
            cost += lvl[u] - lvl[v];
        }
        // if new LCA changes, newLCA will always be upper from past LCA
        // also the node u is on different chain
        else if(lca != pstLca)
            cost += lvl[u] + lvl[pstLca] - 2*lvl[lca];
    }
    void removeNode(int u) {
        int pstLca = lca;
        nodes.erase(u), update(1, 1, n, in[u], -1);
        if(nodes.empty()) {
            lca = -1, cost = 0;
            return;
        }
        else
            lca = LCA();
        if(pstLca == lca and query(1, 1, n, in[u], out[u]) == 0) {
            int v = findChainPar(u, 0);
            cost -= lvl[u] - lvl[v];
        }
        else if(lca != pstLca)
            cost -= lvl[lca] + lvl[u] - 2*lvl[pstLca];
}};

void dfs(int u, int p) {
    in[u] = ++cnt;
    par[u][0] = p, lvl[u] = lvl[p]+1;
    
    for(int i = 1; i <= 20; ++i)
        par[u][i] = par[par[u][i-1]][i-1];
    
    for(auto v : G[u])
        if(v != p)
            dfs(v, u);
    out[u] = cnt;
}

LCATree tree;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, u, v;
    cin >> n >> k;
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    tree.init(n);

    int l = 1, r = 0, ans = 0;
    --k;

    while(++r <= n) {
        tree.addNode(r);
        while(tree.cost > k and l < r)
            tree.removeNode(l++);
        if(tree.cost <= k)
            ans = max(ans, r-l+1);
    }

    cout << ans << endl;

    return 0;
}