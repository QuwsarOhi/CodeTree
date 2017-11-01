// LightOJ
// 1031 - Easy Game 
#include <bits/stdc++.h>
using namespace std;

int v[120], dp[103][103];

int recur(int l, int r) {
    if(l > r)
        return 0;
    if(l == r)
        return v[l];
    
    if(dp[l][r] != -1)
        return dp[l][r];
    
    int mx = -1e8, cSum = 0;
    for(int i = l; i <= r; ++i) {
        cSum += v[i];
        mx = max(cSum - recur(i+1, r), mx);
    }
    cSum = 0;
    for(int i = r; l <= i; --i) {
        cSum += v[i];
        mx = max(cSum - recur(l, i-1), mx);
    }
    
    return dp[l][r] = mx;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, n;
    scanf("%d", &t);
    for(int Case = 1; Case <=t; ++Case) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
            
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", Case, recur(0, n-1));
    }
    
    return 0;
}
