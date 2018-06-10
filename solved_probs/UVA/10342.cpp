// UVa
// 10342 - Always Late

// Kth Path Using Modified Dikjstra (can use same edge more than once)
// Complexity : O(K*(V*logV + E))
// http://codeforces.com/blog/entry/16821

#include <bits/stdc++.h>
#define MAX 110
using namespace std;
typedef pair<int, int>pii;
 
vector<int>G[MAX], W[MAX], dist[MAX];

int KthDikjstra(int Start, int End, int Kth) {
    for(int i = 0; i < MAX; ++i)
        dist[i].clear();
    priority_queue<pii>pq;                  // Weight, Node
    pq.push(make_pair(0, Start));
    
    while(!pq.empty()) {
        int u = pq.top().second;
        int w = -pq.top().first;
        pq.pop();

        if(dist[u].empty())
            dist[u].push_back(w);
        else if(dist[u].back() != w) {
            if((int)dist[u].size() < Kth)
                dist[u].push_back(w);
            else if(dist[u].back() <= w)
                continue;
            else {
                dist[u].push_back(w);
                sort(dist[u].begin(), dist[u].end());
                //while((int)dist[u].size() > Kth)
                    dist[u].pop_back();
        }}
        
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            int _w = w + W[u][i];
            pq.push(make_pair(-_w, v));
    }}
    if((int)dist[End].size() < Kth)
        return -1;
    return dist[End].back();
}

 
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
   
    int u, v, w, V, E, q, Case = 1;
    
    while(scanf("%d%d", &V, &E) == 2) {
        for(int i = 0; i < E; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(v);
            G[v].push_back(u);
            W[u].push_back(w);
            W[v].push_back(w);
        }
        
        scanf("%d", &q);
        printf("Set #%d\n", Case++);
        while(q--) {
            scanf("%d %d", &u, &v);
            int ans = KthDikjstra(u, v, 2);
            if(ans == -1) printf("?\n");
            else printf("%d\n", ans);
        }
        
        for(int i = 0; i < V; ++i)
            G[i].clear(), W[i].clear();
    }
    return 0;
}
