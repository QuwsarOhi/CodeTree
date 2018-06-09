// FISHER - Fishmonger
// DP

#include <bits/stdc++.h>
#define INF 100000000
#define MAX 55
using namespace std;
typedef pair<int, int>pii;

int TimeLim, n;
int W[MAX][MAX], T[MAX][MAX];
pii dp[MAX][1009];
bitset<MAX>vis;

pii dfs(int u, int Time) {
    if(Time > TimeLim)
        return {INF, INF};
    
    if(u == n-1)
        return pii(0, Time);            // Toll, Time
    
    if(dp[u][Time] != make_pair(INF, INF))
        return dp[u][Time];
        
    pii ret(INF, INF);
    for(int v = 0; v < n; ++v) {
        if(!vis[v]) {
            vis[v] = 1;
            
            pii tmp = dfs(v, Time+T[u][v]);
            tmp.first += W[u][v];
            ret = min(tmp, ret);
                        
            vis[v] = 0;
        }
    }
    
    return dp[u][Time] = ret;
}


int main() {
    while(scanf("%d%d", &n, &TimeLim) && n && TimeLim) {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &T[i][j]);          // Time
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &W[i][j]);          // Toll
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 1005; ++j)
                dp[i][j] = {INF, INF};
        
        vis[0] = 1;
        pii ans = dfs(0, 0);
        printf("%d %d\n", ans.first, ans.second);
    }
    
    return 0;
}
