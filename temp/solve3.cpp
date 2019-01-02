// CodeChef
// Subarray LCM
// DP + Prime Factor

#include <bits/stdc++.h>
using namespace std;

bitset<1000010> isPrime;
vector<int>PF[1000010];
int dp[1000010], pfPos[1000010], v[1000010];

void sieveGen(long long N) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(long long i = 2; i <= N; i++) {
        if(isPrime[i]) {
            PF[i].push_back(i);
            for(long long j = i+i; j <= N; j+= i)
                isPrime[j] = 0, PF[j].push_back(i);
}}}

int CAL(int x) {
    int maxCommonPos = 0;
    
    for(auto p : PF[v[x]]) {
        maxCommonPos = max(maxCommonPos, pfPos[p]);
        pfPos[p] = x;
    }

    return maxCommonPos;
}

int main() {
    sieveGen(1000000);
    int t, n, ans, pstPos, totLen;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i = 1; i <= n; ++i)
            scanf("%d", &v[i]);

        memset(dp, 0, sizeof dp);
        memset(pfPos, 0, sizeof pfPos);
        ans = 0;

        for(int i = 1; i <= n; ++i) {
            pstPos = CAL(i);
            totLen = min(i - pstPos, dp[i-1]+1);

            dp[i] = totLen;
            ans = max(ans, totLen);
        }

        printf("%d\n", ans < 2?-1:ans);
    }

    return 0;
}