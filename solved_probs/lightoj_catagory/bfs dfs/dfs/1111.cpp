// LightOJ
// 1111 - Best Picnic Ever

#include <bits/stdc++.h>
using namespace std;

vector<bitset<101> >vis;
vector<int>G[1001];
int k[101];

void dfs(int u, int idx) {
    vis[u-1][idx] = 1;
    for(int i = 0; i < (int)G[u].size(); ++i)
        if(!vis[G[u][i]-1][idx])
            dfs(G[u][i], idx);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, K, V, E, u, v;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d", &K, &V, &E);
        
        for(int i = 0; i < K; ++i)
            scanf("%d", &k[i]);
        
        for(int i = 0; i < E; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        
        vis.clear();
        vis.resize(V, 0);
        
        for(int i = 0; i < K; ++i)
            dfs(k[i], i);
        
        int cnt = 0;
        for(int i = 0; i < V; ++i)
            if((int)vis[i].count() == K)
                ++cnt;
        
        printf("Case %d: %d\n", Case, cnt);
        
        for(int i = 0; i <= V; ++i)
            G[i].clear();
    }
    return 0;
}
