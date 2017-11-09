// LightOJ
// 1232 - Coin Change (II) 

#include <bits/stdc++.h>
#define MOD 100000007
using namespace std;
 
int dp[10002], coin[102];
 
int main() {
    int t, n, k;
    scanf("%d", &t);
   
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d %d", &n, &k);
       
        for(int i = 0; i < n; ++i)
            scanf("%d", &coin[i]);
       
        memset(dp, 0, sizeof dp);
            dp[0] = 1;
       
        //sort(coin, coin+n, greater<int>());
       
        for(int i = 0; i < n; ++i) {
            for(int total = 1; total <= k; ++total) {
                if(total - coin[i] >= 0) {
                    dp[total] = (dp[total] + dp[total-coin[i]])%MOD;
                    //printf("dp[%d][%d] = %d (%d)\n", i, total, dp[total], coin[i]);
                }
            }
        }
       
        printf("Case %d: %d\n", Case, dp[k]);
    }
    return 0;
}
