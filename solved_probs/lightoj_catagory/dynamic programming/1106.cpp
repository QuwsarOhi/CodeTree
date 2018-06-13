// LightOJ
// 1106 - Gone Fishing

#include <bits/stdc++.h>
#define MAX 1000
#define INF 1e8
using namespace std;

int t[MAX], d[MAX], f[MAX], n;
int dp[30][MAX];

int recur(int pos, int Time) {
    if(pos == n || Time <= 0)
        return dp[pos][Time<0?0:Time] = 0;
    
    int &ret = dp[pos][Time];
    
    if(ret != -1)
        return ret;
        
    int fish = f[pos], taken = 0;
    
    do {
        ret = max(ret, recur(pos+1, Time-t[pos])+taken);            // Negative TIME???
        taken += (fish>0 ? fish:0);
        fish -= d[pos];
        Time -= 5;
    } while(Time >= 0);
    
    return ret;
}

vector<int> T, ans;
void dfs(int pos, int Time, int TOT) {
    if(!ans.empty() && T < ans)
        return;
    
    if(pos == n || Time <= 0) {
        ans = T;
        return;
    }
    
    int fish = f[pos], taken = 0, stay = 0;
    do {
        if(TOT == taken + dp[pos+1][Time-t[pos]<0?0:Time-t[pos]]) {
            T.push_back(stay);
            dfs(pos+1, Time-t[pos], TOT - taken);
            T.pop_back();
        }
        
        taken += (fish>0 ? fish:0);
        fish -= d[pos];
        Time -= 5;
        stay += 5;
    } while(Time >= 0);
    
    return;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int tc, h;
    scanf("%d", &tc);
    
    for(int Case = 1; Case <= tc; ++Case) {
        scanf("%d%d", &n, &h);
        h *= 60;
        
        for(int i = 0; i < n; ++i)
            scanf("%d", &f[i]);
        
        for(int i = 0; i < n; ++i)
            scanf("%d", &d[i]);
        
        memset(t, 0, sizeof t);
        for(int i = 0; i < n-1; ++i) {
            scanf("%d", &t[i]);
            t[i] *= 5;
        }
        
        memset(dp, -1, sizeof dp);
        T.clear(), ans.clear();
        
        int fish = recur(0, h);
        dfs(0, h, fish);
        
        printf("Case %d:\n", Case);
        printf("%d", ans.empty()? 0:ans[0]);
        for(int i = 1; i < n; ++i)
            printf(", %d", i >= (int)ans.size() ? 0:ans[i]);
        printf("\n");
        
        printf("Number of fish expected: %d\n", fish);
    }
    return 0;
}
