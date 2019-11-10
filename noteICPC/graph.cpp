Graph:
 * Cycles in directed graph 
 * BFS with path printing
 * Bi-coloring with BFS
 * Shortest Paths:
        * Single Source Shortest Path - Dikjstra
                                        Kth Shortest Path
                                        Negative Cycle - Bellman Ford
        * All Pair Shortest Path - Floyd Warshal
        * Minimum Spanning Tree - Undirected MST [Prims, Kruskal]
                                - Directed MST [Edmond algorithm]
 * Articulation Point [Tarjan]
 * Bridge and Tree extraction from connected components
 * Strongly Connected Component [Tarjan]

/* -------------------------------- Cycle in Directed graph --------------------------------
   http://codeforces.com/contest/915/problem/D */
vi G[550];
int color[550], Cycle = 0;            // Cycle will contain the number of cycles found in graph
void dfs(int u) {
    color[u] = 2;                               // Mark as parent
    for(auto v : G[u]) {
        if(color[v] == 2)       Cycle++;        // If any Parent found (BackEdge)
        else if(color[v] == 0)  dfs(v);
    } color[u] = 1;                             // Mark as visited
}
/* ------------------------------- Basic BFS with path printing -------------------------------
   Complexity : O(V+E) */
vector<int>parent, G[MAX];
void printPath(int u, int source_node) {                                 // destination, source
    if(u == source_node) { printf("%d", u); return; }
    printPath(parent[u], source_node);
    printf(" %d", u);
} int BFS(int source_node, int finish_node, int vertices) {
    queue<int>Q;
    vector<int>dist(vertices+5, INF);                                        // distance vector
    Q.push(source_node), parent.resize(vertices+5, -1);   // parent vector is for path printing
    dist[source_node] = 0;
    while(not Q.empty()) {
        int u = Q.front();
        Q.pop();
        if(u == finish_node)  return dist[u];              // remove this line if shortest path
        for(int i = 0; i < G[u].size(); i++) {                       // to all nodes are needed
            int v = G[u][i];
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                parent[v] = u, Q.push(v);
    }}} return -1;
}
/* ------------------------------- Bi-coloring using BFS ------------------------------- */
int color[100];                         // Contains Color (1, 2)
void Bicolor(int u) {                   // Bicolor Check
    queue<int>q;
    q.push(u), color[u] = 1;            // Color is -1 initialized
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for(auto v : G[u]) {
            if(color[v] == -1) {
                color[u] = (color[u] == 1) ? 2:1, q.push(v);
}}}}
/* ------------------------------- Shortest Path (Dikjstra) -------------------------------
   Complexity : (V*logV + E) */
vector<int>dist, G[MAX], W[MAX];                    // distance, edge list, weight list
void dikjstra(int u, int destination, int nodes) {
    dist.resize(nodes+1, INF);                      
    dist[u] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0, -u});
    while(not pq.empty()) {
        int u = -pq.top().second, wu = -pq.top().first;     // node, weight sum
        pq.pop();
        if(u == destination) return;                        // if destination found, return
        if(wu > dist[u]) continue;                          // if weight is heavy, skip
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i], wv = W[u][i];                  // node, weight
            if(wu + wv < dist[v]) {                         // path relax
                dist[v] = wu + wv;
                p[v] = u;                                   // for path printing
                pq.push({-dist[v], -v});
}}}} void printPath(int u) {                                // path print for dikjstra
    if (u == s) {   printf("%d", s); return; } 
    printPath(p[u]);                     // recursive: to make the output format: s -> ... -> t
    printf(" %d", u);
}
/* Kth Path Using Modified Dikjstra
   Complexity : O(K*(V*logV + E))
   http://codeforces.com/blog/entry/16821 */
