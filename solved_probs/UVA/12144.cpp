//UVa
//12144 - Almost Shortest Path

//Second Shortest Path (unused)
//Dikjstra, Variant
//The edges and nodes which builds the shortest path(s) needs to be cut off
//then find shortest path again

#include<bits/stdc++.h>
#define MAX 510
#define INF 1e6

using namespace std;

vector<int>G[MAX], W[MAX], S[MAX]; //edge, edge_weight, reverse_shortest_paths_graph
int dist[MAX];
bool cut_node[MAX], cut_edge[MAX][MAX];
bitset<550>visited;

int dikjstra(int source, int end, int nodes)
{
    //dist[v] contains the distance from u to v
    for(int i = 0; i < nodes; i++)
        dist[i] = INF;

    //visited is used to exclude same copies of nodes (algorithm doesn't visit same node twice)
    visited.reset();
    dist[source] = 0;

    //pq is sorted in ascending order according to weight and edge
    priority_queue<pair<int, int> > pq;
    pq.push({0, -source});

    while(!pq.empty()) {
        int u = -pq.top().second;
        int wu = -pq.top().first;
        pq.pop();

        //skipping the longer edges, if we have found shorter edge earlier
        //also skipping visited nodes
        if(wu > dist[u] || visited[u])
            continue;

        visited[u] = 1;

        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            int wv = W[u][i];

            //if there is a node / edge(edge is in critical case) that is used earlier in shortest path
            //we exclude it
            if(cut_node[v] || cut_edge[u][v] || visited[v])
                continue;

            //path relax
            if(wu + wv < dist[v]) {
                dist[v] = wu + wv;

                //if this edge is smaller than other edge, then we refresh the reverse paths of this node
                //then push back the node, (building a reverse graph of shortest path(s) )
                S[v].clear();
                S[v].push_back(u);
                pq.push({-dist[v], -v});
            }
            //if there is more than one shortest paths, then only add it in the reverse graph, nothing else
            else if(wu + wv == dist[v])
                S[v].push_back(u);
        }
    }
    return dist[end];
}


//this function cuts off all the nodes
void cut_off(int start, int destination)
{
    if(destination == start)
        return;
    for(int i = 0; i < S[destination].size(); i++) {
        int v = S[destination][i];
        cut_node[v] = 1;
        cut_edge[destination][v] = cut_edge[v][destination] = 1;
        cut_off(start, v);
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int E, V, u, v, w, source, destination;
    while(scanf("%d %d", &V, &E) && (V || E)) {
        scanf("%d %d", &source, &destination);
        while(E--) {
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(v);
            W[u].push_back(w);
        }

        memset(cut_edge, 0, sizeof cut_edge);
        memset(cut_node, 0, sizeof cut_node);

        //finding the shortest possible path(s)
        //this function also creates a reverse graph of shortest path(s)
        dikjstra(source, destination, V);
        //cut off all those nodes and edges which are used in shortest path
        cut_off(source, destination);

        //now find the shortest path again, this is the answer
        int ans = dikjstra(source, destination, V);

        if(ans == INF)
            printf("-1\n");
        else
            printf("%d\n", ans);

        for(int i = 0; i < V; i++) {
            G[i].clear();
            W[i].clear();
        }
    }
    return 0;
}
