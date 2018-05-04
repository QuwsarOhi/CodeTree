// Cycle in Directed graph
// http://codeforces.com/contest/915/problem/D

vi G[550];
int color[550], Cycle = 0;      // Cycle will contain the number of cycles found in graph
void dfs(int u) {
    color[u] = 2;               // Mark as parent
    for(auto v : G[u]) {
        if(color[v] == 2)       // If any Parent found (BackEdge)
            Cycle++;
        else if(!color[v])
            dfs(v);
    } 
    color[u] = 1;               // Visited
}
