#include <bits/stdc++.h>
#define MAX 100
#define INF 1e7
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
    for(int k = 0; k < V; k++)      //Selecting a middle point as k
        for(int i = 0; i < V; i++)  //Selecting all combination of source (i) and destination (j)
            for(int j = 0; j < V; j++)
                if(G[i][k] != INF && G[k][j] != INF)       //if the graph contains negative edges, then min(INF, INF+ negative edge) = +-INF!
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);    //if G[i][i] = negative, then node i is in negative circle
}

int main()
{
    int V = 5;
    graphINIT();
    G[0][1] = 1;
    G[1][2] = 1;
    G[2][4] = 5;
    G[4][3] = -6;
    G[3][2] = -1;

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(G[i][j] != INF)
            printf("%4d", G[i][j]);
            else
                printf(" INF");
        }
        printf("\n");
    }
    floydWarshall(5);

        for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(G[i][j] != INF)
            printf("%4d ", G[i][j]);
            else
                printf(" INF ");
        }
        printf("\n");
    }

    return 0;
}
