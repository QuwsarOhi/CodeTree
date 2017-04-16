//UVa
//11463 - Commandos
//Single Source Shortest Path
//Dikjstra(find maximum path from s to d), Floyd Warshall (solved in floyd warshall)

#include <bits/stdc++.h>
#define MAX 110
#define INF 1e8
using namespace std;

int G[MAX][MAX];

void graphINIT()
{
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            G[i][j] = INF;
    for(int i = 0; i < MAX; i++)
        G[i][i] = 0;
}

void floydWarshall(int V)
{
	//path printing matrix initialization
	//for(int i = 0; i < V; i++)
		//for(int j = 0; j < V; j++)
			//parent[i][j] = i;		//we can go to j from i by only obtaining i (by default)

    for(int k = 0; k < V; k++)      //Selecting a middle point as k
        for(int i = 0; i < V; i++)  //Selecting all combination of source (i) and destination (j)
            for(int j = 0; j < V; j++)
                if(G[i][k] != INF && G[k][j] != INF) { 			//if the graph contains negative edges, then min(INF, INF+ negative edge) = +-INF!
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);    //if G[i][i] = negative, then node i is in negative circle
                    //parent[i][j] = parent[k][j];				//if path printing needed
				}
}

int main()
{
    //freopen("in", "r", stdin);

    int t, u, v, V, E, s, d, Case = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &V, &E);
        graphINIT();
        while(E--) {
            scanf("%d %d", &u, &v);
            G[u][v] = G[v][u] = 1;
        }
        scanf("%d %d", &s, &d);
        floydWarshall(V);
        int dist = 0;
        for(int i = 0; i < V; i++)      //the largest distance from :  s to any other point i + i to d is the ans
            dist = max(G[s][i] + G[i][d], dist);
        printf("Case %d: %d\n", Case++, dist);
    }
    return 0;
}
