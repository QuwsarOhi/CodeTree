// UVa
// 164 - String Computer
#include <bits/stdc++.h>
#define INF 1e7
#define mp make_pair
using namespace std;

int dp[30][30], l1, l2;
char s1[30], s2[30];

int recur(int p1, int p2) {
    if(dp[p1][p2] != INF)
        return dp[p1][p2];
    
    if(p1 == l1 or p2 == l2) {
        if(p1 < l1) return dp[p1][p2] = recur(p1+1, p2)+1;
        if(p2 < l2) return dp[p1][p2] = recur(p1, p2+1)+1;
        return dp[p1][p2] = 0;
    }
    
    if(s1[p1] == s2[p2])
        return dp[p1][p2] = recur(p1+1, p2+1);
    
    return dp[p1][p2] = min(recur(p1+1, p2+1), min(recur(p1+1, p2), recur(p1, p2+1)))+1;    // change, delete, insert
}


void dpPrint(int r, int c) {
    for(int i = 0; i < r; ++i, printf("\n"))
        for(int j = 0; j < c; ++j)
            printf("%3d", dp[i][j]);
    printf("\n");
}


void dPrint(int d) {
    ++d;
    if(d < 10)
        printf("0%d", d);
    else
        printf("%d", d);
}


void dfs(int p1, int p2) {
    if(dp[p1][p2] == 0) {
        printf("E\n");
        return;
    }
    if(s1[p1] == s2[p2]) {
        dfs(p1+1, p2+1);
        return;
    }
    
    
    int P = min(mp(dp[p1+1][p2], 1), min(mp(dp[p1][p2+1], 2), mp(dp[p1+1][p2+1], 3))).second;
    
    
    if(P == 1) {        // delete
        printf("D%c", s1[p1]);
        dPrint(p2);
        dfs(p1+1, p2);
    }
    else if(P == 2) {   // insert
        printf("I%c", s2[p2]);
        dPrint(p2);
        dfs(p1, p2+1);
    }
    else {              // match, change
        if(s1[p1] != s2[p2]) {
            printf("C%c", s2[p2]);
            dPrint(p2);
        }
        dfs(p1+1, p2+1);
    }
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    while(1) {
        scanf("%s", s1);
        l1 = strlen(s1);
        
        if(l1 == 1 and s1[0] == '#')
            break;
        
        scanf("%s", s2);
        l2 = strlen(s2);
    
        for(int i = 0; i < 30; ++i)
            for(int j = 0; j < 30; ++j)
                dp[i][j] = INF;
    
        
        recur(0, 0);
        //printf("COST %d\n", recur(0, 0));
        //dpPrint(6, 6);
        dfs(0, 0);
    }
    return 0;
}
