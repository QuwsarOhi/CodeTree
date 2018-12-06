#include <bits/stdc++.h>
#define MAX 210000
using namespace std;

vector<int>G[MAX];
bitset<MAX>vis, compoVis;
set<int>NODE;
vector<vector<int> > chain;

bool cmp(vector<int> &a, vector<int> &b) {
    int lim = min(a.size(), b.size());
    for(int i = 0; i < lim; ++i)
        if(a[i] > b[i])
            return 1;
    return 0;
}

int maxLen, startNode;
void FindNode(int u, int len) {
    vis[u] = 1;

    if(len > maxLen) {
        maxLen = len;
        startNode = u;
    }

    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(not vis[v])
            FindNode(v, len+1);
    }
    vis[u] = 0;
}

bool MarkChain(int u, int len, bool first) {
    vis[u] = 1;
    if(len == maxLen)
        return 1;

    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v] == 0 and MarkChain(v, len+1, 0)) {
            NODE.erase(v);
            return 1;
        }
    }

    vis[u] = 0;
    if(first) {
        vis[u] = 1;
        NODE.erase(u);
    }

    return 0;
}

void dfs(int u) {
    compoVis[u] = 1;
    NODE.insert(u);

    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(not compoVis[v])
            dfs(v);
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, V, E, u, v, q, k;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &V, &E);

        for(int i = 0; i < E; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vis.reset();
        compoVis.reset();

        int maxTot = 0, maxChain = 0;
        for(int i = 1; i <= V; ++i) {
            if(compoVis[i]) continue;
            dfs(i);
            chain.push_back(vector<int>());

            while(not NODE.empty()) {
                maxLen = -1, startNode = -1;
                FindNode(*NODE.begin(), 1);
                maxLen = -1;
                FindNode(startNode, 1);
                MarkChain(startNode, 1, 1);

                if(NODE.count(startNode))
                    NODE.erase(startNode);

                chain.back().push_back(maxLen);
                maxChain = max(maxChain, maxLen);
            }
        }

        for(int i = 0; i < chain.size(); ++i)
            sort(chain[i].begin(), chain[i].end(), greater<int>());
        sort(chain.begin(), chain.end(), cmp);


        for(int i = 0; i < chain.size(); ++i) {
            int tot = 0;
            for(int j = 0; j < chain[i].size(); ++j)
                tot += chain[i][j];
            chain[i].push_back(tot);
            maxTot = max(maxTot, tot);
        }

        printf("Case %d:\n", Case);
        scanf("%d", &q);

        while(q--) {
            scanf("%d", &k);

            if(maxChain >= k) {
                printf("%d\n", max(k-1, 0));
                continue;
            }

            if(maxTot < k) {
                printf("impossible\n");
                continue;
            }

            for(int i = 0; i < chain.size(); ++i) {
                if(chain[i].empty() or chain[i].back() < k) continue;

                int totCost = chain[i][0]-1, kSum = chain[i][0];
                for(int j = 1; j < (int)chain[i].size()-1 and kSum < k; ++j) {
                    if(kSum+chain[i][j] <= k)
                        totCost += chain[i][j]*2;
                    else
                        totCost += chain[i][j]*2 - ((kSum+chain[i][j])-k)*2;
                    kSum += chain[i][j];
                }

                printf("%d\n", totCost);
                break;
            }
        }

        for(int i = 0; i <= V; ++i)
            G[i].clear();
        chain.clear();
        NODE.clear();
    }

    return 0;
}