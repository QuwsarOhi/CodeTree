#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int par, int lvl) {                 // Tracks distance as well (From root 1 to all nodes)
    level[u] = lvl;                                 // parent[] and level[] is necessary
    parent[u] = par;                                
    
    for(auto v : G[u])
        if(parent[u] != v)
            dfs(v, u, lvl+1);
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

void MERGE(vector<int>&u, vector<int>&v) {
    for(auto it : v)
        u.push_back(it);
    
    sort(u.begin(), u.end(), greater<int>);
    
    while(u.back())
        u.pop_back();
}

int main() {
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &V, &q);
        
        W[0] = 1;
        for(int u = 1; u <= V; ++u) {
            scanf("%d%d", &v, &w);
            G[u].push_back(v);
            W[v] = w;
        }
    }
