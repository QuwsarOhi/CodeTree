// LightOJ
// 1102 - Problem Makes Problem

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 2000100
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
ll C(int n, int r) {                        // Usable if MOD value is present
    if(fa[0] == 0) {                        // Auto initialize
        fa[0] = 1;
        for(int i = 1; i < MAX; ++i)
            fa[i] = (fa[i-1]*i) % MOD;      // Constant MOD
    }
    
    if(n < 0 || r < 0 || n-r < 0) return 0;     // Exceptional Cases
    ll b = (fa[r] * fa[n-r]) % MOD;
    return (fa[n] * modInverse(b, MOD))%MOD;
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

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, n, k;
    vector<int>dummy;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &k);
        printf("Case %d: %lld\n", Case, StarsAndBars(dummy, n, k));
    }
    return 0;
}
