// LightOJ
// 1110 - An Easy LCS

#include <bits/stdc++.h>
using namespace std;

int dp[101][101], l1, l2;
char s1[200], s2[200];
string s[101][101];
vector<char>T, ans;

int recur(int p1, int p2) {
    if(p1 >= l1 || p2 >= l2)
        return dp[p1][p2] = 0;

    int &ret = dp[p1][p2];
    string &ss = s[p1][p2];
    
    if(ret != -1) 
        return ret;
    
    if(s1[p1] == s2[p2]) {
        ret = recur(p1+1, p2+1)+1;
        ss += s1[p1];
        ss += s[p1+1][p2+1];
    }
        
    ret = max(ret, max(recur(p1+1, p2), recur(p1, p2+1)));
    
    if(ret == recur(p1+1, p2)) {
        if(ss.empty()) ss = s[p1+1][p2];
        else ss = min(ss, s[p1+1][p2]);
    }
    
    if(ret == recur(p1, p2+1)) {
        if(ss.empty()) ss = s[p1][p2+1];
        else ss = min(ss, s[p1][p2+1]);
    }
    return ret;
}
    
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%s%s", s1, s2);
        l1 = strlen(s1);
        l2 = strlen(s2);
        
        memset(dp, -1, sizeof dp);
        int ret = recur(0, 0);
        
        printf("Case %d: ", Case);
        if(ret <= 0) printf(":(\n");
        else printf("%s\n", s[0][0].c_str());
        
        int l = max(l1, l2);
        for(int i = 0; i <= l; ++i)
            for(int j = 0; j <= l; ++j)
                s[i][j].clear();
        ans.clear();
    }
    return 0;
}
