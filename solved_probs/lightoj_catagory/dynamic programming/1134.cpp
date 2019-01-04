// LightOJ
// 1134 - Be Efficient

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[100010], v[100010];

// Finding number of subsequences for which mod of d is zero
// for any subsequence, the mod of d is zero iff the cumulative sum 
// of the subsequence is same as previously found cumulative sum
ll subSeqSum(ll v[], ll n, ll d) {
    ll ans = 0, sum = 0;
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for(int i = 0; i < n; ++i) {
        sum = (sum + v[i])%d;
        ans += dp[sum]++;
    }
    return ans;
}

int main() {
    long long t, ans, sum, n, m;
    scanf("%lld", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &n, &m);

        for(int i = 0; i < n; ++i)
            scanf("%lld", &v[i]);

        printf("Case %d: %lld\n", Case, subSeqSum(v, n, m));
    }

    return 0;
}