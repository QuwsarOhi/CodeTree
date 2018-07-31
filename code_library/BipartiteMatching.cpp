// Vertex Cover
// Wiki: Vertex Cover:
// In the mathematical discipline of graph theory, a vertex cover (sometimes node cover) 
// of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set
// Wiki: Edge Cover:
// In graph theory, an edge cover of a graph is a set of edges such that every vertex of the graph 
// is incident to at least one edge of the set

// Min Edge Cover = TotalNodes - MinVertexCover

bitset<MAX>vis;
int lft[MAX], rht[MAX];
vector<int>G[MAX];

int VertexCover(int u) {                    // Min Vertex Cover
    vis[u] = 1;
    for(int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) continue;                // If v is used earlier, skip
		vis[v] = 1;
        if(lft[v] == -1) {                  // If there is no node present on left of v
            lft[v] = u, rht[u] = v;
            return 1;
        }
        else if(VertexCover(lft[v])) {      // If there is one node present on the left side of v (Let it be u')
            lft[v] = u, rht[u] = v;         // and if it is possible to match u' with another node (not v ofcourse!)
            return 1;                       // then we can match this u with v, and u' is matched with another node as well
    }}
    return 0;
}
int BPM(int n) {                            // Bipartite Matching
    int cnt = 0;
    memset(lft, -1, sizeof lft);
    memset(rht, -1, sizeof rht);
    for(int i = 1; i <= n; ++i) {           // Nodes are numbered from 1 to n
        vis.reset();
        cnt += VertexCover(i);              // Check if there exists a match for node i
    }
    return cnt;
}
