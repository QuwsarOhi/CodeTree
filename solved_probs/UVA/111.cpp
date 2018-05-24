// UVa
// 111 - History Grading

#include <bits/stdc++.h>
using namespace std;

vector<int>V, G;
bitset<30>vis;
int n, Rank[30], dp[30];

int dfs(int u) {
    if(dp[u] != -1)
        return dp[u];
        
    vis[u] = 1;
    for(int v = u+1; v <= n; ++v) {
        if(!vis[v] and Rank[G[u]] < Rank[G[v]]) {
            //cout << G[u] << " to " << G[v] << endl;
            dp[u] = max(dfs(v), dp[u]);
        }
    }
    vis[u] = 0;
    
    if(dp[u] == -1)
        return dp[u] = 1;
    return ++dp[u];
}
    
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int x;
    char str[30000];
    bool first;
    stringstream ss;
    
    while(fgets(str, 29000, stdin)) {
        ss << string(str);
        while(ss >> x)
            V.push_back(x);
        
        //cout << "INPUT DONE\n";
        
        if(V.size() == 1) {
            n = V[0];
            first = 1;
            //cout << "N taken " << n << endl; 
        }
        else if(first) {
            first = 0;
            int r = 0;
            for(auto it : V)
                Rank[++r] = it;
                
            //for(int i = 1; i <= n; ++i)
            //    cout << Rank[i] << " ";
            //cout << endl;
        }
        else {
            int ans = -1;
            memset(dp, -1, sizeof dp);
            G.resize(n);
            
            for(int i = 0; i < n; ++i)
                G[V[i]] = i+1;
            
            //for(int i = 1; i <= n; ++i)
            //    cout << G[i] << " ";
            //cout << endl;
            
            for(int i = 1; i <= n; ++i) {
                ans = max(dfs(i), ans);
                //cout << V[i] << " : " << dp[i] << endl;
            }
            
            printf("%d\n", ans);
        }
        V.clear();
        ss.clear();
        G.clear();
    }
    
    return 0;
}
