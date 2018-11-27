#include <bits/stdc++.h>
#define MAX 100009
using namespace std;

vector<int>G[MAX];
set<int>SET;
long long cnt;

long long dfs(int u, int par = -1) {
    int ret = 0;

    SET.erase(u);
    //--cnt;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];

        if(v != par)
            ret += dfs(v, u);
    }

    ret += SET.size();
    //ret += cnt;
    return ret;
}

int main() {
    int t, u, v, V;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &V);

        for(int i = 1; i < V; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            //G[v].push_back(u);
        }

        for(int i = 1; i <= V; ++i)
            SET.insert(i);

        //cnt = V;
        printf("Case %d: %d %lld\n", Case, V-1, dfs(1));

        for(int i = 0; i <= V; ++i)
            G[i].clear();
        SET.clear();
    }
    return 0;
}