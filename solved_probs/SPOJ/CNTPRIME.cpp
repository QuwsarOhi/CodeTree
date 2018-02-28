// SPOJ - CNTPRIME - Counting Primes
// http://www.spoj.com/problems/CNTPRIME/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    ll prop, val;
    bool propSet;
    
    node(ll v=0) {
        propSet = 0;
        prop = val = v;
    }
};


bitset<1110000>isPrime;
node tree[51000];
ll val[11000];

//Only generates a number is prime or not
void sieve(unsigned long long N) {
    isPrime.set();
    //0 and 1 are not prime
    isPrime[0] = isPrime[1] = 0;

    for(unsigned long long i = 2; i <= N; i++) {      // change lim to N, if all primes in range N is needed
        if(isPrime[i]) {
            for(unsigned long long j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
        }
    }
}


void propagate(int pos, int l, int r) {
    if(l == r || !tree[pos].propSet)
        return;
    
    tree[pos<<1].prop = tree[pos<<1|1].prop = tree[pos].prop;
    tree[pos<<1].propSet = tree[pos<<1|1].propSet = 1;
    if(!tree[pos].prop)
        tree[pos<<1].val = tree[pos<<1|1].val = 0;
    else {
        int mid = (l+r)>>1;
        tree[pos<<1].val = (mid-l+1);
        tree[pos<<1|1].val = (r-mid);
    }
    
    tree[pos].prop = tree[pos].propSet = 0;
}


void init(int pos, int L, int R) {
    if(L == R) {
        tree[pos].val = val[L];
        tree[pos].prop = tree[pos].propSet = 0;
        return;
    }
    
    int mid = (L+R)>>1;
    
    init(pos<<1, L, mid);
    init(pos<<1|1, mid+1, R);

    tree[pos].val = tree[pos<<1].val + tree[pos<<1|1].val;
    tree[pos].prop = tree[pos].propSet = 0;
}


void update(int pos, int l, int r, int L, int R, int isPrime) {
    if(r < L || R < l)
        return;
    
    propagate(pos, l, r);
    if(L <= l && r <= R) {
        tree[pos].prop = isPrime;
        tree[pos].val = isPrime ? (r-l+1):0;
        tree[pos].propSet = 1;
        return;
    }
    
    int mid = (l+r)>>1;
    
    update(pos<<1, l, mid, L, R, isPrime);
    update(pos<<1|1, mid+1, r, L, R, isPrime);
    
    tree[pos].val = tree[pos<<1].val + tree[pos<<1|1].val;
}


ll query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l)
        return 0;
    
    propagate(pos, l, r);
    if(L <= l && r <= R)
        return tree[pos].val;
    
    int mid = (l+r)>>1;
    
    return query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R);
}


int main() {
    ll t, n, q, tp, x, l, r;
    
    scanf("%lld", &t);
    
    sieve(1100000);
    
    for(ll Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &n, &q);
        printf("Case %lld:\n", Case);
        
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &x);
            val[i] = isPrime[x] ? 1:0;
        }
        
        init(1, 1, n);
        
        for(int i = 1; i <= q; ++i) {
            scanf("%lld%lld%lld", &tp, &l, &r);
            
            if(tp)
                printf("%lld\n", query(1, 1, n, l, r));
            else {
                scanf("%lld\n", &x);
                update(1, 1, n, l, r, isPrime[x]);
            }
        }
    }
    
    return 0;
}
