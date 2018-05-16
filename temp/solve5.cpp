#include <bits/stdc++.h>
#define M 1000000009
using namespace std;
typedef unsigned long long ull;

ull dp[1000010];

map<ull, int>Map;

int main() {
    ull n, cnt = 0;
    
    dp[1] = 0, dp[2] = 1, dp[3] = 2;
    for(int i = 4; i < 1000000; ++i) {
        dp[i] = (dp[i-1]%M + dp[i-2]%M + dp[i-3]%M) % M;
        cout << dp[i] << " " << i << endl;
        if(Map.find(dp[i]) != Map.end()) {
            ++cnt;
            if(cnt == 10) {
                cout << "Same on " << Map[dp[i]] << endl;
                getchar();
            }
        }
        else {
            cnt = 0;
            Map[dp[i]] = i;
        }
        //getchar();
    }
        
    while(scanf("%llu", &n)) {
        if(!n) break;
        
        cout << dp[n] << endl;
    }
    
    return 0;
}
