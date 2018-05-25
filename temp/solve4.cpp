// UVa
// 166 - Making Change
// DP

#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int val[] = {5, 10, 20, 50, 100, 200}, c[6], dp[700], target, ans;

int shopkeeper(int n) {
    if(n == target)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];
    
    int ret = INF;
    for(int i = 0; i < 6; ++i)
        if(n-val[i] >= target)
            ret = min(ret, shopkeeper(n - val[i])+1);
    
    return dp[n] = ret;
}

void customer(int pos, int n, int k) {
    if(n >= 700)
        return;
    
    if(n >= target) {
        memset(dp, -1, sizeof dp);
        ans = min(shopkeeper(n)+k, ans);
    }
    
    if(pos == 6 or ans <= k)
        return;
    
    for(int i = 0; i <= c[pos]; ++i)
        customer(pos+1, val[pos]*i + n, k+i);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    while(1) {
        bool ok = 1;
        for(int i = 0; i < 6; ++i) {
            scanf("%d", &c[i]);
            if(c[i]) ok = 0;
        }
        
        if(ok) break;
        
        int a, b;
        scanf("%d.%d", &a, &b);
        target = a*100 + b;
        
        ans = INF;
        customer(0, 0, 0);
        printf("%3d\n", ans);
    }
    
    return 0;
}
