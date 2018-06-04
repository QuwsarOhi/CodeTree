//Single Source Shortest Path (Negative Cycle)
//Complexity : O(VE)


vector<int>G[MAX], W[MAX];
int V, E, dist[MAX];
void bellmanFord(int source) {
    for(int i = 0; i <= V; i++)                             // set to -INF if max distance is needed
        dist[i] = INF;
    dist[source] = 0;
    for(int i = 0; i < V-1; i++)                            // relax all edges V-1 times
        for(int u = 0; u < V; u++)                          // all the nodes
            for(int j = 0; j < (int)G[u].size(); j++) {
                int v = G[u][j];
                int w = W[u][j];            // relax edges, set to max if max value needed
                if(dist[u] != INF)          // if there is a negative weight, then INF + negative weight < INF and INF becomes +-INF
                    dist[v] = min(dist[v], dist[u]+w);
            }
}

bool hasNegativeCycle() {
    for(int u = 0; u < V; u++)
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            int w = W[u][i];            // if bellmanFord is run for max values, then this code will return true for positive cycle by adding this line
            if(dist[v] > dist[u] + w)   // if(dist[v] < dist[u] + w)
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
            int w = W[u][i]
            if(dist[v] > dist[u] + w)
                neg = 1;
            if(vis[v][neg])
                continue;
            vis[v][neg] = 1;
            q.push(make_pair(v, neg));
}}}
