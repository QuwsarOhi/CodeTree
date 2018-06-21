// LightOJ
// 1122 - Digit Count

#include <bits/stdc++.h>
using namespace std;

int n, m, v[10], dp[10][10];

int recur(int lastVal, int len) {
    if(len == m)
        return 1;
    
    int &ret = dp[lastVal][len];
    if(ret != -1)
        return ret;
    
    ret = 0;
    if(lastVal == 0) {
        for(int i = 1; i <= 9; ++i)
            if(v[i]) ret += recur(i, len+1);
        return ret;
    }
    
    for(int i = lastVal-2; i <= lastVal+2; ++i) {
        if(i < 1 || i > 9 || !v[i]) continue;
        ret += recur(i, len+1);
    }
    
    return ret;
}
    
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, x;
    scanf("%d", &t);
    
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);
        
        memset(v, 0, sizeof v);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            v[x] = 1;
        }
        
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", Case, recur(0, 0));
    }
    
    return 0;
}
