//11310 - Delivery Debacle

#include<bits/stdc++.h>
using namespace std;

long long dp[50];

long long compute(int n)
{
    if(n < 0)
        return 0;
    else if(dp[n] != -1)
        return dp[n];
    else
        return (dp[n] = compute(n-1) + 4 * compute(n-2) + 2 * compute(n-3));
        //normally cakes in one column can be put in only 1 way, so we exclude 1 column and compute the others, then it is: 1 * all other n-1 column
        //cakes in 2 columns can be put in 4 ways, so 4 * n-2 column
        //cakes in 3 column can be put in 2 ways, so 2 * n-3 column
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    memset(dp, -1, sizeof(dp));
    dp[0] = dp[1] = 1;
    dp[2] = 5;
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%lld\n", compute(n));
    }
    return 0;
}
