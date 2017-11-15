// LightOJ
// 1044 - Palindrome Partitioning
// Complexity : n^2

#include <bits/stdc++.h>
using namespace std;

char s[1010];
int dp[1002][1002], posDP[1003], len;

bool isPalindrome(int l, int r) {
    if(l == r || l > r)
        return 1;
    
    if(dp[l][r] != -1)
        return dp[l][r];
    
    if(s[l] == s[r])
        return dp[l][r] = isPalindrome(l+1, r-1);

    return 0;
}

int recur(int l) {
    if(l >= len)
        return 0;
    int ans = INT_MAX;
    
    if(posDP[l] != -1)
        return posDP[l];
        
    for(int r = l; r < len; ++r) {
        if(isPalindrome(l, r))
            ans = min(ans, recur(r+1)+1);
    }
    return posDP[l] = ans;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%s", s);
        len = strlen(s);
        memset(dp, -1, sizeof dp);
        memset(posDP, -1, sizeof posDP);
        printf("Case %d: %d\n", Case, recur(0));
    }
    return 0;
}
