//UVa
//10557 - XYZZY
//Single Source Shortest Path (Negative Weight)
//Bellman Ford / Floyd Warshall

#include<bits/stdc++.h>
#define MAX 102
#define INF 1e6
using namespace std;

int dist[MAX], point[MAX], W[MAX], V;
vector<int> G[MAX];
bitset<MAX>visited;

//first try to find out all maximum edges from the starting point
//if the n'th node has positive distance then it is visitable
//again if there is a positive cycle, then we may round there many times we want and store enough energy
//then we might go for the n'th node

void bellmanFord()
{
    for(int i = 0; i <= V; i++)
        dist[i] = -INF;

    dist[1] = 100;

    for(int i = 0; i < V-1; i++) {
        for(int u = 1; u < V; u++) {
            for(int j = 0; j < G[u].size(); j++) {
                int v = G[u][j];
                int w = W[v];

                //if it is not ignored, then it might become a positive value by summing up with a larger edge
                //by continuing, it always remains negative
                if(dist[u] + w <= 0)
                    continue;

                dist[v] = max(dist[v], dist[u]+w);
            }
        }
    }
}

bool isReachable(int u, int w)
{
    if(u == w)
        return 1;

    bool found = 0;

    for(int i = 0; i < G[u].size() && !found; i++) {
        int v = G[u][i];
        if(!visited[v]) {
            visited[v] = 1;
            found = isReachable(v, w);
        }
    }
    return found;
}

//if the graph has positive cycle, then the node n will only be visitable if
//the node that has positive cycle can be visited before energy level reaching 0
//the positive cycle connects to the n'th node as well

bool hasPositiveCycle()
{
    for(int u = 1; u < V; u++)
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            int w = W[v];

            //if energy level is zero, then we cant reach this node
            //so we dont have to find positive cycle in this node
            if(dist[v] <= 0)
                continue;

            if(dist[v] < dist[u] + w) {
                visited.reset();
                return (isReachable(u, V));
            }
        }
    return 0;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int w, E, v;
    while(scanf("%d", &V) && (V != -1)) {
        for(int u = 1; u <= V; u++) {
            scanf("%d %d", &w, &E);
            W[u] = w;
            while(E--) {
                scanf("%d", &v);
                G[u].push_back(v);
            }
        }
        W[1] = 0;
        W[V] = 0;

        bellmanFord();

        if(dist[V] > 0)
            printf("winnable\n");
        else if(hasPositiveCycle())
            printf("winnable\n");
        else
            printf("hopeless\n");

        for(int i = 0; i <= V; i++)
            G[i].clear();
    }
    return 0;
}
