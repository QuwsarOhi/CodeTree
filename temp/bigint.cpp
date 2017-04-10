#include<bits/stdc++.h>
#define INF 1e7
using namespace std;

vector<int> G[205];
int W[205], dist[205], V;

void bellmanFord()
{
    for(int i = 0; i <= V; i++)
        dist[i] = INF;

    dist[1] = 0;

    for(int i = 0; i < V-1; i++) {
        for(int u = 1; u <=V; u++)
            for(int j = 0; j < G[u].size(); j++) {
                int v = G[u][j];

                if(dist[u] != INF)
                    dist[v] = min(dist[v], dist[u]+(W[v] - W[u])*(W[v] - W[u])*(W[v] - W[u]));
            }
        /*for(int u = 1; u <= V; u++)
            for(int i = 0; i < G[u].size(); i++)
                printf("%d : %d\n", u, dist[u]);
        printf("\n");*/
    }
}

bool hasNegativeCycle()
{
    for(int u = 0; u < V; u++)
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];

            //if bellmanFord is run for max values, then this code will return true for positive cycle by adding this line
            //if(dist[v] < dist[u] + w)
            if(dist[v] > dist[u] + (W[v] - W[u])*(W[v] - W[u])*(W[v] - W[u]))
                dist[u] = INF;
        }
    return 0;
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int u, v, x, E, q, cnt = 1;
    while(scanf("%d", &V) != EOF) {
        for(int i = 1; i <= V; i++)
            scanf("%d", &W[i]);
        scanf(" %d ", &E);
        while(E--) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        bellmanFord();
        //bool hasNEG = hasNegativeCycle();
        hasNegativeCycle();
        scanf("%d", &q);
        printf("Set #%d\n", cnt++);
        while(q--) {
            scanf("%d", &x);
            if(dist[x] >= 3 && dist[x] != INF)
                printf("%d\n", dist[x]);
            else
                printf("?\n");
        }

        for(int i = 0; i <= V; i++)
            G[i].clear();
    }
    return 0;
}
