//Complexity : O(V+E)
//Finding Bridges (Graph)

vector<int> G[MAX];
vector<pair<int, int> >ans;
int dfs_num[MAX], dfs_low[MAX], parent[MAX], dfsCounter;

void bridge(int u) {
    //dfs_num[u] is the dfs counter of u node
    //dfs_low[u] is the minimum dfs counter of u node (it is minimum if a backedge exists)

    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(dfs_num[v] == 0) {
            parent[v] = u;

            bridge(v);
            //if dfs_num[u] is lower than dfs_low[v], then there is no back edge on u node
            //so u - v can be a bridge
            if(dfs_num[u] < dfs_low[v])
                ans.push_back(make_pair(min(u, v), max(u, v)));

            //obtainig lower dfs counter (if found) from child nodes
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        //if v is not parent of u then it is a back edge
        //also dfs_num[v] must be less than dfs_low[u]
        //so we update it

        else if(parent[u] != v)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}}

void FindBridge(int V){                             //Bridge finding code
    memset(dfs_num, 0, sizeof(dfs_num));
    dfsCounter = 0;
    for(int i = 0; i < V; i++)
        if(dfs_num[i] == 0)
            bridge(i);
}

int main() {
    FindBridge(100);
    //Output
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        printf("%d - %d\n", ans[i].first, ans[i].second);
    printf("\n");
    return 0;
}
