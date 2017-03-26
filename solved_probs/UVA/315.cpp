//UVa
//315 - Network
//Articulation Point
//Tarjan, DFS

#include<bits/stdc++.h>
using namespace std;

vector<int>G[101];
int dfs_num[101], dfs_low[101], parent[101], dfsCounter, rootChildren, dfsRoot;
bitset<101>isArticulationPoint;

void articulationPoint(int u)
{
    dfs_low[u] = dfs_num[u] = ++dfsCounter;

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(dfs_num[v] == 0) {
            parent[v] = u;
            if(u == dfsRoot)            //Special case for root node
                rootChildren++;         //if root node has child, increment counter

            articulationPoint(v);

            //1 : if dfs_num[u] == dfs_low[v], then it is a back edge
            //2 : if dfs_num[u] < dfs_low[v], then u is ancestor of v and there is no back edge
            //so, if u is not root node, then we can chose u for Articulation Point

            if(dfs_num[u] <= dfs_low[v] && u != dfsRoot)    //Avoiding root node
                isArticulationPoint[u] = 1;

            //if there is any child node of u that is a back edge of a previous node
            //then the value of dfs_low[v] might be less than the present dfs_low[u]
            //we try to save the lowest value possible

            dfs_low[u] = min(dfs_low[v], dfs_low[u]);
        }
        //As nodes are bi-directional, avoiding direct child node
        //if it is not direct child node, and visited, then there is a back edge
        //so we try to decrease the value of dfs_low[u] with the dfs_num[v]
        //the dfs_num[v] is less than dfs_num[u] (as it it a back edge)

        else if(parent[u] != v)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int n, u, v;
    char S[210];
    scanf("%d", &n);
    while(n) {
        for(int i = 0; i < 101; i++)
            G[i].clear();
        while(1) {
            scanf(" %[^\n] ", S);
            stringstream ss;
            ss << S;
            ss >> u;
            if(u)
                while(ss >> v) {
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
            else
                break;
        }
        dfsCounter = 0;
        memset(dfs_num, 0, sizeof(dfs_num));
        isArticulationPoint.reset();
        for(int i = 1; i <= n; i++) {
            if(dfs_num[i] == 0) {
                dfsCounter = rootChildren = 0;
                dfsRoot = i;
                articulationPoint(i);
                if(rootChildren > 1)
                    isArticulationPoint[i] = 1;
            }
        }

        //Printing Articulation Points
        /*for(int i = 0; i < 101; i++)
            if(isArticulationPoint[i])
                printf("%d ", i);
        printf("\n");*/

        printf("%d\n", (int)isArticulationPoint.count());
        scanf("%d", &n);
    }
    return 0;
}
