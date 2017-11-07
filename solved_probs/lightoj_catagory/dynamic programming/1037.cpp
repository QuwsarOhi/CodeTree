// LightOJ
// 1037 - Agent 47

#include <bits/stdc++.h>
#define isOn(x, i) (x & (1<<i))
using namespace std;

int v[20], g[20][20], dp[(1<<15)+10], n;

int recur(int mask) {
    if(mask == (1<<n)-1)
        return 0;
        
    if(dp[mask] != -1)
        return dp[mask];
    
    int ans = 1e8;
    
    for(int i = 0; i < n; ++i) {
        if(isOn(mask, i))
            continue;
        ans = min(recur(mask | (1<<i))+v[i], ans);          // kill i with USP
        for(int j = 0; j < n; ++j) {
            if(isOn(mask, j)) {                             // if we killed j
                if(g[j][i] == 0 || i == j)                  // if j has a weapon that can also kill i
                    continue;
            
                int shots = ceil(v[i] / (float)g[j][i]);    // try this weapon also (j's weapon that can kill i (we killed j in previous recursion))
                ans = min(recur(mask | (1<<i))+shots, ans);     // kill i with j's weapon
            }
        }
    }
    
    return dp[mask] = ans;
}

int main() {
    int t;
    char x;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                scanf(" %c", &x);
                g[i][j] = int(x - '0');
            }
        
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", Case, recur(0));
    }
    return 0;
}
