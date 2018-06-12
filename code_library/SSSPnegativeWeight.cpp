//Single Source Shortest Path (Negative Cycle)
//Complexity : O(VE)


vector<int>G[MAX], W[MAX];
int V, E, dist[MAX];
void bellmanFord(int source) {              // If there exists disconnected graphs, then add a dummy source node which will 
    for(int i = 0; i <= V; i++)             // direct to all nodes with cost 0, and run bellmanFord from that virtual node
        dist[i] = INF;                      // set to -INF if max distance is needed
    dist[source] = 0;
    for(int i = 0; i < V-1; i++)                            // relax all edges V-1 times, if virtual node added, run V times
        for(int u = 0; u < V; u++)                          // all the nodes, if virtual node added, run within u <= V
            for(int j = 0; j < (int)G[u].size(); j++) {
                int v = G[u][j], w = W[u][j];               // relax edges, set to max if max value needed
                if(dist[u] != INF)                          // if there is a negative weight, then INF + negative weight < INF and INF becomes +-INF
                    dist[v] = min(dist[v], dist[u]+w);
}}

bool hasNegativeCycle() {
    for(int u = 0; u < V; u++)
        for(int i = 0; i < G[u].size(); i++) {      // if bellmanFord is run for max values, then this code will
            int v = G[u][i], w = W[u][i];           // return true for positive cycle by adding this line
            if(dist[v] > dist[u] + w)               // if(dist[v] < dist[u] + w)
                return 1;
        }
    return 0;
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
