// LightOJ
// 1084 - Winter

#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

vector<int>v;
int dp[100009], n, k;

int recur(vector<int>::iterator it) {
    if(it == v.end())
        return 0;
    
    int pos = it - v.begin();
    if(dp[pos] != -1)
        return dp[pos];
    
    vector<int>::iterator tmp = upper_bound(it, v.end(), *it+(k<<1));
    int len = tmp - it, ret = INF;
    
    if(len >= 3)   ret = min(ret, 1+recur(tmp));
    if(len >= 4)   ret = min(ret, 1+recur(tmp-1));
    if(len >= 5)   ret = min(ret, 1+recur(tmp-2));
    return dp[pos] = ret;
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, x;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &k);
        
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            v.push_back(x);
        }
        
        sort(v.begin(), v.end());
        memset(dp, -1, sizeof dp);
        int ans = recur(v.begin());
    
        printf("Case %d: %d\n", Case, ans>=INF?-1:ans);
        v.clear();
    }
    return 0;
}
