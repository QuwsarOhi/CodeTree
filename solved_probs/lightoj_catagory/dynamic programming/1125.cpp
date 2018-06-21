// LightOJ
// 1125 - Divisible Group Sums

#include <bits/stdc++.h>
using namespace std;

long long d, m, n, v[210], dp[201][20][11];

long long recur(int pos, int taken, int sum) {
    if(pos >= n || taken == m) {
        if(taken == m) return (sum == 0);
        return 0;
    }
    long long &ret = dp[pos][sum][taken];
    
    if(ret != -1) 
        return ret;
    
    ret = recur(pos+1, taken+1, (d+(sum+v[pos])%d)%d) + recur(pos+1, taken, sum);
    return ret;
}
    
int main() {
    int t, q;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%d", &n, &q);
        for(int i = 0; i < n; ++i) scanf("%lld", &v[i]);
        
        printf("Case %d:\n", Case);
        while(q--) {
            scanf("%lld%lld", &d, &m);
            memset(dp, -1, sizeof dp);
            printf("%lld\n", recur(0, 0, 0));
        }
    }
    return 0;
}
