//UVa
//10635 - Prince and Princess
//Longest common subsequence

#include<bits/stdc++.h>
using namespace std;

int p, q, n, Q[6300], P[6300], dp[6300][6300];

int LCS()
{
    p++, q++;
    for(int i = 0; i <= p; i++)
        for(int j = 0; j <= q; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(P[i-1] == Q[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    /*for(int i = 0; i <= p; i++) {
        for(int j = 0; j <= q; j++)
            printf("%3d ", dp[i][j]);
        printf("\n");
    }*/

    return dp[p][q];
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d %d %d", &n, &p, &q);
        for(int i = 0; i <= p; i++)
            scanf("%d", &P[i]);
        for(int i = 0; i <= q; i++)
            scanf("%d", &Q[i]);
        printf("Case %d: %d\n", Case, LCS());
    }
    return 0;
}