vector<int>G[MAX], W[MAX], dist[MAX];
int KthDikjstra(int Start, int End, int Kth) {     // Kth Shortest Path (Visits Edge Only Once)
    for(int i = 0; i < MAX; ++i)        dist[i].clear();
    priority_queue<pii>pq;                          // Weight, Node
    pq.push({0, Start});
    while(!pq.empty()) {
        int u = pq.top().second, w = -pq.top().first;
        pq.pop();
        if((int)dist[End].size() == Kth)        // We can also break if the Kth path is found
            return dist[End].back();
        if(dist[u].empty())                 dist[u].push_back(w);
        else if(dist[u].back() != w)        dist[u].push_back(w);   
        if((int)dist[u].size() > Kth)       continue;
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i], _w = w + W[u][i];
            if((int)dist[v].size() == Kth) continue;
            pq.push(make_pair(-_w, v));
    }} return -1;
}
/* Kth Shortest Path (Visits Same Edge More Than Once if required) */
int KthDikjstra(int Start, int End, int Kth) {      // 
    for(int i = 0; i < MAX; ++i) dist[i].clear();
    priority_queue<pii>pq;                              // Weight, Node
    pq.push(make_pair(0, Start));
    while(!pq.empty()) {
        int u = pq.top().second, w = -pq.top().first;
        pq.pop();
        if(dist[u].empty()) dist[u].push_back(w);
        else if(dist[u].back() != w) {         
            if((int)dist[u].size() < Kth)      dist[u].push_back(w);
            else if(dist[u].back() <= w)       continue;
            else {                     // we have to take this cost, and remove the greater one
                dist[u].push_back(w);
                sort(dist[u].begin(), dist[u].end());
                dist[u].pop_back();
        }} for(int i = 0; i < (int)G[u].size(); ++i) {
             int v = G[u][i], _w = w + W[u][i];
             pq.push(make_pair(-_w, v));
    }}
    if((int)dist[End].size() < Kth) return -1;
    return dist[End].back();
}
/* -------------------- Single Source Shortest Path (Negative Cycle) -------------------------
   Complexity : O(VE) */
vector<int>G[MAX], W[MAX];
int V, E, dist[MAX];
void bellmanFord(int source) {  
    for(int i = 0; i <= V; i++) dist[i] = INF;
    dist[source] = 0;
    for(int i = 0; i < V-1; i++)                                   // relax all edges V-1 times
        for(int u = 0; u < V; u++)
            for(int j = 0; j < (int)G[u].size(); j++) {
                int v = G[u][j], w = W[u][j];
                if(dist[u] != INF)                           
                    dist[v] = min(dist[v], dist[u]+w);
}} bool hasNegativeCycle() {                           // if bellmanFord is run for max values,
    for(int u = 0; u < V; u++)                         // then this code will return true for 
        for(int i = 0; i < G[u].size(); i++) {         // positive cycle by adding this line
            int v = G[u][i], w = W[u][i];              // if(dist[v] < dist[u] + w)
            if(dist[v] > dist[u] + w) return 1;
        } return 0;
} bool vis[MAX][2];
void negativePoint(int u) {            // Works in undirected graph
    queue<pair<int, bool> >q;          // if vis[v][1] == 1 then there exists an negative cycle
    q.push(make_pair(u, 0));           // vis[v]][1] is true for all nodes which are 
    memset(vis, 0, sizeof vis);        // in negative cycle and the nodes that can be reached 
    vis[u][0] = 1;                     // from the negative cycle nodes on one/more 
    while(!q.empty()) {                // path from u to v
        u = q.front().first;
        bool neg = q.front().second;
        q.pop();
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i], w = W[u][i];
            if(dist[v] > dist[u] + w)   neg = 1;
            if(vis[v][neg])             continue;
            vis[v][neg] = 1;
            q.push(make_pair(v, neg));
}}}
/* ------------------------ All Pair Shortest Path - Floyd Warshal ---------------------------
   Complexity : O(V^3) */
int G[MAX][MAX], parent[MAX][MAX];
void graphINIT() {
    memset(G, INF, sizeof G);
    for(int i = 0; i < MAX; i++) G[i][i] = 0;
} void floydWarshall(int V) {
    for(int i = 0; i < V; i++)      // path printing matrix initialization
        for(int j = 0; j < V; j++)
            parent[i][j] = i;         // we can go to j from i by only obtaining i (by default)
    for(int k = 0; k < V; k++)          // Selecting a middle point as k and all combination of
        for(int i = 0; i < V; i++)                              // source(i) and destination(j)
            for(int j = 0; j < V; j++)
                if(G[i][k] != INF && G[k][j] != INF) {          // if G[i][i] = negative, then 
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);    // node i is in negative circle
                    parent[i][j] = parent[k][j];                // if path printing needed
}} void printPath(int i, int j) {
    if(i != j) printPath(i, parent[i][j]);
    printf(" %d", j);
} void minMax(int V) {                                   // maximum weight of minimum cost path
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
} void transitiveClosure(int V) {                  // Checks if there exists a path from i to j
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                G[i][j] |= (G[i][k] & G[k][j]);
}
/* --------------------- MST Kruskal + Union Find Disjoint Set (DSU) -------------------------
   Complexity of MST : O(E logV) */
