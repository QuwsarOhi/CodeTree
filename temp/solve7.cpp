#include <bits/stdc++.h>
#define MOD 998244353
#define MAX 1010
using namespace std;
typedef long long ll;


// Building Pascle C(n, r)
ll p[MAX][MAX];
void buildPascle(int n) {                                // This Contains values of nCr : p[n][r] 
    p[0][0] = 1;
    p[1][0] = p[1][1] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i)
                p[i][j] = 1;
            else
                p[i][j] = (p[i-1][j-1] + p[i-1][j])%MOD;
}}

ll C(int n, int r) {
    if (r<0 || r>n) return 0;
    return p[n][r];
}


vector<int>T;
int ans, n;
ll v[1010], dp[1010];


int main() {
    //freopen("in", "r", stdin);
    buildPascle(1005);
    cin >> n;
    
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    //recur();
    
    dp[n] = 1;
    for(int i = n-1; i >= 0; --i) {
        for(int j = i+1; j <= n and v[i] > 0; ++j) {
            dp[i] += (C(j-i-1, v[i]) * dp[j])%MOD;
            dp[i] %= MOD;
        }
        
        ans += dp[i];
        ans %= MOD;
    }
    
    cout << ans << endl;
    return 0;
}
    
    
