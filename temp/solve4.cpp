// UVa
// 11022 - String Factoring

#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

char s[100];
int dp[110][110];

// D O O O D O O O
// 0 1 2 3 4 5 6 7

int reduce(int l, int r) {
    if(l > r)           return INF;
    if(l == r)          return 1;
    if(dp[l][r] != -1)  return dp[l][r];
    int ret = r-l+1;
    int len = ret;
    
    for(int i = l; i < r; ++i)          // A B D O D O   remove A B substring
        ret = min(ret, reduce(l, i)+reduce(i+1, r));
    for(int d = 1; d < len; ++d) {      // D O O D O O D O O D O O  to check all divisable length substring
        if(len%d != 0)  continue;
        for(int i = l+d; i <= r; i += d)
            for(int k = 0; k < d; ++k)
                if(s[l+k] != s[i+k])
                    goto pass;
        ret = min(ret, reduce(l, l+d-1));
        pass:;
    }
    return dp[l][r] = ret;
}
    
int main() {
    while(scanf("%s", s)) {
        if(s[0] == '*')
            break;
        memset(dp, -1, sizeof dp);
        printf("%d\n", reduce(0, strlen(s)-1));
    }
    return 0;
}
