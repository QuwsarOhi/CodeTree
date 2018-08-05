// LightOJ
// 1200 - Thief

#include <bits/stdc++.h>
using namespace std;

int dp[10005], p[101], c[101], w[101], n, W;

int recur(int weight) {
    if(weight >= W)
        return 0;
    
    int &ret = dp[weight];
    if(ret != -1) return ret;
    
    ret = 0;
    for(int i = 0; i < n; ++i)
        if(weight+w[i] <= W)
            ret = max(ret, recur(weight+w[i])+p[i]);
    return ret;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &W);
        
        int preW = 0, preCst = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d%d%d", &p[i], &c[i], &w[i]);
            preW += c[i]*w[i];
            preCst += c[i]*p[i];
        }
        
        memset(dp, -1, sizeof dp);
        if(preW > W)
            printf("Case %d: Impossible\n", Case);
        else
            printf("Case %d: %d\n", Case, recur(preW));
    }
    
    return 0;
}
