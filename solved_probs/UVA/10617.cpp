// UVa
// 10617 - Again Palindrome

#include <bits/stdc++.h>
using namespace std;

char s[100];
long long dp[61][61], len;

long long palindromeCount(int l, int r) {
    if(l > r)           return 0;
    if(l == r)          return 1;
    if(dp[l][r] != -1)  return dp[l][r];
    if(s[l] == s[r])    return dp[l][r] = palindromeCount(l+1, r)+palindromeCount(l, r-1)+1;
    return dp[l][r] = palindromeCount(l+1, r)+palindromeCount(l, r-1)-palindromeCount(l+1, r-1);
}
    
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        len = strlen(s);
        memset(dp, -1, sizeof dp);
        printf("%lld\n", palindromeCount(0, len-1));
    }
    return 0;
}
