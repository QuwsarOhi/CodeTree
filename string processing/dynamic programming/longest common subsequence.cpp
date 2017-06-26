//UVa
//10192 - Vacation
//Longest Common SubSequence
//Dynamic Programming

#include<bits/stdc++.h>
using namespace std;



int LCS(char a, char b, int len_a, int len_b) {      //longest common subsequence
	int dp[210][210];
    for(register int i = 1; i <= len_a; i++)
        for(register int j = 1; j <= len_b; j++) {
            if(i == 0 || j == 0)                    //base case
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])               //if a match found
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);     // dp[i][j] = max(ignoring b[j-1] (taking b[j]), ignoring a[i-1] (taking a[i]))
        }
    return dp[len_a][len_b];
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int Case = 1;
    while(1) {
        fgets(a, 150, stdin);
        if(a[0] == '#')
            break;
        fgets(b, 150, stdin);
        len_a = strlen(a);
        len_b = strlen(b);
        //fgets function also inputs the '\n' which is also a common sub sequence, so minus 1 for it
        printf("Case #%d: you can visit at most %d cities.\n", Case++, LCS()-1);
    }
}
