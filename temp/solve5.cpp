#include <bits/stdc++.h>
using namespace std;

char s[100];
long long dp[61][61], len;

long long palinCount(int l, int r) {
    //cout << l << " -- " << r << endl;
    if(l == r)
        return 1;
    
    if(dp[l][r] != -1) {
        //cout << "HIT" << endl;
        return dp[l][r];
    }
    
    int ret = 0;
    for(int i = l; i <= r; ++i)
        for(int j = r; j >= i; --j)
            if(s[i] == s[j]) {
                if(i+1 <= j-1)
                    ret += palinCount(i+1, j-1)+1;
                else
                    ret += 1;
            }
    return dp[l][r] = ret;
}
    
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        len = strlen(s);
        memset(dp, -1, sizeof dp);
        printf("%lld\n", palinCount(0, len-1));
    }
    return 0;
}
