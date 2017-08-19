//UVa
//11258 - String Partition
//String DP

#include<bits/stdc++.h>
using namespace std;

char S[300];
unsigned long long dp[205];

/*
as the number limit is 2147483647, which is 10 of length,
we can check the input number from back, and take from 1-10 numbers and check for
the max sum of the number
if in any case the number stands bigger than 2147483647, we should ignore that
*/

long long can_be_used(int i, int j)
{
    if(i == j)
        return S[i] - '0';
    unsigned long long sum;
    sum = 0;
    while(i <= j) {
        sum *= 10;
        sum += S[i] - '0';
        if(sum > 2147483647)
            return -1;
        i++;
    }
    return sum;
}

unsigned long long cmp(int len)
{
    if(len < 0)
        return 0;
    if(dp[len] != -1) {
        return dp[len];
    unsigned long long mx = 0;
    for(int i = 0; i < 10 && len - i >= 0; i++) {
        long long x = can_be_used(len-i, len);
        if(x != -1)
            mx = max(cmp(len-i-1)+x, mx);
    }
    dp[len] = mx;
    return mx;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    getchar();
    while(t--) {
        scanf(" %s", S);
        memset(dp, -1, sizeof(dp));
        int len = strlen(S);
        printf("%llu\n", cmp(len-1));
    }
    return 0;
}
