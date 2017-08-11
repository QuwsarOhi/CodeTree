//UVa
//821 - Page Hopping
//All Pair Shortest Path (Floyd Warshall)

#include <bits/stdc++.h>
#define MAX 105
#define INF 1e7
using namespace std;

int G[MAX][MAX], used[MAX], node;

void graphINIT()
{
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++) {
            if(i == j)
                G[i][j] = 0;
            else
                G[i][j] = INF;
        }
}

void floydWarshall(int V)
{
    for(int k = 1; k < V; k++)      //Selecting a middle point as k
        for(int i = 1; i < V; i++)  //Selecting all combination of source (i) and destination (j)
            for(int j = 1; j < V; j++)
                if(G[i][k] != INF && G[k][j] != INF)       //if the graph contains negative edges, then min(INF, INF+ negative edge) = +-INF!
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);    //if G[i][i] = negative, then node i is in negative circle
}

void node_count(int x, int y)
{
    if(used[x] == 0) {
        used[x]++;
        node++;
    }
    if(used[y] == 0) {
        used[y]++;
        node++;
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

        int u, v, V, Case = 1;
        while(scanf("%d%d", &u, &v) && (u || v)) {
            memset(used, 0, sizeof(used));
            node = 0;
            V = max(u, v);
            node_count(u, v);
            graphINIT();
            G[u][v] = 1;
            while(scanf("%d%d", &u, &v) && (u || v)) {
                G[u][v] = 1;
                V = max(V, max(u, v));
                node_count(u, v);
            }
            floydWarshall(V+1);
            int sum = 0;
            for(int i = 0; i <= V; i++)
                for(int j = 0; j <= V; j++)
                    if(G[i][j] != INF)
                        sum += G[i][j];

            printf("Case %d: average length between pages = %0.3lf clicks\n", Case++, (double)sum/(node*(node-1)));
        }
    return 0;
}
