// LightOJ
// 1119 - Pimp My Ride

#include <bits/stdc++.h>
using namespace std;

int c[20][20], sum[15][(1 << 15)+10], dp[(1 << 15)+10], n;

void GenSumDP() {
    for(int i = 0; i < n; ++i) {
        sum[i][0] = 0;
        
        for(int j = 0; j < n; ++j)
            for(int mask = (1<<j); mask < (1<<(j+1)); ++mask) {
                sum[i][mask] = sum[i][mask ^ (1<<j)] + c[i][j];
            }
    }
}

int recur(int mask) {
    if(mask == (1<<n)-1)
        return 0;
    int &ret = dp[mask];
    
    if(ret != -1)
        return ret;
    ret = 1e8;
    for(int i = 0; i < n; ++i) {
        if(mask & (1<<i))
            continue;
        int newMask = mask | (1<<i);
        ret = min(ret, recur(newMask)+sum[i][newMask]);
    }
    
    return ret;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &c[i][j]);
        GenSumDP();
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", Case, recur(0));
    }
    return 0;
}
