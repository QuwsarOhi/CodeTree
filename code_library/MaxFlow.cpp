// MaxFlow
// Ford-Fulkerson
// Complexity: O(VE^2)
// Graph Type : Directed/Undirected

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
    while((bfs(s, d))) {
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

int main() {
    int u, v, w, source, destination, Case = 1;
    map<pair<int, int>, bool>Map;
    while(scanf("%d", &V) && V) {
        scanf("%d%d%d", &source, &destination, &E);
        memset(rG, 0, sizeof rG);
        for(int i = 0; i < E; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            rG[u][v] += w;                          // edges are undirected
            rG[v][u] += w;                          // remove this line if edges are directed
            if(Map.find({u, v}) == Map.end()) {             // same edges might occur more than once
                edge[u].push_back(v);                       // to avoid n^2 calculation
                edge[v].push_back(u);
                Map[{u, v}] = Map[{v, u}] = 1;
        }}
        printf("Network %d\n", Case++);
        printf("The bandwidth is %d.\n\n", maxFlow(source, destination));

        for(int i = 0; i <= V; ++i) edge[i].clear();
        Map.clear();
    }
    return 0;
}
