#include <bits/stdc++.h>
using namespace std;

char s[2000];
int dp[1010][1010];

int recur(int l, int r) {
    if(l > r)
        return 1e7;
    
    if(dp[l][r] != -1)
        return dp[l][r];
    if(l == r)
        return 0;
    else if(l+1 == r)
        return s[l] != s[r];
    else if(s[l] == s[r])
        return dp[l][r] = recur(l+1, r-1);
    else
        return dp[l][r] = min(recur(l+1, r), min(recur(l, r-1), recur(l+1, r-1)))+1;
}


int main() {
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%s", s);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", Case, recur(0, strlen(s)-1));
    }
    return 0;
}
