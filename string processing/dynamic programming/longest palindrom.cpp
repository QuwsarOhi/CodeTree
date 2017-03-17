//UVa
//11151 - Longest Palindrome
//DP, String Processing
#include<bits/stdc++.h>
using namespace std;

char S[1010];
int dp[1010][1010], len;

int palindrom(int l, int r)
{
    if(dp[l][r] != -1)              //memorization
        return dp[l][r];
    else if(l == r)                 //if the middle point reached (odd length of a string)
        return dp[l][r] = 1;
    else if(l+1 == r) {             //if the two points are middle (even length of a string)
        if(S[l] == S[r])
            return dp[l][r] = 2;    //if matches, we can take them both
        else
            return dp[l][r] = 1;    //else we can take only one of them
    }
    else {
        if(S[l] == S[r])            //if the first and the last character is matched, then we can take them both and go deeper
            dp[l][r] = 2 + palindrom(l+1, r-1);
        else                        //else we will search for the best choice
            dp[l][r] = max(palindrom(l+1, r), palindrom(l, r-1));
    }
    return dp[l][r];
}


int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    getchar();
    while(t--) {
        fgets(S, 1005, stdin);
        for(int i = 0; i<=1001; i++)
            for(int j = 0; j<=1001; j++)
                dp[i][j] = -1;
        len = strlen(S) - 1;
        if(len == 0 && S[0] == '\n')
            printf("0\n");
        else
            printf("%d\n", palindrom(0, len));
    }
    return 0;
}