set<pair<int, pair<int, int> > >Edge;                                         // USED STL SET!!
int MST(int V) {
    int mstCost = 0, edge = 0;                     // If Edge list is STL vector, then sort it!
    DSU U(V+5);
    set<pair<int, pair<int, int> > > :: iterator it = Edge.begin(); //Contains:{Weight, {U, V}}
    for( ; it != Edge.end() && edge < V; ++it) {
        int u = (*it).second.first, v = (*it).second.second, w = (*it).first;
        if(!U.isSameSet(u, v)) 
            ++edge, mstCost += w, U.makeUnion(u, v);
    } if(edge != V-1) 
        return -1;              // Some edge is missing, so no MST found!
    return mstCost;
}
/* ---------------------- Minimum Spanning Tree - Prim's Algorithm ---------------------------
   Complexity : O(E logV) */
vector<int> G[MAX], W[MAX];
priority_queue<pair<int, int> >pq;
bitset<MAX>taken;
void process(int u) {
    taken[u] = 1;
    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i], w = W[u][i];
        if(!taken[v]) pq.push(make_pair(-w, -v));
}} int main() {
    taken.reset(), process(0);              // taking 0 node as default
    int mst_cost = 0;
    while(!pq.empty()) {
        w = -pq.top().first, v = -pq.top().second;
        pq.pop();                               // if the node is not taken, then use this node
        if(!taken[v]) mst_cost += w, process(v);             // as it contains the minimum edge
    } printf("Prim's MST cost : %d\n", mst_cost);
    return 0;
}
/* ----------------- Directed Minimum Spanning Tree (Edmonds' algorithm) ---------------------
  Complexity : O(E*V) ~ O(E + VlogV)            [ works in O(E + VlogV) for almost all cases ]
  https://en.wikipedia.org/wiki/Edmonds%27_algorithm */
struct edge {
    int u, v, w;
    edge() {}
    edge(int a,int b,int c) : u(a), v(b), w(c) {}
};
int DMST(vector<edge> &edges, int root, int V) {
    int ans = 0, cur_nodes = V;
    while(true) {                            // lo[v] : contains minimum weight to go to node v
        vector<int> lo(cur_nodes, INF), pi(cur_nodes, INF);     
        for(int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if(w < lo[v] and u != v)
                lo[v] = w, pi[v] = u;
        } lo[root] = 0;                        // by default the weight to go to root node is 0
        for(int i = 0; i < (int)lo.size(); ++i) {
            if(i == root) continue;
            if(lo[i] == INF) return -1;                           // Directed MST doesn't exist
        } int cur_id = 0;
        vector<int> id(cur_nodes, -1), mark(cur_nodes, -1);
        for(int i = 0; i < cur_nodes; ++i) {
            ans += lo[i];                           // Adding node i's minimum weight to answer
            int u;
            for(u = i; u != root && id[u] < 0 && mark[u] != i; u = pi[u])
                mark[u] = i;
            if(u != root && id[u] < 0) { 
                for(int v = pi[u]; v != u; v = pi[v])           // mark all cycle nodes with id
                    id[v] = cur_id;
                id[u] = cur_id++;                                   
        }} if(cur_id == 0) break;                             // all nodes are possibly visited
        for(int i = 0; i < cur_nodes; ++i)
            if(id[i] < 0) id[i] = cur_id++;
        for(int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i].u, v = edges[i].v;
            edges[i].u = id[u];
            edges[i].v = id[v];
            if(id[u] != id[v]) edges[i].w -= lo[v];
        }
        cur_nodes = cur_id, root = id[root];
    } return ans;                                                  // returns total cost of MST
}
/* ------------------------------- Articulation Point -------------------------------
   Complexity O(V+E)
   Tarjan, DFS Timing
   1 : if dfs_num[u] == dfs_low[v], then it is a back edge
   2 : if dfs_num[u] < dfs_low[v], then u is ancestor of v and there is no back edge
   so, if u is not root node, then we can chose u for Articulation Point */
