#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX                 5010
#define MOD                 1000000007
typedef long long ll;


ll powerMOD(ll x, ll y) {                   // Can find modular inverse by a^(MOD-2),  a and MOD must be co-prime
    //if(MAP.find({x, y}) != MAP.end())
    //    return MAP[{x, y}];
        
    ll res = 1;

    while(y > 0) {
        if(y&1) {
            res = res*x;          // If y is odd, multiply x with result
            if(res > MOD) res %= MOD;
        }
        y = y >> 1;
        x = (x * x);
        if(x > MOD) x %= MOD;
    }
    
    //MAP[{x, y}] = res;
    return res;
}


// Building Pascle C(n, r)
ll p[MAX][MAX];
void buildPascle() {                                // This Contains values of nCr : p[n][r] 
    p[0][0] = 1;
    p[1][0] = p[1][1] = 1;
    for(int i = 2; i <= 5001; i++)
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i)
                p[i][j] = 1;
            else
                p[i][j] = (p[i-1][j-1] + p[i-1][j]) % (MOD-1);
}}

ll C(int n, int r) {
    if (r<0 || r>n) return 0;
    return p[n][r];
}

//------------------------------------------------------------------

ll F(int n, int r) {
    n = r + abs(n-r);
    return C(n-1, r-1);
}


ll a[MAX];

int main() {
    buildPascle();
    int t, n;
    ll m;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d%lld", &n, &m);
        
        a[0] = 1;
        for(int i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        
        if(n < m) {
            printf("0\n");
            continue;
        }
        
        sort(a+1, a+n+1);
        for(int i = 1; i <= n; ++i) {
            a[i] *= a[i-1];
            if(a[i] > MOD) a[i] %= MOD;
        }
        
        ll ANS = 1;
        for(int l = 1; l <= n-m+1; ++l) {
            ll modINV = powerMOD(a[l], MOD-2);
            for(int r = l+m-1; r <= n; ++r) {
                ll c = r-l-1;
                
                ll segMul = (a[r-1] * modINV);
                if(segMul > MOD) segMul %= MOD;
                
                ll p = F(c, m-2);
                ANS = (ANS * powerMOD(segMul, p));
                if(ANS > MOD) ANS %= MOD;
            }
        }
        
        printf("%lld\n", ANS);
    }
    return 0;
}
