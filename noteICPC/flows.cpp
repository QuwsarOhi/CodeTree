Flows:
	* Vertex Cover
	* Bipartite Matching
	* Max flow
	* Min cost max flow

/* Vertex Cover
 In the mathematical discipline of graph theory, a vertex cover (sometimes node cover) of a 
 graph is a set of vertices such that each edge of the graph is incident to at least one vertex
* Edge Cover
In graph theory, an edge cover of a graph is a set of edges such that every vertex of the graph 
is incident to at least one edge of the set  Min Edge Cover = TotalNodes - MinVertexCover */
bitset<MAX>vis;
int lft[MAX], rht[MAX];
vector<int>G[MAX];
int VertexCover(int u) {                    // Min Vertex Cover
    vis[u] = 1;
    for(auto v : G[u]) {
        if(vis[v]) continue;                // If v is used earlier, skip
		vis[v] = 1;
        if(lft[v] == -1) {                  // If there is no node present on left of v
            lft[v] = u, rht[u] = v;			// If there is one node present on the left
            return 1;				        // side of v (Let it be u') and if it is possible
        } else if(VertexCover(lft[v])) {    // to match u' with another node (not v ofcourse!)  
            lft[v] = u, rht[u] = v;         // then we can match this u with v, and u' is
            return 1;                       // matched with another node as well
    }} return 0;
} int BPM(int n) {                          // Bipartite Matching
    int cnt = 0;
    memset(lft, -1, sizeof lft), memset(rht, -1, sizeof rht);
    for(int i = 1; i <= n; ++i) {           // Nodes are numbered from 1 to n
        vis.reset();
        cnt += VertexCover(i);              // Check if there exists a match for node i
    } return cnt;
}
/* ----------------------------- MaxFlow (Directed/Undirected) -------------------------------
   Ford-Fulkerson
   Complexity: O(VE^2) */
const int MAX = 120;
vector<int>edge[MAX];
int V, E, rG[MAX][MAX], parent[MAX];
bool bfs(int s, int d) {                // augment path : source, destination
    memset(parent, -1, sizeof parent);
    queue<int>q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : edge[u])
            if(parent[v] == -1 && rG[u][v] > 0) {                
                parent[v] = u;
                if(v == d) return 1;
                q.push(v);
    }}
    return 0;
} int maxFlow(int s, int d) {             // source, destination
    int max_flow = 0;
    while(bfs(s, d)) {
        int flow = INT_MAX;
        for(int v = d; v != s; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, rG[u][v]);
        } for(int v = d; v != s; v = parent[v]) {
            int u = parent[v];
            rG[u][v] -= flow, rG[v][u] += flow;
        } max_flow += flow;
    } return max_flow;
} void AddEdge(int u, int v, int w) {
	edge[u].push_back(v), edge[v].push_back(u);
	rG[u][v] += w, rG[v][u] += w;
}
/* ------------------------- Min Cost Max Flow (Directed/Undirected) -------------------------
   Edmonds-Karp relabelling + Dijkstra
   Complexity : O(V*V*flow) */
vi G[MAX];
int cost[MAX][MAX], cap[MAX][MAX], dist[MAX], parent[MAX];
bitset<MAX>vis;
bool Dikjstra(int src, int sink) {
	queue<int>q;
	memset(dist, INF, sizeof dist);
	vis.reset(), q.push(src), vis[src] = 1, dist[src] = 0;	 // dist[u] : contains minimum cost
	while(!q.empty()) {
		int u = q.front();
		q.pop(), vis[u] = 0;			   // node u is processed and poped out, so set vis = 0
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i], w = dist[u] + cost[u][v];
			if(cap[u][v] > 0 and dist[v] > w) {		// if capacity exists and can minimize cost
				dist[v] = w, parent[v] = u;
				if(not vis[v]) { q.push(v), vis[v] = 1; }    // check if node v is not in queue
	}}}	return dist[sink] != INF;	   // this check is because we might insert same node twice	
} int MinCostFlow(int src, int sink, int &max_flow) {		   // Returns min cost and max flow
	int flow, min_cost = 0;
	max_flow = 0;
	while(Dikjstra(src, sink)) {						// Max flow does bfs
		flow = INF;
		for(int v = sink; v != src; v = parent[v]) {
			int u = parent[v], flow = min(flow, cap[u][v]);
		} for(int v = sink; v != src; v = parent[v]) {
			int u = parent[v];
			cap[u][v] -= flow, cap[v][u] += flow, cost[v][u] = -cost[v][u];
		} min_cost += dist[sink]*flow, max_flow += flow;	               // cost of this flow 
	} return min_cost;										 // flow = total_cost * actual_flow
} void AddEdge(int u, int v, int _capacity, int _cost) {		   // Assuming undirected graph
	G[u].push_back(v), G[v].push_back(u);					
	cost[u][v] = cost[v][u] = _cost;						// Cost of edge u-v
	cap[u][v] = cap[v][u] = _capacity;						// Capacity of edfe u-v
}
