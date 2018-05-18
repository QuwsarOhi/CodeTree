// UVa
// 10066 - The Twin Towers

#include <bits/stdc++.h>
using namespace std;

int l1, l2, v1[110], v2[110], dp[110][110];

int recur(int p1, int p2) {
    if(p1 == l1 or p2 == l2)
        return 0;
    
    if(dp[p1][p2] != -1)
        return dp[p1][p2];
    
    if(v1[p1] == v2[p2])
        return dp[p1][p2] = recur(p1+1, p2+1)+1;
    else
        return dp[p1][p2] = max(recur(p1+1, p2), recur(p1, p2+1));
}


int main() {
    int Case = 1;
    while(scanf("%d%d", &l1, &l2)) {
        if(l1 == 0 and l2 == 0)
            break;
        for(int i = 0; i < l1; ++i)
            scanf("%d", &v1[i]);
        for(int i = 0; i < l2; ++i)
            scanf("%d", &v2[i]);
        
        memset(dp, -1, sizeof dp);
        printf("Twin Towers #%d\n", Case++);
        printf("Number of Tiles : %d\n\n", recur(0, 0));
    }
    return 0;
}
