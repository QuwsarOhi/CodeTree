// LightOJ
// 1079 - Just another Robbery

#include <bits/stdc++.h>
#define INF 1e7
using namespace std;

double dp[101][10001];
double p[101], tmp;
int v[101], n;

double recur(int val, int pos = n) {
    if(val == 0)
        return 0;
    if(pos == 0)
        return INF;
    
    if(dp[pos][val] != INF)
        return dp[pos][val];
    
    double ret = p[pos] + (1-p[pos]) * recur(val-v[pos], pos-1);
    ret = min(ret, recur(val, pos-1));
    return dp[pos][val] = ret;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, TOT;
    double lim;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lf %d", &lim, &n);
        TOT = 0;
        
        for(int i = 1; i <= n; ++i) {
            scanf("%d%lf", &v[i], &p[i]);
            TOT += v[i];
        }
        
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= TOT; ++j)
                dp[i][j] = INF;
        
        int ans = 0;
        for(int i = 1; i <= TOT; ++i)
            if(recur(i) < lim)
                ans = i;
        
        //recur(0, 0);
        //int ans = solve(TOT, lim);
        /*for(int i = 0; i < n; ++i)
            for(int j = 0; j <= TOT; ++j)
                if(dp[i][j] < lim) {
                    cerr << i << " " << j << " " << dp[i][j] << endl;
                    ans = max(ans, j);
                }
        */
        printf("Case %d: %d\n", Case, ans);
    }
    return 0;
}
