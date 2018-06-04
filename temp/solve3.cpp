// LightOJ
// 1074 - Extended Traffic

#include <bits/stdc++.h>
#define MAX 250
#define INF 1e16
using namespace std;

vector<int>G[MAX];
long long W[MAX], dist[MAX];
int V, E;

void bellmanFord(int source) {                      // Works in directed & undirected graph
    for(int i = 0; i < V; ++i)
        dist[i] = INF;
    dist[source] = 0;
    for(int i = 0; i < V-1; ++i)
        for(int u = 0; u < V; ++u)
            for(int j = 0; j < (int)G[u].size(); ++j) {
                int v = G[u][j];
                long long w = (W[v] - W[u]);
                w = w*w*w;
                if(dist[u] != INF)
                    dist[v] = min(dist[v], dist[u]+w);
            }
}

bool hasNegativeCycle() {                           // Works in directed graph
    for(int u = 0; u < V; ++u)
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            long long w = (W[v] - W[u]);
            w = w*w*w;
            if(dist[v] > dist[u] + w)
                return 1;
        }
    return 0;
}

bool vis[MAX][2];
void negativePoint(int u) {                         // Works in undirected graph
    queue<pair<int, bool> >q;                       // if vis[v][1] == 1 then there exists an negative cycle
    q.push(make_pair(u, 0));                        // on one/more path from u to v
    memset(vis, 0, sizeof vis);
    vis[u][0] = 1;
        
    while(!q.empty()) {
        u = q.front().first;
        bool neg = q.front().second;
        q.pop();
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            int w = W[v] - W[u];
            w = w*w*w;
            if(dist[v] > dist[u] + w)
                neg = 1;
            if(vis[v][neg])
                continue;
            vis[v][neg] = 1;
            
            q.push(make_pair(v, neg));
}}}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, q, u, v;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &V);
        for(int i = 0; i < V; ++i)
            scanf("%lld", &W[i]);
        
        scanf("%d", &E);
        for(int i = 0; i < E; ++i) {
            scanf("%d%d", &u, &v);
            --u, --v;
            G[u].push_back(v);
        }
        
        bellmanFord(0);
        negativePoint(0);
        scanf("%d", &q);
        printf("Case %d:\n", Case);
        while(q--) {
            scanf("%d", &v);
            --v;
            if(vis[v][1] || dist[v] < 3 || dist[v] == INF)
                printf("?\n");
            else
                printf("%lld\n", dist[v]);
        }
        
        for(int i = 0; i < V; ++i)
            G[i].clear();
    }
    
    return 0;
}

