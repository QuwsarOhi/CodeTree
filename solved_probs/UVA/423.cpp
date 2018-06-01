// UVa
// 423 - MPI Maelstrom

#include <bits/stdc++.h>
#define MAX 150
#define INF 1e7
using namespace std;

int dist[MAX];
vector<int>G[MAX], W[MAX];

void dfs(int u) {
    for(int i = 0; i < MAX; ++i)
        dist[i] = INF;
    
    dist[u] = 0;
    priority_queue<pair<int, int> >pq;
    pq.push({0, u});
    
    while(!pq.empty()) {
        u = pq.top().second;
        int w = -pq.top().first;
        pq.pop();
        
        if(dist[u] < w)
            continue;
        
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            int _w = W[u][i] + w;
            
            if(dist[v] <= _w)
                continue;
            
            dist[v] = _w;
            pq.push({-_w, v});
        }
    }
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, w;
    string str;
    
    while(scanf("%d", &n) == 1) {
        getline(cin, str);
        for(int u = 2; u <= n; ++u) {
            getline(cin, str);
            stringstream ss;
            ss << str;
            for(int v = 1; v < u; ++v) {
                ss >> str;
                if(str[0] == 'x')
                    continue;
                w = stoi(str, 0);
                G[u].push_back(v);
                G[v].push_back(u);
                W[u].push_back(w);
                W[v].push_back(w);
            }
        }
        dfs(1);
        
        int ans = -1;
        for(int i = 1; i <= n; ++i)
            ans = max(dist[i], ans);
        
        printf("%d\n", ans);
        
        for(int i = 1; i <= n; ++i)
            G[i].clear(), W[i].clear();
    }
    return 0;
}
