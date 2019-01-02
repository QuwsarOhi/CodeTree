// LightOJ
// 1170 - Counting Perfect BST

#include <bits/stdc++.h>
#define MAX 150010
#define MOD 100000007
using namespace std;

typedef long long ll;

ll gcdExtended(ll a, ll b, ll *x, ll *y) {          // C function for extended Euclidean Algorithm
    if (a == 0) {                                   // Base Case
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;                                     // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
ll modInverse(ll a, ll mod) {
    ll x, y;
    ll g = gcdExtended(a, mod, &x, &y);
    if(g != 1) return -1;                   // ModInverse doesnt exist
    ll res = (x%mod + mod) % mod;           // m is added to handle negative x
    return res;
}

ll fa[MAX], fainv[MAX];                             // fa and fainv must be in global
ll C(ll n, ll r) {                                  // Usable if MOD value is present
    if(fa[0] == 0) {                                // Auto initialize
        fa[0] = 1, fainv[0] = modInverse(1, MOD);
        for(ll i = 1; i < MAX; ++i) {
            fa[i] = (fa[i-1]*i) % MOD;              // Constant MOD
            fainv[i] = modInverse(fa[i], MOD);
    }}
    if(n < 0 || r < 0 || n-r < 0) return 0;         // Exceptional Cases
    return ((fa[n] * fainv[r])%MOD * fainv[n-r])%MOD;
}

ll Catalan(ll n) {    // Cat(n) = C(2*n, n)/(n+1);
    ll c = C(2LL*n, n);
    return (c*modInverse(n+1LL, MOD))%MOD;
}

vector<ll>p;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    ll a, b;
    scanf("%d", &t);

    for(ll i = 2; i <= 100001; ++i) {
        ll pp = i*i;
        while(pp <= 10000000001LL) {
            p.push_back(pp);
            pp *= i;
        }
    }

    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    vector<ll> :: iterator it1, it2;

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &a, &b);
        if(a > b) swap(a, b);
        it2 = upper_bound(p.begin(), p.end(), b);
        it1 = lower_bound(p.begin(), p.end(), a);
        int n = it2-it1;
        printf("Case %d: %lld\n", Case, n == 0? 0:Catalan(n));
    }

    return 0;
}