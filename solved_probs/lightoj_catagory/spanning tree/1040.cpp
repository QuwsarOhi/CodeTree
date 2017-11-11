// LightOJ
// 1040 - Donation

#include <bits/stdc++.h>
#define MAX 70
using namespace std;

vector<int>G[MAX], W[MAX];
bitset<MAX>taken;
priority_queue<pair<int, int> >pq;

void process(int u) {
    taken[u] = 1;
    
    for(int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        int w = W[u][i];
        if(!taken[v])
            pq.push(make_pair(-w, -v));
    }
}

int MST() {
    taken.reset();
    process(0);
    int mst_cost = 0;
    while(!pq.empty()) {
        int w = -pq.top().first;
        int v = -pq.top().second;
        pq.pop();
        
        if(!taken[v]) {
            mst_cost += w;
            process(v);
        }
    }
    return mst_cost;
}
        

int main() {
    //freopen("in", "r", stdin);
    int t, n, w;
    
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        
        int total = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &w);
                if(i != j && w > 0) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                    W[i].push_back(w);
                    W[j].push_back(w);
                }
                total += w;
            }
        }
        
        int mst = MST();
        printf("Case %d: ", Case);
        if((int)taken.count() != n)
            printf("-1\n");
        else
            printf("%d\n", total-mst);
        
        for(int i = 0; i < n; ++i) {
            G[i].clear();
            W[i].clear();
        }
    }
    return 0;
}
