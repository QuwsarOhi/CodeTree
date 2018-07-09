#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX                 5010
#define MOD                 1000000007
typedef long long ll;


struct BIT {
    ll tree[MAX];
    int MaxVal;
    
    void init(int sz=1e7) {
        memset(tree, 0, sizeof tree);
        MaxVal = 5000;
    }

    void update(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx)) {
            tree[idx] += val + MOD - 1;
            tree[idx] %= (MOD-1);
        }
    }
    
    void update(int l, int r, ll val) {
        if(l > r) swap(l, r);
        update(l, val);
        update(r+1, -val);
    }

    ll read(int idx) {
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx)) {
            sum += tree[idx] + MOD - 1;
            sum %= (MOD-1);
        }
        return sum;
    }
    
    ll read(int l, int r) {
        ll ret = (read(r) - read(l-1) + MOD - 1) % (MOD-1);
        return ret;
}};

BIT BT;

ll powerMOD(ll x, ll y) {                   // Can find modular inverse by a^(MOD-2),  a and MOD must be co-prime
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
        
        BT.init();
        ll T[MAX] = {0};
        for(int l = 1; l <= n-m+1; ++l) {
            for(int r = l+m-1; r <= n; ++r) {
                ll c = r-l-1;
                ll p = F(c, m-2);
                BT.update(l+1, r-1, p);
                T[l+1] += p;
                T[l+1] %= MOD-1;
            }
        }
        
        ll ANS = 1, CSUM = 0;
        sort(a+1, a+n+1);
        for(int i = 1; i < n; ++i) {
            printf("%d : %lld %lld\n", i, BT.read(i), T[i]+CSUM);
            ANS = (ANS * powerMOD(a[i], BT.read(i)))%MOD;
            CSUM += T[i];
        }
        printf("%lld\n", ANS);
    }
    return 0;
}
