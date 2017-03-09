//UVa
//10759 - Dice Throwing
#include<bits/stdc++.h>
using namespace std;

unsigned long long dp[30][160], p[30];
int total;

unsigned long long compute(int dice_left, int total_sum)
{
    if(dice_left == 0) {
        if(total_sum <= 0)
            return 1;
        else
            return 0;
    }
    if(dp[dice_left][total_sum] != -1)
        return dp[dice_left][total_sum];
    unsigned long long sum = 0;
    for(int i = 1; i <= 6; i++)
        sum += compute(dice_left-1, total_sum-i);
    return dp[dice_left][total_sum] = sum;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    p[0] = 1;
    for(int i = 1; i <= 25; i++)
        p[i] = p[i-1] * 6;
    int dice;
    while(scanf("%d %d", &dice, &total) && (total || dice)) {
        memset(dp, -1, sizeof(dp));
        unsigned long long ans = compute(dice, total);
        if(ans == p[dice])
            printf("1\n");
        else if(ans == 0)
            printf("0\n");
        else {
            unsigned long long gcd = __gcd(ans, p[dice]);
            printf("%llu/%llu\n", ans/gcd, p[dice]/gcd);
        }
    }
    return 0;
}
