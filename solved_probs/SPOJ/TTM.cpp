// SPOJ TTM
// Presistant Segment Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


struct node {
    ll val, prop;
    node *lft, *rht;
    
    node(node *lft = NULL, node *rht = NULL, ll val = 0, ll prop = 0) {
        this->lft = lft;
        this->rht = rht;
        this->val = val;
        this->prop = prop;
    }
};

node *prop[200100];
ll val[200100];


node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->lft = x->lft;
        tmp->rht = x->rht;
        tmp->val = x->val;
        tmp->prop = x->prop;
    }
    return tmp;
}


void init(node *pos, ll l, ll r) {
    if(l == r) {
        pos->val = val[l];
        return;
    }
    
    ll mid = (l+r)>>1;
    
    pos->lft = new node();
    pos->rht = new node();
    
    init(pos->lft, l, mid);
    init(pos->rht, mid+1, r);
    pos->val = pos->lft->val + pos->rht->val;
}

void update(node *pos, ll l, ll r, ll L, ll R, ll val) {
    if(r < L || R < l)
        return;
    
    if(L <= l && r <= R) {
        pos->prop += val;
        pos->val += (r-l+1)*val;
        return;
    }
    
    ll mid = (l+r)>>1;
    
    pos->lft = nCopy(pos->lft);
    pos->rht = nCopy(pos->rht);
    
    update(pos->lft, l, mid, L, R, val);
    update(pos->rht, mid+1, r, L, R, val);
    
    pos->val = pos->lft->val + pos->rht->val + (r-l+1)*pos->prop;
}


ll query(node *pos, ll l, ll r, ll L, ll R, ll carry = 0) {
    if(r < L || R < l)
        return 0;
    
    if(L <= l && r <= R)
        return pos->val + (r-l+1)*carry;
    
    ll mid = (l+r)>>1;
    ll x = query(pos->lft, l, mid, L, R, carry+pos->prop);
    ll y = query(pos->rht, mid+1, r, L, R, carry+pos->prop);
    
    return x+y;
}


int main() {
    ll l, r, Time = 0, t, m, n, d;
    char str[10];
    
    scanf("%lld%lld", &n, &m);
    
    prop[Time] = new node();
    
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &val[i]);
    
    init(prop[Time], 1, n);
    
    while(m--) {
        scanf(" %s", str);
        if(str[0] == 'C') {
            scanf("%lld%lld%lld", &l, &r, &d);
            Time++;
            prop[Time] = nCopy(prop[Time-1]);
            update(prop[Time], 1, n, l, r, d);
        }
        else if(str[0] == 'Q') {
            scanf("%lld%lld", &l, &r);
            printf("%lld\n", query(prop[Time], 1, n, l, r));
        }
        else if(str[0] == 'H') {
            scanf("%lld%lld%lld", &l, &r, &t);
            printf("%lld\n", query(prop[t], 1, n, l, r));
        }
        else {
            scanf("%lld", &Time);
        }
    }
    
    return 0;
}
