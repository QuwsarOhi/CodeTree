// LightOJ
// 1412 - Visiting Islands

#include <bits/stdc++.h>
#define MAX 100005
#define INF 0x3f3f3f3f
using namespace std;

bitset<MAX> compo, vis;
vector<int> G[MAX];
int ans[MAX];

int dfs(int u) {
    compo[u] = 1;
    int ret = 1;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(not compo[v])
            ret += dfs(v);
    }
    return ret;
}

int maxLen, startNode;
void LongestChain(int u, int len) {
    vis[u] = 1;

    if(len > maxLen) {
        maxLen = len;
        startNode = u;
    }

    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(not vis[v]) LongestChain(v, len+1);
    }

    vis[u] = 0;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, u, v, V, E, k, q;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &V, &E);

        for(int i = 0; i < E; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        memset(ans, INF, sizeof ans);
        compo.reset();
        vis.reset();

        //cerr << "DONE\n";

        // Process each Graph Component
        int maxCompo = 0;
        for(int i = 1; i <= V; ++i) {
            if(compo[i]) continue;

            int totNode = dfs(i);
            maxCompo = max(maxCompo, totNode);

            //cerr << "DFS DONE\n";

            maxLen = -1, startNode = -1;
            LongestChain(i, 1);
            maxLen = -1;
            LongestChain(startNode, 1);

            for(int k = 1; k <= totNode; ++k) {
                if(k <= maxLen)
                    ans[k] = min(ans[k], k-1);
                else
                    ans[k] = min(ans[k], maxLen-1 + (k-maxLen)*2);
            }
        }

        printf("Case %d:\n", Case);
        scanf("%d", &q);

        while(q--) {
            scanf("%d", &k);
            if(k > maxCompo)
                printf("impossible\n");
            else
                printf("%d\n", ans[k]);
        }

        for(int i = 0; i <= V; ++i) G[i].clear();
    }

    return 0;
}