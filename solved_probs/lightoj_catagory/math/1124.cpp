// LightOJ
// 1124 - Cricket Ranking


#include <bits/stdc++.h>
#define MOD 100000007
#define MAX 1000100
using namespace std;
typedef long long ll;

// Solution only exists if d | c (i.e : c is divisable by d)
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

ll fa[MAX];                                 // fa must be in global
ll C(ll n, ll r) {                        // Usable if MOD value is present
    if(fa[0] == 0) {                        // Auto initialize
        fa[0] = 1;
        for(int i = 1; i < MAX; ++i)
            fa[i] = (fa[i-1]*i) % MOD;      // Constant MOD
    }
    if(n < 0 || r < 0 || n-r < 0) return 0;     // Exceptional Cases
    ll b = (fa[r] * fa[n-r]) % MOD;
    return (fa[n] * modInverse(b, MOD)) %MOD;
}

// If We have to Make x1+x2+x3+x4 = 12
// Then, the solution can be expressed as : {*|*****|****|**} = {1+5+4+2}, {|*****|***|****} = {0+5+3+4}
// The summation is presented as total value, and the stars represanted as 1, we use bars to seperate values
// Number of ways we can produce the summation n, with k unknowns : C(n+k-1, n) = C(n+k-1, k-1)

// If numbers have lower limits, like x1 >= 3, x2 >= 2, x3 >= 1, x4 >= 1   (Let, the lower limits be l[i])
// Then the solution is : C(n-l1-l2-l3-l4+k-1, k-1)

ll StarsAndBars(vector<int> &l, int n, int k) {
    if(!l.empty()) for(int i = 0; i < k; ++i) n -= l[i];        // If l is empty, then there is no lower limit
    return C(n+k-1, k-1);
}

// If numbers have both boudaries l1 <= x1 <= r1, l2 <= x2 <= r2, and x1+x2 = N
// then we can reduce the form to x1+x2 = N-l1-l2 and then x only gets upper limit x1 <= r1-l1+1, x2 <= r2-l2+1
// let r1-l1+1 be new l1, and r2-l2+1 be new l2, so x1 <= l1 and x2 <= l2, this limit is the opposite of basic Stars
// and Bars theorem, according to Principle of Inclusion Exclution, this answer can be found as 
// Answer = C(n+k-1, k-1) - C(n-l1+k-1, k-1) - C(n-l2-k-1, k-1) + C(n-l1-l2+k-1, k-1) ......

ll StarsAndBarsInRange(ll l[], ll r[], ll n, ll k) {
    ll d[k+10], p[(1<<k) + 10];
    for(int i = 0; i < k; ++i) {
        d[i] = r[i] - l[i] + 1;
        n -= l[i];
    }
    
    ll ret = C(n+k-1, k-1);
    p[0] = 0;
    for(int i = 0; i < k; ++i)                                  // Optimized Complexity : 2^n
        for(int mask = (1<<i); mask < (1 << (i+1)); ++mask) {
            p[mask] = p[mask ^ (1<<i)] + d[i];
            ret += C(n-p[mask]+k-1, k-1) * (__builtin_popcount(mask)&1 ? -1:1);
            ret %= MOD;
        }
    return (ret+MOD)%MOD;
}

/*
ll StarsAndBarsInRange(ll l[], ll r[], ll n, ll k) {
    ll d[k+10];
    for(int i = 0; i < k; ++i) {
        d[i] = r[i] - l[i] + 1;
        n -= l[i];
    }
    
    ll ret = 0;
    for(int i = 0; i < (1<<k); ++i) {
        ll TOT = 0, cnt = 0;
        for(int j = 0; j < k; ++j) 
            if(i & (1<<j)) TOT += d[j], ++cnt;
        ret += C(n-TOT+k-1, k-1) * (cnt&1 ? -1:1);
        ret %= MOD;
    }
            
    return (ret+MOD)%MOD;
}*/


ll l[MAX], r[MAX];
        
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, N, K;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &K, &N);
        
        for(int i = 0; i < K; ++i)
            scanf("%lld%lld", &l[i], &r[i]);
        
        printf("Case %d: %lld\n", Case, StarsAndBarsInRange(l, r, N, K));
    }
    return 0;
}
