// LightOJ
// 1095 - Arrange the Numbers
// Derangement (Place numbers where none of them are in their initial place)

// Ref:
//http://www.shafaetsplanet.com/planetcoding/?p=600
//http://mathworld.wolfram.com/PartialDerangement.html

// In this problem, we need to find how many ways we can put N-K numbers where M-K numbers are not in their initial place
// This is because exactly K numbers (in first M) can be placed in their initial place 

#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ull;
using namespace std;


ull c[1004][1004], f[1010];

void factorial() {
    f[0] = 1;
    for(ull i = 1; i <= 1000; ++i) {
        f[i] = (i * f[i-1])%MOD;
    }
}

ull C(int n, int r) {
    if(r == 0 || n == r)
        return 1;
    if(c[n][r] != -1)
        return c[n][r];
    c[n][r] = (C(n-1, r)%MOD + C(n-1, r-1)%MOD)%MOD;
    return c[n][r];
}

ull partial_derangement(int n, int r) {			// Finds out how many ways we can place n numbers where r of them are not in their initial place
    ull ans = f[n];								// Factorial of n!
    for(int i = 1; i <= r; ++i) {				
        if(i & 1)						// Formula: n! - C(n, 1)*(n-1)! + C(n, 2)*(n-2)! ..... + (-1)^r * C(n,r)*(n-r)!
            ans = (ans%MOD - (C(r, i) * f[n-i])%MOD)%MOD;	// Here C(r, i) is because we only have to choose from r elements, not n elements
        else 												// So, this is not the exact formula
            ans = (ans%MOD + (C(r, i) *f[n-i])%MOD)%MOD;
        ans = (ans + MOD)%MOD;
    }
    return ans%MOD;
}

int main() {

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    memset(c, -1, sizeof(c));
    factorial();

    int t, N,K,M;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d", &N,&M,&K);
        printf("Case %d: %lld\n", Case, ((C(M, K)%MOD) * partial_derangement(N-K, M-K)%MOD)%MOD);
    }
    return 0;
}

