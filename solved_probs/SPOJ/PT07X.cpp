// SPOJ
// PT07X - Vertex Cover

#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

vector<int>G[MAX];
int dp[MAX][2];

void dfs(int u, int par = -1) {
    dp[u][0] = 0;
    dp[u][1] = 1;

    for(auto v : G[u]) {
        if(v == par) continue;
        dfs(v, u);

        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}

int main() {
    int V, u, v;

    scanf("%d", &V);

    for(int i = 1; i < V; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1);
    printf("%d\n", min(dp[1][0], dp[1][1]));
    return 0;
}