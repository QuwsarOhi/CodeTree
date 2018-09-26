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


/*---------------- DFS Timing + Child Finding ----------------*/

int startTime[MAX], endTime[MAX], Time = 1;
void dfsTiming(int u = 1, int par = -1) {
    startTime[u] = Time;
    for(auto v : Tree[u])
        if(v != par) {
            ++Time;
            dfsTiming(v, u);
        }
    endTime[u] = Time;
}

bool isChild(int child, int par) {                                  // returns true if a is child of b
    return ((child == par) or ((startTime[par] <= startTime[child]) and (endTime[par] >= endTime[child])));
}