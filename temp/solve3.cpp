#include <bits/stdc++.h>
#define INF 1e7
using namespace std;

int W[55][55], T[55][55], C[60000], dp[55], n, t;
bitset<55>vis;

int dfs(int u, int Cost, int Time) {
    if(Time >= t)
        return INF;
    
    if(u == n-1) {
        C[Cost] = min(Time, C[Cost]);
        return 0;
    }
    
    if(dp[u] != -1)
        return dp[u];
    
    int ret = INF;
    for(int v = 0; v < n; ++v)
        if(!vis[v]) {
            cout << "FROM " << u << " TO " << v << endl;
            vis[v] = 1;
            ret = min(ret, dfs(v, Cost+W[u][v], Time+T[u][v])+W[u][v]);
            vis[v] = 0;
        }
        else
            cout << "SKIP FROM " << u << " TO " << v << endl;
    
    return dp[u] = ret;
}

int main() {
    
    while(scanf("%d%d", &n, &t) && n && t) {
    
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &W[i][j]);
    
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &T[i][j]);
        
        vis.reset();
        memset(dp, -1, sizeof dp);
        for(int i = 0; i <= 50000; ++i)
            C[i] = INF;
        
        vis[0] = 1;
        int cst = dfs(0, 0, 0);
        printf("%d %d\n", cst, C[cst]);
    }
    
    return 0;
}

