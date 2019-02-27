#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

int cnt = 0, lvl[MAX], par[MAX][22], in[MAX], out[MAX], revIn[MAX];
vector<int>G[MAX];

void dfs(int u, int p) {
    lvl[u] = lvl[p]+1;
    in[u] = ++cnt;
    revIn[cnt] = u;
    par[u][0] = p;
    for(int i = 1; i <= 20; ++i)
        par[u][i] = par[par[u][i-1]][i-1];
    for(auto v : G[u])
        if(v != p)
            dfs(v, u);
    out[u] = cnt;
}

int LCA(int u, int v) {
    if(lvl[u] < lvl[v]) swap(u, v);
    for(int p = 20; p >= 0; --p)
        if(lvl[u] - (1 << p) >= lvl[v])
            u = par[u][p];
    if(u == v) return u;
    for(int p = 20; p >= 0; --p)
        if(par[u][p] != par[v][p])
            u = par[u][p], v = par[v][p];
    return par[u][0];
}

// Can Give Total Spanning Tree edges for an particular set of nodes

set<int>nodes;                  // contains nodes according to dfs order
int nodeCost(int u) {           // returns node Query/Insert updated distance    
    auto it = nodes.insert(in[u]).first;        // inserted according to dfs in-timing
    auto l = it, r = it;                        // iterator of the inserted index
    if(it == nodes.begin())
        l = --nodes.end();
    else --l;
    
    if(it == --nodes.end())
        r = nodes.begin();
    else ++r;
    
    int L = revIn[*l], R = revIn[*r];     // nodes are retrieved from dfs in-timing 
    
    // dst is the spanning distance if the new node is added
    int dst = lvl[u] + lvl[LCA(L, R)] - lvl[LCA(u, L)] - lvl[LCA(u, R)];
    return dst;
}

void removeNode(int u) {
    nodes.erase(in[u]);
}

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

    int l = 1, r = 0, ans = 0, tot = 0;
    --k;

    while(++r <= n) {
        tot += nodeCost(r);
        //cerr << "Inserted " << r << endl;
        //cerr << "NEW cost " << tot << endl;

        while(tot > k and l < r) {
            tot -= nodeCost(l);
            removeNode(l);
            //cerr << "Removed " << l << " new cost " << tot << endl;
            ++l;
        }

        if(tot <= k)
            ans = max(ans, r-l+1);
    }

    cout << ans << endl;
    return 0;
}