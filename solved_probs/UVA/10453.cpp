// UVa
// 10453 - Make Palindrome

#include <bits/stdc++.h>
#define INF 1e7
using namespace std;

int dp[1010][1010];
char s[1010];
string Palin;

int recur(int l, int r) {
    if(dp[l][r] != INF)
        return dp[l][r];
    if(l >= r)
        return dp[l][r] = 0;
    if(l+1 == r)
        return dp[l][r] = (s[l] != s[r]);
    
    if(s[l] == s[r])
        return dp[l][r] = recur(l+1, r-1);
    return dp[l][r] = min(recur(l+1, r), recur(l, r-1))+1;
}

void dfs(int l, int r) {
    if(l > r)
        return;
    if(s[l] == s[r]) {
        Palin.push_back(s[l]);
        dfs(l+1, r-1);
        if(l != r) Palin.push_back(s[l]);
        return;
    }
    int P = min(make_pair(dp[l+1][r], 1), make_pair(dp[l][r-1], 2)).second;
    if(P == 1) {
        Palin.push_back(s[l]);
        dfs(l+1, r);
        Palin.push_back(s[l]);
    }
    else {
        Palin.push_back(s[r]);
        dfs(l, r-1);
        Palin.push_back(s[r]);
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    while(gets(s)) {
        for(int i = 0; i < 1010; ++i)
            for(int j = 0; j < 1010; ++j)
                dp[i][j] = INF;
        
        int len = strlen(s);
        printf("%d ", recur(0, len-1));
        dfs(0, len-1);
        printf("%s\n", Palin.c_str());
        memset(s, 0, sizeof s);
        Palin.clear();
    }
    return 0;
}
