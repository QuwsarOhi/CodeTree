// Basic DFS
// Time complexity: O(V+E)
// Why?
// The for loop of dfs works as follows
// = v1 + (incident edges) + v2 + (incident edges) + .... + vn + (incident edges)
// = (v1 + v2 + ... + vn) + [(incident_edges v1) + (incident_edges v2) + ... + (incident_edges vn)]
// = V + E     [v_i \in V and e_i in E]
// Reference: https://stackoverflow.com/questions/11468621/why-is-the-time-complexity-of-both-dfs-and-bfs-o-v-e

vi G[550];
int visited[550];       // Default value of visited is 0
void dfs(int u) {
    visited[u] = 1;
    cout << "AT node " << u << endl;
    for(auto v : G[u]) {
        if(color[v] == 0)
            dfs(v);
    }
}

// Cycle in Directed graph
// http://codeforces.com/contest/915/problem/D
// Time complexity: O(V(V+E))

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
