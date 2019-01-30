//Strongly Connected Component (Tarjan)
//Complexity : O(V+E)

vector<int>G[MAX], SCC;
int dfs_num[MAX], dfs_low[MAX], dfsCounter, SCC_no = 0;
bitset<MAX>visited;
map<int, int>Component;         // For Creating new SCC (ConnectNode function)

void tarjanSSC(int u) {
    // Stack, here, it is implemented as vector instead
    SCC.push_back(u);
    // Marking node u as visited
    // visited[u] marks if the node u is usable in a SCC and not used on other SCC
    // if visited[u] is false, then it is used in other SCC
    visited[u] = 1;
    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    // for all Strongly Connected Component (directed graph), dfs_low[u] is same
    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        // if it is not visited yet, backtrack it
        // for undirected graph, check if v != parent_of_u
        if(dfs_num[v] == 0)
            tarjanSSC(v);

        // visited[v] is used to check if this node is not in any other SCC
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    // in a SCC the first node of the SCC, node u is the first node in a SCC if dfs_low[u] == dfs_low[v]
    // as we implementing stack like data structure, the nodes from top to u are on the same SCC
    if(dfs_low[u] == dfs_num[u]) {
        SCC_no++;       // Component Node no. starts from 0
        
        // ------------------- Use if ONLY IF ConnectNode / Printing needed ------------------- 
        bool first = 1;
        while(1) {
            int v = SCC.back();
            SCC.pop_back();
            // node v is used, so marking it as false, so that the ancestor nodes
            // doesn't use this node to update it's value
            visited[v] = 0;
            // printf("%d\n", v);
            Component[v] = SCC_no;      // Marking SCC nodes to as same component
            if(u == v)
                break;
        }
        // printf("\n");
}}

void ConnectNode() {                    // This function can convert Components to a new graph (G1)
    map<int, int> :: iterator it = Component.begin(); 
    for( ; it != Component.end(); ++it) {
        for(int i = 0; i < (int)G[it->first].size(); ++i) {
            int v = G[it->first][i];
            if(it->second == Component[v])              // No Self loop in new graph
                continue;
            G1[it->second].push_back(Component[v]);
}}}


void RunSCC(int V) {
    memset(dfs_num, 0, sizeof(dfs_num));
    dfsCounter = 0;
    visited.reset();
    SCC_no = 0;
    for(int i = 1; i <= V; i++)
        if(dfs_num[i] == 0)
            tarjanSSC(i);
}
