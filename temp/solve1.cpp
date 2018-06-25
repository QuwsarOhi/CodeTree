// LightOJ
// 1128 - Greatest Parent

#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

vector<int> G[MAX];
int level[MAX], parent[MAX], sparse[MAX][20], W[MAX];

void dfs(int u, int par, int lvl) {             // Tracks distance as well (From root 1 to all nodes)
    level[u] = lvl;                                 // parent[] and level[] is necessary
    parent[u] = par;                                
    
    for(int i = 0; i < (int)G[u].size(); ++i)
        if(parent[u] != G[u][i])
            dfs(G[u][i], u, lvl+1);
}

void LCAinit(int V) {
    memset(parent, -1, sizeof parent);
    dfs(0, -1, 0);                               // DFS first
    memset(sparse, -1, sizeof sparse);              // Main initialization of sparse table LCA starts here
    for(int u = 1; u <= V; ++u)                     // node u's 2^0 parent
        sparse[u][0] = parent[u];
    
    for(int p = 1, v; (1LL<<p) <= V; ++p)
        for(int u = 0; u < V; ++u)
            if((v = sparse[u][p-1]) != -1)          // node u's 2^x parent = parent of node v's 2^(x-1) [ where node v : (node u's 2^(x-1) parent) ]
                sparse[u][p] = sparse[v][p-1];
}


int Query(int u, int cost) {
    for(int p = ceil(log2(level[u])); p >= 0; --p)
        if(sparse[u][p] != -1 && W[sparse[u][p]] >= cost) {      // W[u] contains weight of node u
            u = sparse[u][p];
    return u;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, n, q, v, w;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &q);
        
        for(int u = 1; u < n; ++u) {
            scanf("%d%d", &v, &w);
            G[u].push_back(v);
            G[v].push_back(u);
            W[u] = w;
        }
        
        W[0] = 1;
        LCAinit(n);
        
        printf("Case %d:\n", Case);
        while(q--) {
            scanf("%d%d", &v, &w);
            printf("%d\n", Query(v, w));
        }
        
        for(int i = 0; i <= n; ++i) G[i].clear();
    }
    return 0;
}
        
        
