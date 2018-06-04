// LightOJ
// 1073 - DNA Sequence

#include <bits/stdc++.h>
#define INF 1e7
#define isOn(XX, II)    (XX & (1<<II))
using namespace std;

string v[20];
int n, step = 0;
int matchDP[20][20];

int TryMatch(int x, int y) {
    if(matchDP[x][y] != -1)
        return matchDP[x][y];
    for(size_t i = 0; i < v[x].size(); ++i) {
        for(size_t j = i, k = 0; j < v[x].size() && k < v[y].size(); ++j, ++k)
            if(v[x][j] != v[y][k])
                goto pass;
        return matchDP[x][y] = i;
        pass:;
    }
    return matchDP[x][y] = v[x].size();
}

int dp[16][(1<<15)+100];
int recur(int mask, int last) {
    if(dp[last][mask] != -1)
        return dp[last][mask];
        
    if(mask == (1<<n)-1)
        return dp[last][mask] = v[last].size();
    
    int ret = INF, cost;
    for(int i = 0; i < n; ++i) {
        if(isOn(mask, i))
            continue;

        int mPos = TryMatch(last, i);
        if(mPos < (int)v[last].size())
            cost = (int)v[last].size() - ((int)v[last].size() - mPos);
        else
            cost = v[last].size();
        ret = min(ret, recur(mask | (1 << i), i) + cost);
    }
    return dp[last][mask] = ret;
}


string ans;
void dfs(int mask, int last, string ret) {
    if(!ret.empty() && ans < ret)
        return;
        
    if(mask == (1<<n)-1) {
        ret += v[last];
        if(ret < ans)
            ans = ret;
        return;
    }
    
    for(int i = 0; i < n; ++i) {
        if(isOn(mask, i))
            continue;
        int mPos = TryMatch(last, i);
        int cost;
        if(mPos < (int)v[last].size())
            cost = (int)v[last].size() - ((int)v[last].size() - mPos);
        else
            cost = v[last].size();
        if(dp[last][mask] - cost == dp[i][mask | (1<<i)])
            dfs(mask | (1<<i), i, ret + v[last].substr(0, cost));
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out2", "w", stdout);

    int t;
    cin >> t;
    string s[20];
    
    for(int Case = 1; Case <= t; ++Case) {
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> s[i];
        sort(s, s+n);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                if(s[i].find(s[j]) != string::npos && s[j].size() <= s[i].size())
                    s[j] = "";
            }
            
        int T = 0;
        for(int i = 0; i < n; ++i)
            if(s[i] != "")
                v[T++] = s[i];
        n = T;
        
        memset(matchDP, -1, sizeof matchDP);
        memset(dp, -1, sizeof dp);
    
        int ret = INF;
        for(int i = 0; i < n; ++i)
            ret = min(ret, recur(1 << i, i));
        ans = "X";
        for(int i = 0; i < n; ++i)
            if(dp[i][1 << i] == ret)
                dfs(1<<i, i, "");
        
        cout << "Case " << Case << ": " << ans << "\n";
    }
    return 0;
}

