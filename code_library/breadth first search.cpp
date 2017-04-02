#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

vector<int> G[MAX];

void BFS(int V, int U)
{
    //V = total Vertex in Graph
    //U = starting node
    //level[x] will contain the distance from node u to x in an unweighted graph(SCC)

    vector<int>level;
    queue<int>q;

    level.resize(V+1, 0);
    q.push(U);
    visited[U] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];

            if(!visited[v]) {
                visited[v] = 1;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{

}
