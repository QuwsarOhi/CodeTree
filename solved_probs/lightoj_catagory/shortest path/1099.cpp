// LightOJ
// 1099 - Not the Best

// Kth Path Using Modified Dikjstra
// Complexity : O(K*(V*logV + E))
// http://codeforces.com/blog/entry/16821

#include <bits/stdc++.h>
#define MAX 5010
using namespace std;
typedef pair<int, int>pii;

vector<int>G[MAX], W[MAX], dist[MAX];
int CNT[MAX], V, E;

int KthDikjstra(int Start, int End, int Kth) {      // Kth Shortest Path (Visits Same Edge More Than Once if required)
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
        else if(dist[u].back() != w) {          // if the weight is not same
            if((int)dist[u].size() < Kth)       // if we have to take more costs, take it
                dist[u].push_back(w);
            else if(dist[u].back() <= w)        // if the cost is greater than previous, then, don't go further
                continue;
            else {                              // we have to take this cost, and remove the greater one
                dist[u].push_back(w);
                sort(dist[u].begin(), dist[u].end());
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
    
    int t, u, v, w;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &V, &E);
        
        for(int i = 0; i < E; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            G[u].push_back(v);
            G[v].push_back(u);
            W[u].push_back(w);
            W[v].push_back(w);
        }
        
        memset(CNT, 0, sizeof CNT);
        int ans = KthDikjstra(0, V-1, 2);
        
        printf("Case %d: %d\n", Case, ans);
        
        for(int i = 0; i < V; ++i)
            G[i].clear(), W[i].clear();
    }
    return 0;
}
