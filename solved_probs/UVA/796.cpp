//UVa
//796 - Critical Links
//Finding Bridges (Graph)

#include<bits/stdc++.h>
#define MAX 150
using namespace std;

vector<int> G[MAX];
vector<pair<int, int> >ans;
int dfs_num[MAX], dfs_low[MAX], parent[MAX], dfsCounter;

void bridge(int u)
{
    //dfs_num[u] is the dfs counter of u node
    //dfs_low[u] is the minimum dfs counter of u node (it is minimum if a backedge exists)

    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(dfs_num[v] == 0) {
            parent[v] = u;

            bridge(v);
            //if dfs_num[u] is lower than dfs_low[v], then there is no back edge on u node
            //so u - v can be a bridge
            if(dfs_num[u] < dfs_low[v])
                ans.push_back(make_pair(min(u, v), max(u, v)));

            //obtainig lower dfs counter (if found) from child nodes
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        //if v is not parent of u then it is a back edge
        //also dfs_num[v] must be less than dfs_low[u]
        //so we update it

        else if(parent[u] != v)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}


int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int n, u, v, c;
    while(scanf(" %d ", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf(" %d %*[(] %d %*[)]", &u, &c);
            while(c--) {
                scanf(" %d ", &v);
                G[u].push_back(v);
            }
        }
        //Bridge finding code
        memset(dfs_num, 0, sizeof(dfs_num));
        dfsCounter = 0;
        for(int i = 0; i < n; i++)
            if(dfs_num[i] == 0)
                bridge(i);

        printf("%d critical links\n", (int)ans.size());
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
            printf("%d - %d\n", ans[i].first, ans[i].second);
        printf("\n");
        ans.clear();
        for(int i = 0; i <= n; i++)
            G[i].clear();
    }
    return 0;
}
