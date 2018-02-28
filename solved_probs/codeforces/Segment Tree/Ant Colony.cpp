// Codeforces
// F - Ant Colony
// http://codeforces.com/contest/474/problem/F

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    ll val;
    node *lft, *rht;
    
    node(node *L = NULL, node *R = NULL, ll v = 0) {
        lft = L;
        rht = R;
        val = v;
    }
};

node *Count[101000], *null;
ll tree[510000], val[110000];
map<ll, ll>Map;

void init(ll pos, ll l, ll r) {
    if(l==r) {
        tree[pos] = val[l];
        return;
    }

    ll mid = (l+r)>>1;
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);

    tree[pos] = __gcd(tree[pos<<1], tree[pos<<1|1]);
}

ll query(ll pos, ll l, ll r, ll L, ll R) {
    if(r < L || R < l)
        return -1;

    if(L <= l && r <= R)
        return tree[pos];

    ll mid = (l+r)>>1;
    ll x = query(pos<<1, l, mid, L, R);
    ll y = query(pos<<1|1, mid+1, r, L, R);

    if(x == -1)
        return y;
    if(y == -1)
        return x;
    return __gcd(x, y);
}

node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->val = x->val;
        tmp->lft = x->lft;
        tmp->rht = x->rht;
    }
    return tmp;
}


// Single Position update
void insert(node *pos, ll l, ll r, ll idx) {
    if(l == r) {
        pos->val++;
        pos->lft = pos->rht = null;
        return;
    }
    
    ll mid = (l+r)>>1;
    
    if(idx <= mid) {
        pos->lft = nCopy(pos->lft);
        if(pos->rht == NULL)
            pos->rht = null;
        insert(pos->lft, l, mid, idx);
    }
    else {
        pos->rht = nCopy(pos->rht);
        if(pos->lft == NULL)
            pos->lft = null;
        insert(pos->rht, mid+1, r, idx);
    }
    pos->val++;
}

ll RangeCount(node *Rht, node *Lft, ll l, ll r, ll val) {
    ll cnt = Rht->val-Lft->val;
    
    if(!cnt)
        return 0;
    
    if(l == r)
        return cnt;
    
    ll mid = (l+r)>>1;
    
    if(val <= mid)
        return RangeCount(Rht->lft, Lft->lft, l, mid, val);
    return RangeCount(Rht->rht, Lft->rht, mid+1, r, val);
}

// What to do when L == R?

int main() {
    ll n, q, l, r, idx = 0;

    scanf("%lld", &n);
    Count[0] = new node();
    null = new node();
    null->lft = null->rht = null;
    Count[0] = null;
    
    for(ll i = 1; i <= n; ++i) {
        scanf("%lld", &val[i]);
        Count[i] = nCopy(Count[i-1]);
        if(Map.find(val[i]) == Map.end())
            Map[val[i]] = ++idx;
        insert(Count[i], 1, n, Map[val[i]]);
    }

    scanf("%lld", &q);
    init(1, 1, n);

    for(ll i = 1; i <= q; ++i) {
        scanf("%lld%lld", &l, &r);
        //ll k = (r-l);
        ll gcd = query(1, 1, n, l, r), sameCount = 0;
        // Need to find values in range l r
        if(Map.find(gcd) != Map.end())
            sameCount = RangeCount(Count[r], Count[l-1], 1, n, Map[gcd]);
        
        //cout << gcd << " " << sameCount << endl;
        // samecount Generated, how to find answer?
        printf("%lld\n", r-l+1-sameCount);
    }

    return 0;
}
