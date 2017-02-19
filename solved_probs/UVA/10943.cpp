//UVa
//10943 - How do you add?
#include<bits/stdc++.h>
using namespace std;

int memo[110][110];

inline int backtrack(int n, int k)
{
    if(k == 1)
        return 1;
    int ans = 0;
    for(register int i = 0; n - i >= 0; i++) {
        if(memo[n-i][k-1] == -1)
            ans += backtrack(n-i, k-1);
        else
            ans += memo[n-i][k-1];
        if(ans >= 1000000)
            ans %= 1000000;
    }
    return memo[n][k] = ans;
}

int main()
{
    memset(memo, -1, sizeof(memo));
    int n, k;
    while(scanf("%d %d", &n, &k) && (n || k)) {
        if(memo[n][k] == -1)
            printf("%d\n", backtrack(n, k));
        else
            printf("%d\n", memo[n][k]);
    }
    return 0;
}
