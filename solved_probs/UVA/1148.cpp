//UVa
//1148 - The mysterious X network
//BFS

#include<bits/stdc++.h>
#define MAX 100010
using namespace std;

vector<int>G[MAX], level;
bitset<MAX>visited;

void bfs(int U, int V)
{
    visited[U] = 1;
    level[U] = 0;
    queue<int>q;
    q.push(U);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 0; i < G[u].size(); i ++) {
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
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, V, u, v, q;
    scanf("%d", &t);
    bool first = 1;
    while(t--) {
        if(!first)
            printf("\n");
        first = 0;
        scanf("%d", &V);
        for(int i = 0; i < V; i++) {
            scanf("%d %d", &u, &q);
            while(q--) {
                scanf("%d", &v);
                G[u].push_back(v);
            }
        }
        scanf("%d %d", &u, &v);
        //printf("input done\n");
        visited.reset();
        level.resize(V+1, 0);
        bfs(u, v);
        printf("%d %d %d\n", u, v, level[v]-1);
        for(int i = 0; i < V; i++)
            G[i].clear();
    }
    return 0;
}
