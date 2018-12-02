// LightOJ
// 1357 - Corrupted Friendship

#include <bits/stdc++.h>
#define MAX 101000
using namespace std;

vector<long long>G[MAX];
set<long long>SET;
set<pair<long long, long long> >EDGE;
long long cnt;
bitset<MAX> vis;

long long dfs(int u, int par = -1) {
    long long ret = 0;
    vis[u] = 1;
    SET.erase(u);
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];

        if(not vis[v])
            ret += dfs(v, u);
    }

    ret += SET.size();
    return ret;
}

int main() {
    long long t, u, v, V;
    scanf("%lld", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld", &V);

        for(int i = 1; i < V; ++i) {
            scanf("%lld%lld", &u, &v);
            if(u > v) swap(u, v);
            if(not EDGE.count(make_pair(u, v))) {
                G[u].push_back(v);
                G[v].push_back(u);
        }}

        for(int i = 1; i <= V; ++i)
            SET.insert(i);

        vis.reset();
        printf("Case %d: %lld %lld\n", Case, V-1, dfs(1));

        for(int i = 0; i <= V; ++i)
            G[i].clear();
        SET.clear();
        EDGE.clear();
    }
    return 0;
}