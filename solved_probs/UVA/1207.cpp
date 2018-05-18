// UVa
// 1207 - AGTC

#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010], l1, l2;
char s1[1010], s2[1010];

int recur(int p1, int p2) {
    if(dp[p1][p2] != -1)
        return dp[p1][p2];
        
    if(p1 == l1 or p2 == l2) {
        if(p1 < l1) return dp[p1][p2] = recur(p1+1, p2)+1;
        if(p2 < l2) return dp[p1][p2] = recur(p1, p2+1)+1;
        return dp[p1][p2] = 0;
    }
    
    if(s1[p1] == s2[p2])
        return dp[p1][p2] = recur(p1+1, p2+1);
    return dp[p1][p2] = min(recur(p1+1, p2), min(recur(p1, p2+1), recur(p1+1, p2+1)))+1;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    while(scanf("%d%s", &l1, s1) == 2) {
        scanf("%d%s", &l2, s2);
        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0, 0));
    }
    
    return 0;
}
        
