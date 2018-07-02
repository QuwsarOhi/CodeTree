#include <bits/stdc++.h>
#define MOD 100000007
using namespace std;

int dp[1001][15001], n, k, s;

int recur(int pos, int val) {
    if(pos == n)
        return (val == s);
    if(val > s)
        return 0;
    
    int &ret = dp[pos][val];
    if(ret != -1)
        return ret;
    
    ret = 0;
    for(int i = 1; i <= k; ++i) {
        ret += recur(pos+1, val+i);
        if(ret > MOD)
            ret %= MOD;
    }
    
    return ret;
}

// 2 10 10

// 

int main() {
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d", &n, &k, &s);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", Case, recur(0, 0)%MOD);
    }
    return 0;
}
