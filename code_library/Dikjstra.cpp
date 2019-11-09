// Shortest Path (Dikjstra)
// Complexity : (V*logV + E)

vector<int>dist, G[MAX], W[MAX];
void printPath(int u) {     // call with ending node
    if (u == s) {           // s is the starting node
        printf("%d", s);    // base case, at the source s
        return;
    }                       
    printPath(p[u]);        // recursive: to make the output format: s -> ... -> t
    printf(" %d", u);
}

void dikjstra(int u, int destination, int nodes) {
    dist.resize(nodes+1, INF);                      // dist[v] contains the distance from u to v
    dist[u] = 0;
    priority_queue<pair<int, int> > pq;             // pq is sorted in ascending order according to weight and edge
    pq.push({0, -u});

    while(!pq.empty()) {
        int u = -pq.top().second;
        int wu = -pq.top().first;
        pq.pop();
        if(u == destination) return;                // if we only need distance of destination, then we may return
        if(wu > dist[u]) continue;                  // skipping the longer edges, if we have found shorter edge earlier

        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            int wv = W[u][i];
            if(wu + wv < dist[v]) {                 // path relax
                dist[v] = wu + wv;
                p[v] = u;                           // path printing
                pq.push({-dist[v], -v});
}}}}

/* Kth Path Using Modified Dikjstra
   Complexity : O(K*(V*logV + E))
   http://codeforces.com/blog/entry/16821 */
vector<int>G[MAX], W[MAX], dist[MAX];
int KthDikjstra(int Start, int End, int Kth) {      // Kth Shortest Path (Visits Edge Only Once)
    for(int i = 0; i < MAX; ++i)
        dist[i].clear();
    priority_queue<pii>pq;                  // Weight, Node
    pq.push(make_pair(0, Start));
   
    while(!pq.empty()) {
        int u = pq.top().second;
        int w = -pq.top().first;
        pq.pop();
       
        //if((int)dist[End].size() == Kth)    // We can also break if the Kth path is found
        //    return dist[End].back();
        if(dist[u].empty())
            dist[u].push_back(w);
        else if(dist[u].back() != w)        // Not taking same cost paths
            dist[u].push_back(w);           // As priority queue greedily chooses edge, it's guranteed that this edge is bigger than previous
        if((int)dist[u].size() > Kth)       // Like basic dikjstra, we'll not take the Kth+ edges
            continue;
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            int _w = w + W[u][i];
            if((int)dist[v].size() == Kth)
                continue;
            pq.push(make_pair(-_w, v));
    }}
    return -1;
}

int KthDikjstra(int Start, int End, int Kth) {      // Kth Shortest Path (Visits Same Edge More Than Once if required)
    for(int i = 0; i < MAX; ++i)
        dist[i].clear();
    priority_queue<pii>pq;                  // Weight, Node
    pq.push(make_pair(0, Start));
    
    while(!pq.empty()) {
        int u = pq.top().second;
        int w = -pq.top().first;
        pq.pop();

        if(dist[u].empty())
            dist[u].push_back(w);
        else if(dist[u].back() != w) {          // if the weight is not same
            if((int)dist[u].size() < Kth)       // if we have to take more costs, take it
                dist[u].push_back(w);
            else if(dist[u].back() <= w)        // if the cost is greater than previous, then, don't go further
                continue;
            else {                              // we have to take this cost, and remove the greater one
                dist[u].push_back(w);
                sort(dist[u].begin(), dist[u].end());
                dist[u].pop_back();
        }}
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            int _w = w + W[u][i];
            pq.push(make_pair(-_w, v));
    }}
    if((int)dist[End].size() < Kth) return -1;
    return dist[End].back();
}

// Kth Shortest Path (Every edge and shortest path of previous calculation is not used)

vector<int>G[MAX], W[MAX], S[MAX];          //edge, edge_weight, reverse_shortest_paths_graph
int dist[MAX];
bool cut_node[MAX], cut_edge[MAX][MAX];

int dikjstra(int source, int end, int nodes) {
    for(int i = 0; i < nodes; i++)          // dist[v] contains the distance from u to v
        dist[i] = INF;
    dist[source] = 0;
    priority_queue<pair<int, int> > pq;     // pq is sorted in ascending order according to weight and edge
    pq.push({0, -source});

    while(!pq.empty()) {
        int u = -pq.top().second;
        int wu = -pq.top().first;
        pq.pop();
        if(wu > dist[u]) continue;          // skipping the longer edges, if we have found shorter edge earlier

        for(int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i];
            int wv = W[u][i];

            if(cut_node[v] || cut_edge[u][v])   // if there exists node/edge that is used in previous shortest path
                continue;
            if(wu + wv < dist[v]) {             // path relax
                dist[v] = wu + wv;
                S[v].clear();                   // if this edge is smaller than other edge, then we refresh the reverse paths of this node
                S[v].push_back(u);              // then push back the node, (building a reverse graph of shortest path(s) )
                pq.push({-dist[v], -v});
            }
            else if(wu + wv == dist[v])         // if there is more than one shortest paths, then only add it in the reverse graph, nothing else
                S[v].push_back(u);
    }}
    return dist[end];
}

void cut_off(int start, int destination) {      // this function cuts off all the nodes
    if(destination == start) return;
    for(int i = 0; i < S[destination].size(); i++) {
        int v = S[destination][i];
        cut_node[v] = 1;
        cut_edge[destination][v] = cut_edge[v][destination] = 1;
        cut_off(start, v);
}}
