// UVa
// 103 - Stacking Boxes

#include <bits/stdc++.h>
using namespace std;

int dp[1009], par[1009], n, d, V[1009][32];
bitset<1009>vis;

bool canGo(int u, int v) {
    for(int i = 0; i < d; ++i)
        if(V[u][i] >= V[v][i])
            return 0;
    return 1;
}

int dfs(int u) {
    if(dp[u] != -1)
        return dp[u];
    
    vis[u] = 1;
    for(int i = 0; i < n; ++i)
        if(not vis[i] and canGo(u, i))
            if(dp[u] < dfs(i)) {
                dp[u] = dfs(i);
                par[u] = i;
            }
    vis[u] = 0;
    
    if(dp[u] == -1)
        return dp[u] = 1;
    return ++dp[u];
}

void nodePrint(int u, bool first = 1) {
    if(u == -1)
        return;
    if(!first) printf(" ");
    
    printf("%d", u+1);
    nodePrint(par[u], 0);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    while(scanf("%d%d", &n, &d) == 2) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < d; ++j)
                scanf("%d", &V[i][j]);
            sort(V[i], V[i]+d);
        }
        
        memset(dp, -1, sizeof dp);
        memset(par, -1, sizeof par);
        
        int mx = -1, node;
        for(int i = 0; i < n; ++i) 
            if(mx < dfs(i)) {
                mx = dfs(i);
                node = i;
            }
        
        printf("%d\n", mx);
        nodePrint(node);
        printf("\n");
    }
    return 0;
}
