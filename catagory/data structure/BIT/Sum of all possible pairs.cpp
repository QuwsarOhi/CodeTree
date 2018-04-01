// Toph
// https://toph.co/p/hardest-update-and-easiest-query

// Hardest Update and Easiest Query
// Sum of pairs
// Square Sum technique


// Sum of all possible pair technique:
// (a+b)^2 = a^2 + 2ab + b^2
// ab = ( (a+b)^2 - (a^2 + b^2) ) / 2

#include <stdio.h>
#include <string.h>
#define M 1000000007LL
#define pf printf
typedef long long ll;

inline void sf(ll &num) {          // Fast IO, with space and new line ignoring
    bool neg = false;
    register ll c;
    num = 0;
    c = getchar_unlocked();
    for( ; c != '-' && (c < '0' || c > '9'); c = getchar_unlocked());
    if (c == '-') {
        neg = true;
        c = getchar_unlocked();
    }
    for(; (c>47 && c<58); c=getchar_unlocked())
        num = (num<<1) + (num<<3) + c - 48;
    if(neg)
        num *= -1;
}

struct BIT {
    ll tree[100002], MX = 100000;
    BIT(int n) {
        MX = n;
        memset(tree, 0, sizeof tree);
    }
    void update(int idx, ll val) {
        for( ;idx <= MX; idx += (idx & -idx))
            tree[idx] = (tree[idx] + val + M)%M;
    }
    void upd(int idx, ll val) {
        update(idx, (val - read(idx, idx) + M)%M);
    }
    ll read(int idx) {
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx))
            sum = (sum + tree[idx] + M)%M;
        return sum;
    }
    ll read(int l, int r) {
        return ((read(r) - read(l-1) + M)%M);
    }
};


int main() {
    ll r, n, t, l;
    
    sf(n);
    BIT sqSum(n), sum(n);
    for(int i = 1; i <= n; ++i) {
        sf(r);
        sqSum.update(i, (r*r)%M);
        sum.update(i, r);
    }
    
    sf(n);
    while(n--) {
        sf(t), sf(l), sf(r);
        if(t == 1) {
            sqSum.upd(l, (r*r)%M);
            sum.upd(l, r);
        }
        else {
            ll tm = sum.read(l, r);
            tm = ((tm*tm)%M - sqSum.read(l, r) + M)%M;
            if(tm&1LL) tm += M;
            tm /= 2;
            pf("%lld\n", tm);
        }
    }
}
