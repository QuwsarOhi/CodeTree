// LightOJ
// 1126 - Building Twin Towers

#include <bits/stdc++.h>
using namespace std;

int n, v[110];

int dp[2][500010];
int BottomUp(int TOT) {
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    bool present = 0, past = 1;
    for(int i = 0; i < n; ++i) {
        present ^= 1, past ^= 1;
        for(int diff = 0; diff <= TOT; ++diff)
            if(dp[past][diff] != -1) {
                int moreDiff = diff + v[i], lessDiff = abs(diff - v[i]);
                dp[present][diff] = max(dp[present][diff], dp[past][diff]);
                dp[present][lessDiff] = max(dp[present][lessDiff], max(dp[past][lessDiff], dp[past][diff] + v[i]));
                dp[present][moreDiff] = max(dp[present][moreDiff], max(dp[past][moreDiff], dp[past][diff] + v[i]));
    }}
    return max(dp[0][0], dp[1][0]);
}



int main() {
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        
        for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
        sort(v, v+n);
        int sum = accumulate(v, v+n, 0);
        int ret = BottomUp((sum+1)/2);
        if(ret == 0)    printf("Case %d: impossible\n", Case);
        else            printf("Case %d: %d\n", Case, ret/2);
    }
    return 0;
}

