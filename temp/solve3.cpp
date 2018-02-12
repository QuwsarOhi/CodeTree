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

node *presis[101000];
node *null = new node();
ll val[1000000];
map<ll, int>Map;
set<pair < pair<int, ll>, pair<ll, ll> > > Set;

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
void update(node *pos, ll l, ll r, ll idx, ll val) {
    if(l == r) {
        pos->val += val;
        pos->lft = pos->rht = null;
        return;
    }
    
    ll mid = (l+r)>>1;
    
    if(idx <= mid) {
        pos->lft = nCopy(pos->lft);
        update(pos->lft, l, mid, idx, val);
    }
    else {
        pos->rht = nCopy(pos->rht);
        update(pos->rht, mid+1, r, idx, val);
    }
    
    pos->val = 0;
    if(pos->lft)
        pos->val += pos->lft->val;
    if(pos->rht)
        pos->val += pos->rht->val;
}

// Range [L, R] Sum Query
ll query(node *pos, ll l, ll r, ll L, ll R) {
    if(r < L || R < l || pos == NULL)
        return 0;
    
    if(L <= l && r <= R)
        return pos->val;
    
    ll mid = (l+r)/2LL;
    
    ll x = query(pos->lft, l, mid, L, R);
    ll y = query(pos->rht, mid+1, r, L, R);

    return x+y;
}


inline void fastIn(ll &num) {          // Fast IO, with space and new line ignoring
    bool neg = false;
    register int c;
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


ll query(node *lPos, node *rPos, ll l, ll r, ll k) {
    if(!lPos || !rPos || r <= k || rPos->val == 0 || rPos->lft == rPos || rPos->rht == rPos) {
        //cout << "BRK " << l << " ---- " << r << endl;
        return 0;
    }
    
    //cout << l << " ---- " << r << endl;
    
    if(l > k) {
        //cout << "RET " << rPos->val - lPos->val << endl;
        return rPos->val - lPos->val;
    }
    
    ll mid = (l+r)>>1;
    
    return query(lPos->lft, rPos->lft, l, mid, k) + query(lPos->rht, rPos->rht, mid+1, r, k);
}

int main() {
    //freopen("in", "r", stdin);
    
    ll n, l, r, k, q, idx = 0;
    
    null->lft = null->rht = null;
    presis[0] = new node();
    presis[0]->lft = presis[0]->rht = null;
    
    fastIn(n);
    
    for(int i = 1; i <= n; ++i) {
        fastIn(val[i]);
        Map[val[i]];
    }
    
    fastIn(q);
    
    for(int i = 1; i <= q; ++i) {
        fastIn(l), fastIn(r), fastIn(k);
        Set.insert({{i, k}, {l, r}});
        Map[k];
    }
    
    for(auto it = Map.begin(); it != Map.end(); ++it)
        it->second = ++idx;
    
    for(int i = 1; i <= n; ++i) {
        presis[i] = nCopy(presis[i-1]);
        update(presis[i], 1, idx, Map[val[i]], 1);
    }
    
    for(auto it : Set)
        printf("%lld\n", query(presis[it.second.first-1], presis[it.second.second], 1, idx, Map[it.first.second]));
    
    return 0;
}
    
    
