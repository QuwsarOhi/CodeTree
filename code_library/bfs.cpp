// Basic BFS with path printing 
// Complexity : O(V+E)

vector<int>parent, G[MAX];
void printPath(int u, int source_node) {
    if(u == source_node) {
        printf("%d", u);
        return;
    }
    printPath(parent[u], source_node);
    printf(" %d", u);
}

int BFS(int source_node, int finish_node, int vertices) {
    vector<int>dist(vertices+5, INF);               //contains the distance from source to end point
    queue<int>Q;
    Q.push(source_node);
    parent.resize(vertices+5, -1);                  //for path printing

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if(u == finish_node)                        //remove this line if shortest path to all nodes are needed
            return dist[u];
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                Q.push(v);
    }}}
    return -1;
}
