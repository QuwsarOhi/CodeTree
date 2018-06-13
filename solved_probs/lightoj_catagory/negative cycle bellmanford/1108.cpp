// LightOJ
// 1108 - Instant View of Big Bang

#include <bits/stdc++.h>
#define MAX 1009
#define INF 1e8
using namespace std;

vector<int>G[MAX], W[MAX];
int V, E, dist[MAX];
void bellmanFord(int source) {
    for(int i = 0; i <= V; i++)                             // set to -INF if max distance is needed
        dist[i] = INF;
    dist[source] = 0;
    for(int i = 0; i < V-1; i++)                            // relax all edges V-1 times
        for(int u = 0; u < V; u++) {                         // all the nodes
            for(int j = 0; j < (int)G[u].size(); j++) {
                int v = G[u][j];
                int w = W[u][j];            // relax edges, set to max if max value needed
                if(dist[u] != INF)          // if there is a negative weight, then INF + negative weight < INF and INF becomes +-INF
                    dist[v] = min(dist[v], dist[u]+w);
            }
        }
}

bool vis[MAX][2];
void negativePoint(int u) {                         // Works in undirected graph
    queue<pair<int, bool> >q;                       // if vis[v][1] == 1 then there exists an negative cycle
    q.push(make_pair(u, 0));                        // vis[v]][1] is true for all nodes which are in negative cycle and
    memset(vis, 0, sizeof vis);                     // the nodes that can be reached from the negative cycle nodes
    vis[u][0] = 1;                                  // on one/more path from u to v
    while(!q.empty()) {
        u = q.front().first;
        bool neg = q.front().second;
        q.pop();
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            int w = W[u][i];
            if(dist[v] > dist[u] + w)
                neg = 1;
            if(vis[v][neg])
                continue;
            vis[v][neg] = 1;
            q.push(make_pair(v, neg));
}}}

int main() {
    int t, u, v, w;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &V, &E);
        ++V;
        
        for(int i = 0; i < E; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            ++u, ++v;
            G[v].push_back(u);                  // Reverse Graph
            W[v].push_back(w);
        }
        
        for(int i = 1; i < V; ++i)                  // Virtual Source
            G[0].push_back(i), W[0].push_back(0);
        
        bellmanFord(0);
        negativePoint(0);
        
        printf("Case %d:", Case);
        bool found = 0;
        for(int i = 1; i < V; ++i)
            if(vis[i][1]) {
                found = 1;
                printf(" %d", i-1);
            }
        if(!found) printf(" impossible");
        printf("\n");
        
        for(int i = 0; i <= V; ++i)
            G[i].clear(), W[i].clear();
    }
    return 0;
}
