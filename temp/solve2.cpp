#include <bits/stdc++.h>
#define MAX 100

using namespace std;

vector<int>G[MAX];
int sparse[MAX][20], parent[MAX], level[MAX], nextNode[MAX], chain[MAX], num[MAX], val[MAX], numToNode[MAX], top[MAX], ChainSize[MAX], mx[MAX];
int ChainNo = 1, all = 1, n;

void dfs(int u, int par, int lvl) {
    level[u] = lvl;
    parent[u] = par;
    
    for(auto v : G[u]) {
        // any way to take these values??
        dfs(v, u, lvl+1);
    }
}


void LCAinit(int V) {
    // DFS first
    memset(parent, -1, sizeof parent);
    
    // Main initialization of sparse table LCA starts here
    memset(sparse, -1, sizeof sparse);
    
    for(int u = 1; u <= V; ++u)                 // node u's 2^0 parent
        sparse[u][0] = parent[u];
    
    int v;
    for(int p = 1; (1<<p) <= V; ++p)
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
    
    //cout << "lcs:: " << parent[u] << endl;
    return parent[u];
}

int main() {
    
    
    int n, m, q, u, v, x;
    
    cin >> n >> m >> q;
    
    for(int i = 0; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    memset(val, -1, sizeof val);
    
    for(int i = 1; i <= m; ++i) {
        cin >> x;
        val[i] = x;
    }
    
    dfs(1, -1, 0);
    
    return 0;
}
