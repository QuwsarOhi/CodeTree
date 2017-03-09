//UVa
//12024 - Hats

#include<bits/stdc++.h>
using namespace std;

long long int dp[15];

long long int cal(int n)
{
    if(dp[n] != -1)
        return dp[n];
    if(n == 2)
        return 1;
    if(n < 2)
        return 0;
    else
        return dp[n] = (n-1) * (cal(n-1) + cal(n-2));
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    memset(dp, -1, sizeof(dp));
    int t, n;
    scanf("%d", &t);
    long long int p[15];
    p[0] = p[1] = 1;
    for(int i = 2; i <= 12; i++)
        p[i] = i * p[i-1];
    while(t--) {
        scanf("%d", &n);
        printf("%lld/%lld\n", cal(n), p[n]);
    }
    return 0;
}
