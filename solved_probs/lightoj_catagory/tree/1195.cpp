// LightOJ
// 1195 - Similar Trees
// Tree Matching

// Find if the sum of child of two trees are same

#include <bits/stdc++.h>
#define MAX 10010
using namespace std;

vector<int>G[2][MAX];           // {Random Value, node}
char s[2][10100];
vector<int>T1, T2;

int nodeVal;
void BuildGrap(int u, int &pos, int lvl, int gNO) {
    while(s[gNO][pos] == '1') {
        G[gNO][u].push_back(++nodeVal), ++pos;
        BuildGrap(nodeVal, pos, lvl+1, gNO);
    }
    pos++;
}

int dp[2][MAX];
int dfs(int u, int gNO) {
    int ret = 1;
    if(dp[gNO][u] != -1)
        return dp[gNO][u];
    
    for(int i = 0; i < (int)G[gNO][u].size(); ++i)
        ret += dfs(G[gNO][u][i], gNO);
    return dp[gNO][u] = ret;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, pos;
    scanf("%d", &t);
    getchar();
    for(int Case = 1; Case <= t; ++Case) {
        gets(s[0]);
        gets(s[1]);
        
        pos = nodeVal = 0;
        BuildGrap(0, pos, 0, 0);
        pos = nodeVal = 0;
        BuildGrap(0, pos, 0, 1);

        memset(dp, -1, sizeof dp);
        for(int i = 0; i < MAX; ++i) {
            T1.push_back(dfs(i, 0));
            T2.push_back(dfs(i, 1));
        }
        
        sort(T1.begin(), T1.end());
        sort(T2.begin(), T2.end());
        bool ok = (T1.size() == T2.size());
        for(int i = 0; i < (int)T1.size(); ++i)
            if(T1[i] != T2[i])
                ok = 0;
        
        printf("Case %d: %s\n", Case, (!ok)?"Different":"Same");
        for(int i = 0; i < MAX; ++i)
            G[0][i].clear(), G[1][i].clear();
        T1.clear(), T2.clear();
    }
    return 0;
}
