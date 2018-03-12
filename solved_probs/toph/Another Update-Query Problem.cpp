// TOPH - Another Update-Query Problem
// https://toph.co/p/another-update-query-problem
// Segment Tree


#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

struct SegTreeRSQ {
    vector<ll>sum, prop;

    void Resize(int n) {
        sum.resize(5*n);
        prop.resize(5*n);
    }

    void init(int pos, int l, int r, ll val[]) {
        sum[pos] = prop[pos] = 0;
        if(l == r) {
            sum[pos] = val[l]%MOD;
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }

    void propagate(int pos, int l, int r) {
        if(prop[pos] == 0 || l == r)
            return;

        int mid = (l+r)>>1;
        sum[pos<<1] = (sum[pos<<1] + prop[pos]*(mid-l+1))%MOD;
        sum[pos<<1|1] = (sum[pos<<1|1] + prop[pos]*(r-mid))%MOD;
        prop[pos<<1] = (prop[pos<<1] + prop[pos])%MOD;
        prop[pos<<1|1] = (prop[pos<<1|1] + prop[pos])%MOD;
        prop[pos] = 0;
    }

    void update(int pos, int l, int r, int L, int R, ll val) {
        if(r < L || R < l)
            return;

        propagate(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] = (sum[pos] + val*(r-l+1))%MOD;
            prop[pos] = (prop[pos] + val)%MOD;
            return;
        }

        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }

    ll query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l)
            return 0;

        propagate(pos, l, r);
        if(L <= l && r <= R)
            return sum[pos];

        int mid = (l+r)>>1;
        return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R))%MOD;
    }
};

// Segment Tree Sequence (Lazy Propagation):: Contains sequnce A + 2A + 3A + ..... nA
struct SegTreeSeq {
    vector<ll>sum, prop;

    void Resize(int n) {
        sum.resize(n*5);
        prop.resize(n*5);
    }

    ll intervalSum(ll l, ll r, ll val) {
        ll interval = (r*(r+1))/2LL - (l*(l-1))/2LL;
        return (interval*val+MOD)%MOD;
    }

    void propagate(int pos, int l, int r) {
        if(prop[pos] == 0 || l == r)
            return;
        
        int mid = (l+r)>>1;
        sum[pos<<1] = (sum[pos<<1] + intervalSum(l, mid, prop[pos]))%MOD;
        sum[pos<<1|1] = (sum[pos<<1|1] + intervalSum(mid+1, r, prop[pos]))%MOD;
        prop[pos<<1] = (prop[pos<<1] + prop[pos])%MOD;
        prop[pos<<1|1] = (prop[pos<<1|1] + prop[pos])%MOD;
        prop[pos] = 0;
    }

    void init(int pos, int l, int r, ll val[]) {
        sum[pos] = prop[pos] = 0;
        if(l == r) {
            sum[pos] = (val[l]*l)%MOD;
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }

    void update(int pos, int l, int r, int L, int R, ll val) {      // Range Update
        if(r < L || R < l)
            return;
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] = (intervalSum(l, r, val) + sum[pos])%MOD;
            prop[pos] = (val + prop[pos])%MOD;
            return;
        }
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }
    
    ll query(int pos, int l, int r, int L, int R) {     // Range Query
        if(r < L || R < l || L > R)
            return 0;
        propagate(pos, l, r);
        if(L <= l && r <= R)
            return sum[pos];
        int mid = (l+r)>>1;
        return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R))%MOD;
    }
};


SegTreeRSQ sum;
SegTreeSeq seq;
ll v[110000];


int main() {
    ll t, q, n, l, r, d, typ;
    
    scanf("%lld", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &n, &q);
        
        for(int i = 1; i <= n; ++i)
            scanf("%lld", &v[i]);
        
        sum.Resize(n);
        seq.Resize(n);
        sum.init(1, 1, n, v);
        seq.init(1, 1, n, v);
        
        printf("Case %d:\n", Case);
        
        while(q--) {
            scanf("%lld%lld%lld%lld", &typ, &l, &r, &d);
            d %= MOD;

            if(typ == 1) {
                sum.update(1, 1, n, l, r, d);
                seq.update(1, 1, n, l, r, d);
            }
            else {
                ll RangeSum = sum.query(1, 1, n, l, r);
                ll seqSum = (((seq.query(1, 1, n, l+1, r) - (sum.query(1, 1, n, l+1, r)*l)%MOD + MOD)%MOD) * d)%MOD;

                printf("%lld\n", (RangeSum+seqSum)%MOD);
            }
        }
    }
    
    return 0;
}
