#include <bits/stdc++.h>
#define MAX 30010
using namespace std;

int v[MAX], n, D, LIM;
int dp[MAX][600];

int recur(int pos, int d) {
    if(pos > LIM || d <= 0)
        return 0;
    
    int t = d - (D-250);
    int &ret = dp[pos][t];
    if(ret != -1) return ret;
    
    ret = max(recur(pos+d, d), max(recur(pos+d+1, d+1), recur(pos+d-1, d-1))) + v[pos];
    return ret;
}
    

int main() {
    int x;
    scanf("%d%d", &n, &D);
    
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        LIM = max(x, LIM);
        v[x]++;
    }
    
    memset(dp, -1, sizeof dp);
    printf("%d\n", recur(D, D));
    return 0;
}
