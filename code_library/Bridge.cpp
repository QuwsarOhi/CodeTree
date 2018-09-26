//Complexity : O(V+E)
//Finding Bridges (Graph)

vector<int> G[MAX];
vector<pair<int, int> >ans;
int dfs_num[MAX], dfs_low[MAX], dfsCounter, timeToNode[MAX];

void bridge(int u, int par = -1) {
    // dfs_num[u] is the dfs counter of u node
    // dfs_low[u] is the minimum dfs counter of u node (it is minimum if a backedge exists)
    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    //timeToNode[dfs_num[u]] = u;
    for(auto v : G[u]) {
        if(v == par) continue;
        if(dfs_num[v] == 0) {
            bridge(v, u);
            // if dfs_num[u] is lower than dfs_low[v], then there is no back edge on u node
            // so u - v can be a bridge
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if(dfs_num[u] < dfs_low[v])
                ans.push_back(make_pair(min(u, v), max(u, v)));
        }
        // if v is not parent of u then it is a back edge
        // also dfs_num[v] must be less than dfs_low[u]
        // so we update it
        else if(v != par)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
    timeToNode[dfs_num[u]] = u;         // if BuildNewTree is used otherwise ignore it
}

void FindBridge(int V){                             //Bridge finding code
    memset(dfs_num, 0, sizeof(dfs_num));
    dfsCounter = 0;
    for(int i = 0; i < V; i++)
        if(dfs_num[i] == 0)
            bridge(i);
}

/*---------------- Build Bridge Tree ----------------*/

vi Tree[MAX];
int conv[MAX] = {0}, ncnt;
int Convert(int u) {                                // Converts graph node number to
    if(conv[dfs_low[u]] == 0)                       // tree numbers
        conv[dfs_low[u]] = ++ncnt;                  // tree nodes start from 1
    return conv[dfs_low[u]];                        // ncnt contains total number of nodes 
}                                                   // in the tree

int findMin(int u) {                                    // Basic tarjan doesn't contain same dfs_low[u]
    if(dfs_low[u] == dfs_num[u]) return dfs_low[u];     // for all nodes, so this finds the actual values
    return dfs_low[u] = findMin(timeToNode[dfs_low[u]]);
}

int BuildNewTree(int V) {
    ncnt = 0;
    for(int i = 1; i <= V; ++i) 
        findMin(i);
    for(auto it : ans) {
        int u = Convert(it.first), v = Convert(it.second);
        Tree[u].pb(v);
        Tree[v].pb(u);
    }
    return ncnt;
}