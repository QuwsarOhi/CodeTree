// LightOJ
// 1198 - Karate Competition

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, v1[60], v2[60], cnt[1010], used[1010];
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof cnt);
        memset(used, 0, sizeof used);
        
        for(int i = 0; i < n; ++i)
            scanf("%d", &v1[i]);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &v2[i]);
            cnt[v2[i]]++;
        }
        
        sort(v1, v1+n);
        sort(v2, v2+n);
        reverse(v2, v2+n);
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                if(v2[j] < v1[i] && cnt[v2[j]] > 0) {
                    ans += 2;
                    used[i] = 1;
                    cnt[v2[j]]--;
                    break;
                }
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                if(!used[i] && v2[j] == v1[i] && cnt[v2[j]] > 0) {
                    ans += 1;
                    cnt[v2[j]]--;
                    break;
                }
        }
        
        printf("Case %d: %d\n", Case, ans);
    }
    return 0;
}