vector<int>G[101];
int dfs_num[101], dfs_low[101], parent[101], isAtriculationPoint[101];
int dfsCounter, rootChildren, dfsRoot;
void articulationPoint(int u) {
    dfs_low[u] = dfs_num[u] = ++dfsCounter;
    for(auto v : G[u]) {
        if(dfs_num[v] == 0) {
            parent[v] = u;                           // Special case for root node, if root
            if(u == dfsRoot) rootChildren++;         // node has child, increment counter
            articulationPoint(v);
            if(dfs_num[u] <= dfs_low[v] && u != dfsRoot)                 // Avoiding root node
                isArticulationPoint[u]++;
            dfs_low[u] = min(dfs_low[v], dfs_low[u]);
        } else if(parent[u] != v) 
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}} int main() {
    dfsCounter = 0, memset(dfs_num, 0, sizeof(dfs_num)), isArticulationPoint.reset();
    for(int i = 1; i <= n; i++) {
        if(dfs_num[i] == 0) {
            dfsCounter = rootChildren = 0, dfsRoot = i;
            articulationPoint(i);
            isArticulationPoint[i] += (rootChildren > 1);
    }}                        // isAtriculationPoint + 1 = number of nodes that is disconnected
    for(int i = 0; i < 101; i++)                                // Printing Articulation Points
        if(isArticulationPoint[i]) printf("%d ", i);
    printf("%d\n", (int)isArticulationPoint.count());
}

/* ----------------------------------------- Bridge -----------------------------------------
   Complexity : O(V+E) */
vector<int> G[MAX];
vector<pair<int, int> >ans;
int dfs_num[MAX], dfs_low[MAX], dfsCounter, timeToNode[MAX];
void bridge(int u, int par = -1) {
    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    timeToNode[dfs_num[u]] = u;                     // For building new tree from current graph
    for(auto v : G[u]) {
        if(v == par) continue;
        if(dfs_num[v] == 0) {
            bridge(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if(dfs_num[u] < dfs_low[v])
                ans.push_back(make_pair(min(u, v), max(u, v)));
        } else if(v != par) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
    timeToNode[dfs_num[u]] = u;                  // If BuildNewTree is used otherwise ignore it
} void FindBridge(int V){                                                // Bridge finding code
    memset(dfs_num, 0, sizeof(dfs_num)), dfsCounter = 0;
    for(int i = 0; i < V; i++) if(dfs_num[i] == 0) bridge(i);
}
// Make tree from the above found connected components
vi Tree[MAX];
int conv[MAX] = {0}, ncnt;
int Convert(int u) {                                // Converts graph node number to
    if(conv[dfs_low[u]] == 0)                       // tree numbers
        conv[dfs_low[u]] = ++ncnt;                  // tree nodes start from 1
    return conv[dfs_low[u]];                             // ncnt contains total number of nodes 
} int findMin(int u) {                          // Basic tarjan doesn't contain same dfs_low[u]
    if(dfs_low[u] == dfs_num[u]) return dfs_low[u];                           // for all nodes, 
    return dfs_low[u] = findMin(timeToNode[dfs_low[u]]);     // so this finds the actual values
} int BuildNewTree(int V) {
    ncnt = 0;
    for(int i = 1; i <= V; ++i)  findMin(i);
    for(auto it : ans) {
        int u = Convert(it.first), v = Convert(it.second);
        Tree[u].pb(v),Tree[v].pb(u);
    } return ncnt;
}

/* -------------------------- Strongly Connected Component (Tarjan) ---------------------------
   Complexity : O(V+E) */
vector<int>G[MAX], SCC;
int dfs_num[MAX], dfs_low[MAX], dfsCounter, SCC_no = 0;
bitset<MAX>visited;
map<int, int>Component;                          // For Creating new SCC (ConnectNode function)
void tarjanSSC(int u) {
    SCC.push_back(u), visited[u] = 1, dfs_num[u] = dfs_low[u] = ++dfsCounter;
    for(auto v : G[u]) {
        if(dfs_num[v] == 0)     tarjanSSC(v);
        if(visited[v])          dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } if(dfs_low[u] == dfs_num[u]) {
        SCC_no++;                                          // Component Node no. starts from 0
        bool first = 1;
        while(1) {
            int v = SCC.back();
            SCC.pop_back(), visited[v] = 0;
            // printf("%d\n", v);       // v is strongly connected in this component
            Component[v] = SCC_no;      // Marking SCC nodes to as same component
            if(u == v) break;
        }
}} void ConnectNode() {             // This function can convert Components to a new graph (G1)
    map<int, int> :: iterator it = Component.begin(); 
    for( ; it != Component.end(); ++it) {
        for(int i = 0; i < (int)G[it->first].size(); ++i) {
            int v = G[it->first][i];
            if(it->second == Component[v])  continue;              // No Self loop in new graph
            G1[it->second].push_back(Component[v]);
}}} void RunSCC(int V) {
    memset(dfs_num, 0, sizeof(dfs_num)), visited.reset(), dfsCounter = 0, SCC_no = 0;
    for(int i = 1; i <= V; i++) if(dfs_num[i] == 0) tarjanSSC(i);
}
