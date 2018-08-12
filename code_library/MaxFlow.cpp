// MaxFlow (Directed/Undirected)
// Ford-Fulkerson
// Complexity: O(VE^2)

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
}
                
int maxFlow(int s, int d) {             // source, destination
    int max_flow = 0;
    while(bfs(s, d)) {
        int flow = INT_MAX;
        for(int v = d; v != s; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, rG[u][v]);
        }
        for(int v = d; v != s; v = parent[v]) {
            int u = parent[v];
            rG[u][v] -= flow;
            rG[v][u] += flow;
        }
        max_flow += flow;
    }
    return max_flow;
}

void AddEdge(int u, int v, int w) {
	edge[u].push_back(v), edge[v].push_back(u);
	rG[u][v] += w;
	rG[v][u] += w;
}

// Min Cost Max Flow (Directed/Undirected)
// Edmonds-Karp relabelling + Dijkstra
// Complexity : O(V*V*flow)

vi G[MAX];
int cost[MAX][MAX], cap[MAX][MAX], dist[MAX], parent[MAX];
bitset<MAX>vis;

bool Dikjstra(int src, int sink) {
	queue<int>q;
	for(int i = 0; i < MAX; ++i) 
		dist[i] = INT_MAX;
	vis.reset();
	q.push(src);
	vis[src] = 1, dist[src] = 0;					// dist[u] : contains minimum cost
	while(!q.empty()) {
		int u = q.front();
		q.pop(), vis[u] = 0;						// node u is processed and poped out, so set vis = 0
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i], w = dist[u] + cost[u][v];
			if(cap[u][v] > 0 and dist[v] > w) {		// if capacity exists and can minimize cost
				dist[v] = w;
				parent[v] = u;
				if(not vis[v])						// check if node v is not inserted in queue
					q.push(v), vis[v] = 1;			// this check is because we might insert same node twice
	}}}
	return dist[sink] != INT_MAX;
}

int MinCostFlow(int src, int sink, int &max_flow) {		// Returns min cost and max flow
	int flow, min_cost = 0;
	max_flow = 0;
	while(Dikjstra(src, sink)) {						// Max flow does bfs
		flow = INT_MAX;
		for(int v = sink; v != src; v = parent[v]) {
			int u = parent[v];
			flow = min(flow, cap[u][v]);
		}
		for(int v = sink; v != src; v = parent[v]) {
			int u = parent[v];
			cap[u][v] -= flow, cap[v][u] += flow;
			cost[v][u] = -cost[v][u];					// Extra part of MaxFlow
		}
		min_cost += dist[sink]*flow, max_flow += flow;	// cost of this flow = total_cost * actual_flow
	}
	return min_cost;
}

void AddEdge(int u, int v, int _capacity, int _cost) {		// Assuming undirected graph
	G[u].push_back(v), G[v].push_back(u);					//
	cost[u][v] = cost[v][u] = _cost;						// Cost of edge u-v
	cap[u][v] = cap[v][u] = _capacity;						// Capacity of edfe u-v
}
