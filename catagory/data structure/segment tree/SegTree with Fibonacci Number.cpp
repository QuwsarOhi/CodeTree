// DZY Loves Fibonacci Numbers
// http://codeforces.com/contest/446/problem/C

// Segment Tree + Fibonacci Sequence

// Add f1, f2, f3,... fibonacci numbers to each position in interval [l, r]
// output sum in range [l, r]

/*
Observations:

1. F(a, b, k) = a*f[k-2] + b*f[k-1] 
   : k-th element of general Fibonacii sequences starting with a, b, where f[i] — i-th Fibonacci numbers (starting from 1, 1) (so a = 1, b = 1)

2) sum of first k members of general Fibonacci sequence f[i] equals to F[k+2] - F[2].
*/

#include <bits/stdc++.h>
#define MOD 1000000009
#define MAX 310000
using namespace std;
typedef long long ll;

struct node {
    ll a, b, sum;
    bool prop;
};

ll f[MAX], val[MAX];
node tree[5*MAX];

void fibCal(int n) {
    f[1] = f[2] = 1;
    for(int i = 3; i <= n; ++i)
        f[i] = (f[i-1] + f[i-2])%MOD;
}

ll KthFib(ll a, ll b, ll k) {
    if(k == 1)
        return a;
    else if(k == 2)
        return b;                               // for any fib sequence starting from a, b to get the k'th value
    return (a*f[k-2] + b*f[k-1])%MOD;           // F(a, b, k) = a*f[k-2] + b*f[k-1]     -->> where f[i] is obtained from the original series
}

ll fibSum(ll a, ll b, ll k) {
    return (KthFib(a, b, k+2) - b + MOD)%MOD;
}

// FULL OK
void init(int pos, int l, int r) {
    tree[pos].a = tree[pos].b = 0;
    tree[pos].prop = 0;
    
    if(l == r) {
        tree[pos].sum = val[l];
        return;
    }
    
    int mid = (l+r)>>1;
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    
    tree[pos].sum = (tree[pos<<1].sum + tree[pos<<1|1].sum)%MOD;
}

// ERROR
void nodeCal(int pos, int l, int r, ll a, ll b) {
    tree[pos].a = (tree[pos].a + a)%MOD;
    tree[pos].b = (tree[pos].b + b)%MOD;
    tree[pos].sum = (tree[pos].sum + fibSum(a, b, r-l+1))%MOD;
    tree[pos].prop = 1;
}

void propagate(int pos, int l, int r) {
    if(!tree[pos].prop || l == r)
        return;
    
    int mid = (l+r)>>1;
    int lftInterval = mid-l+1;
    ll a = tree[pos].a, b = tree[pos].b;
    
    nodeCal(pos<<1, l, mid, a, b);
    nodeCal(pos<<1|1, mid+1, r, KthFib(a, b, lftInterval+1), KthFib(a, b, lftInterval+2));
    
    tree[pos].a = tree[pos].b = 0;
    tree[pos].prop = 0;
}

void update(int pos, int l, int r, int L, int R) {
    if(r < L || R < l)
        return;
    
    propagate(pos, l, r);
    if(L <= l && r <= R) {
        int a = f[l-L+1];
        int b = f[l-L+2];
        
        //printf("%d %d : a: %d, b: %d\n", l, r, a, b);
        nodeCal(pos, l, r, a, b);        
        return;
    }
    
    int mid = (l+r)>>1;
    update(pos<<1, l, mid, L, R);
    update(pos<<1|1, mid+1, r, L, R);
    
    tree[pos].sum = (tree[pos<<1].sum + tree[pos<<1|1].sum)%MOD;
}


ll query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l)
        return 0;
    
    propagate(pos, l, r);
    if(L <= l && r <= R)
        return tree[pos].sum;
    
    int mid = (l+r)>>1;
    return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R))%MOD;
}


int main() {
    int n, q, t, l, r;
    
    scanf("%d%d", &n, &q);
    fibCal(n+10);
    
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &val[i]);
    
    init(1, 1, n);
    
    while(q--) {
        scanf("%d%d%d", &t, &l, &r);
        
        if(t == 1)
            update(1, 1, n, l, r);
        else
            printf("%lld\n", query(1, 1, n, l, r));
    }
    
    return 0;
}
