// LightOJ
// 1094 - Farthest Nodes in a Tree

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pii;

vector<int>G[30010], W[30010];

pii dfs(int u, int par, int d) {
    pii ret(d, u);                                      // {distance, node}
    for(int i = 0; i < (int)G[u].size(); ++i)
        if(G[u][i] != par)
            ret = max(ret, dfs(G[u][i], u, d+W[u][i]));
    return ret;
}

int main() {
    int t, n, u, v, w;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        
        for(int i = 1; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(v);
            G[v].push_back(u);
            W[u].push_back(w);
            W[v].push_back(w);
        }
        
        pii left = dfs(0, -1, 0);
        pii right = dfs(left.second, -1, 0);
        printf("Case %d: %d\n", Case, right.first);
        
        for(int i = 0; i < n; ++i)
            G[i].clear(), W[i].clear();
    }
    return 0;
}
