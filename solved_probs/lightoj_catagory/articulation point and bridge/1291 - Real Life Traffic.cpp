// LightOJ
// 1291 - Real Life Traffic
// Bridge

// Target : to find minimum number of roads, we have to find the corner nodes with bridges, then the ans is (n+1)/ [as we can connect every two nodes with one edge]
// to corner nodes with bridge, first cut off all bridges (also save the two nodes which contain bridge)
// then run bfs/dfs so that, all strongly connected component turns into single component/ node
// increment the bridge nodes with the new made nodes/components, single incremented are the ans

// ex :   0 -- 1---3 -- 4 - 6
//		  |		\ /		|
//		  7 	 2		5
// node 1 and 3 are strongly connected, but the bridge will mark 1 and 3 seperately, we have to turn them in a single node
// after bfs/dfs
// 		  0 -- x -- 4 -- 6
//		  |			|
//		  7			5
// x is the new node converted from strongly connected component
// now if we increment the pair of every bridge, we'll se that 7, 5 and 6 is only updated once, hence this is the corner bridges, 
// if somehow we can connect these nodes, out problem is solved

#include <bits/stdc++.h>
using namespace std;

vector<int> G[10010];
vector<pair<int, int> > bridges;
int dfs_num[10010], dfs_low[10010], parent[10010], dfsCounter, bridgeCount;
set<pair<int, int> >bridge;

void findBridge(int u) {
    dfs_low[u] = dfs_num[u] = ++dfsCounter;

    for(int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(dfs_num[v] == 0) {
            parent[v] = u;
            findBridge(v);

            dfs_low[u] = min(dfs_low[v], dfs_low[u]);

            if(dfs_num[u] < dfs_low[v]) {
                bridgeCount++;
                bridges.push_back(make_pair(min(u, v), max(u, v)));
                bridge.insert(make_pair(min(u, v), max(u, v)));
            }

        }
        else if(parent[u] != v)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void dfs(int u) {
    dfs_num[u] = dfsCounter;
    for(int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(dfs_num[v] == -1 && bridge.count(make_pair(min(u, v), max(u, v))) == 0)
            dfs(v);
    }
}

int main() {

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, u, v, V, E;

    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++ Case) {
        scanf("%d%d", &V, &E);
        for(int i = 0; i < E; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        bridgeCount = 0;
        bridge.clear();
        memset(dfs_num, 0, sizeof(dfs_num));
        memset(parent, -1, sizeof(parent));

        for(int i = 0; i < V; ++i) {
            if(dfs_num[i] == 0) {
                dfsCounter = 0;
                findBridge(i);
            }
        }

        //printf("%d Bridge found\n", bridgeCount);

        memset(dfs_num, -1, sizeof(dfs_num));
        dfsCounter = 0;
        for(int i = 0; i < V; ++i) {
            if(dfs_num[i] == -1) {
                dfs(i);
                ++dfsCounter;
            }
        }

        memset(dfs_low, 0, sizeof(dfs_low));
        for(int i = 0; i < (int)bridges.size(); ++i) {
            dfs_low[dfs_num[bridges[i].first]]++;
            dfs_low[dfs_num[bridges[i].second]]++;
        }

        int ans = 0;
        for(int i = 0; i < V; ++i) {
            if(dfs_low[i] == 1)
                ans++;
        }

        printf("Case %d: %d\n", Case, (ans+1)/2);

        if(Case != t) {
            bridges.clear();
            for(int i = 0; i < V; ++i)
                G[i].clear();
        }
    }
    return 0;
}

