// LightOJ
// 1098 - A New Function

// Cumulative Sum of Divisors

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll CSOD(ll n) {
    ll ans = 0;
    for(ll i = 2; i * i <= n; ++i) {
        ll j = n / i;
        ans += (i + j) * (j - i + 1) / 2;
        ans += i * (j - i);
    }
    return ans;
}


int main() {
    int t;
    ll n;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld", &n);
        printf("Case %d: %lld\n", Case, CSOD(n));
    }
    return 0;
}
