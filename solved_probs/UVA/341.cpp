// UVa
// 341 - Non-Stop Travel

#include <bits/stdc++.h>
#define isOn(XX, II) (XX & (1<<II))
using namespace std;

vector<int>G[12], W[12], T, ANS;
int MIN;

void dfs(int u, int destination, int cost, int mask) {
    if(u == destination) {
        if(cost < MIN) {
            ANS = T;
            MIN = cost;
        }
        else if(cost == MIN and T.size() < ANS.size())
            ANS = T;
        return;
    }
    
    for(int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(not isOn(mask, v)) {
            //cout << "FROM " << u << " TO " << v << " : " << W[u][i] << endl;
            T.push_back(v);
            dfs(v, destination, cost + W[u][i], mask | (1<<v));
            T.pop_back();
        }
    }
}
                
        

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, u, v, w, E, Case = 1;
    
    while(scanf("%d", &n) and n) {
        for(u = 1; u <= n; ++u) {
            scanf("%d", &E);
            while(E--) {
                //cout << u << " TO " << v << endl;
                scanf("%d%d", &v, &w);
                G[u].push_back(v);
                W[u].push_back(w);
            }
        }
        MIN = 1e8;
        scanf("%d%d", &u, &v);
        T.push_back(u);
        dfs(u, v, 0, 0);
        
        printf("Case %d: Path =", Case++);
        for(auto it : ANS) printf(" %d", it);
        printf("; %d second delay\n", MIN);
        
        
        for(int i = 1; i <= 10; ++i)
            G[i].clear(), W[i].clear();
        T.clear();
        ANS.clear();
    }
    return 0;
}
