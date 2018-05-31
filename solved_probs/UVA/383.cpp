// UVa
// 383 - Shipping Routes

#include <bits/stdc++.h>
#define INF 1e6
#define isOn(XX, II) (XX & (1<<II))
using namespace std;

int MapCnt;
map<string, int>Map;
vector<int>G[35];

int Conv(char ss[]) {
    string s = string(ss);
    if(Map.find(s) == Map.end()) {
        Map[s] = MapCnt;
        return MapCnt++;
    }
    return Map[s];
}

bitset<35>vis;
int bfs(int u, int to) {
    vis.reset();
    vis[u] = 1;
    queue<pair<int, int> >q;
    q.push({u, 0});
    
    while(!q.empty()) {
        u = q.front().first;
        int w = q.front().second;
        q.pop();
        
        if(u == to)
            return w;
        
        for(auto v : G[u])
            if(not vis[v]) {
                vis[v] = 1;
                q.push({v, w+1});
            }
    }
    
    return -1;
}
    

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int V, E, q, t, u, v, w;
    char s1[5], s2[5];
    scanf("%d", &t);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d", &V, &E, &q);
        printf("DATA SET  %d\n\n", Case);
        
        while(V--) {
            scanf("%s", s1);
            Conv(s1);
        }
        
        while(E--) {
            scanf("%s%s", s1, s2);
            u = Conv(s1), v = Conv(s2);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        while(q--) {
            scanf("%d%s%s", &w, s1, s2);
            int ret = bfs(Conv(s1), Conv(s2));
            if(ret == -1) printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n", w*ret*100);
        }
        
        MapCnt = 0;
        Map.clear();
        for(int i = 0; i <= 30; ++i) G[i].clear();
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
