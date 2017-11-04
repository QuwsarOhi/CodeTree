// LightOJ
// 1034 - Hit the Light Switches

#include <bits/stdc++.h>
using namespace std;

vector<int>G[10010], G1[10010], SCC;
int indegree[10010], dfs_num[10010], dfs_low[10010], dfsCounter, SCC_no;
bitset<10010>visited;
map<int, int>Component;

void tarjanSSC(int u) {
    SCC.push_back(u);
    visited[u] = 1;
    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(dfs_num[v] == 0) {
            tarjanSSC(v);
        }
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u]) {
        SCC_no++;
        while(1) {
            int v = SCC.back();
            SCC.pop_back();
            visited[v] = 0;
            Component[v] = SCC_no;
            if(u == v)
                break;
        }
    }
}

int topsort(int V) {
    for(int u = 1; u <= V; ++u) {
        for(int i = 0; i < (int)G1[u].size(); ++i) {
            int v = G1[u][i];
            indegree[v]++;
        }
    }
    
    queue<int>q;
    int  cnt = 0;
    for(int u = 1; u <= V; ++u)
        if(indegree[u] == 0) {
            ++cnt;
            q.push(u);
        }
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)G1[u].size(); ++i) {
            int v = G1[u][i];
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }
    return cnt;
}

void ConnectNode() {
    map<int, int> :: iterator it = Component.begin();
    
    for(; it != Component.end(); ++it) {
        for(int i = 0; i < (int)G[it->first].size(); ++i) {
            int v = G[it->first][i];
            if(it->second == Component[v])
                continue;
            G1[it->second].push_back(Component[v]);
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, V, E, u, v;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d %d", &V, &E);
        
        memset(indegree, 0, sizeof indegree);
        memset(dfs_low, 0, sizeof dfs_low);
        memset(dfs_num, 0, sizeof dfs_num);
        visited.reset();
        SCC_no = 0;
        dfsCounter = 0;
        
        for(int i = 0; i < E; ++i) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
        }
        
        for(int i = 1; i <= V; ++i) {
            if(dfs_num[i] == 0) {
                tarjanSSC(i);      
            }
        }
        ConnectNode();
        int ans = topsort(SCC_no);
        
        
        printf("Case %d: %d\n", Case, ans);
        for(int i = 0; i <= V; ++i) {
            G[i].clear();
            G1[i].clear();
        }
        Component.clear();
    }
    return 0;
}
        
