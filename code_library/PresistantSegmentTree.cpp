// Peresistant/Dynamic Segment Tree
// Pointer Version

#include <bits/stdc++.h>
using namespace std;
#define MAX                 500000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000003
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;


struct node {
    ll val;
    node *lft, *rht;
    
    node(node *L = NULL, node *R = NULL, ll v = 0) {
        lft = L;
        rht = R;
        val = v;
    }
};

node *presis[101000] *null = new node();
null->lft = null->rht = null;

node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->val = x->val;
        tmp->lft = x->lft;
        tmp->rht = x->rht;
    }
    return tmp;
}


void init(node *pos, ll l, ll r) {
    if(l == r) {
        pos->val = val[l];
        pos->lft = pos->rht = null;
        return;
    }
    
    ll mid = (l+r)>>1;
    
    pos->lft = new node();
    pos->rht = new node();
    
    init(pos->lft, l, mid);
    init(pos->rht, mid+1, r);
    pos->val = pos->lft->val + pos->rht->val;
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
        if(!pos->rht)
            pos->rht = null;
        update(pos->lft, l, mid, idx, val);
    }
    else {
        pos->rht = nCopy(pos->rht);
        if(!pos->lft)
            pos->lft = null;
        update(pos->rht, mid+1, r, idx, val);
    }
    
    pos->val = 0;
    if(pos->lft)
        pos->val += pos->lft->val;
    if(pos->rht)
        pos->val += pos->rht->val;
}


// Range [L, R] update
void update(node *pos, ll l, ll r, ll L, ll R, ll val) {
    if(r < L || R < l)
        return;
    
    if(L <= l && r <= R) {
        pos->prop += val;
        pos->val += (r-l+1)*val;
        return;
    }
    
    ll mid = (l+r)>>1;
    
    pos->lft = nCopy(pos->lft);             // Can be reduced
    pos->rht = nCopy(pos->rht);
    
    update(pos->lft, l, mid, L, R, val);
    update(pos->rht, mid+1, r, L, R, val);
    
    pos->val = pos->lft->val + pos->rht->val + (r-l+1)*pos->prop;
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


// Ignore LMax presistant tree positions query for finding k'th value
int query(node *RMax, node *LMax, int l, int r, int k) {                         // (LMax : past, RMax : updated)
    if(l == r)
        return l;
    
    // NO NEED THIS SECTOR STILL AC --
    RMax->lft = nCopy(RMax->lft);
    LMax->lft = nCopy(LMax->lft);
    RMax->rht = nCopy(RMax->rht);
    LMax->rht = nCopy(LMax->rht);
    //--------------------------------
    
    
    // for each range [l, r] we will ignore every [1, l-1] range numbers
    
    int Count = RMax->lft->val - LMax->lft->val; 
    int mid = (l+r)>>1;
    
    // if there exists more than or equal to k values in left range, then we'll find kth number in left segment
    if(Count >= k)
        return query(RMax->lft, LMax->lft, l, mid, k);
    else
        return query(RMax->rht, LMax->rht, mid+1, r, k-Count);
}


// --------------- Propagation -------------------------

bool flipProp(bool par, bool child) {
    if(par == child)
        return 0;
    return 1;
}

void propagate(node *pos, ll l, ll r) {         // Propagation Func
    if(l == r)
        return;
    
    pos->lft = nCopy(pos->lft);                 // No need to copy in update/query function
    pos->rht = nCopy(pos->rht);
    
    if(!pos->flip)
        return;
    
    ll mid = (l+r)>>1;
    pos->lft->flip = flipProp(pos->flip, pos->lft->flip);
    pos->rht->flip = flipProp(pos->flip, pos->rht->flip);
    
    pos->lft->val = (mid-l+1)-pos->lft->val;
    pos->rht->val = (r-mid)-pos->rht->val;
    
    pos->flip = 0;
}


// Flip in range [L, R]
void updateFlip(node *pos, ll l, ll r, ll L, ll R) {
    if(r < L || R < l)
        return;
    
    propagate(pos, l, r);
    if(L <= l && r <= R) {
        pos->flip = 1;
        pos->val = (r-l+1) - pos->val;
        return;
    }
    
    ll mid = (l+r)>>1;
    
    updateFlip(pos->lft, l, mid, L, R);
    updateFlip(pos->rht, mid+1, r, L, R);
    
    pos->val = 0;
    if(pos->rht)
        pos->val += pos->rht->val;
    if(pos->lft)
        pos->val += pos->lft->val;
}


// Erasing A segment tree, pos = root, must run for each root
void ClearTree(node *pos) {
    if(pos == NULL) {
        delete pos;
        return;
    }

    ClearTree(pos->lft);
    ClearTree(pos->rht);
    
    delete pos;
}

int main() {
    // DEMO
    for(int i = 1; i <= 10; ++i) {
        presis[i] = nCopy(presis[i-1]);
        update(presis[i], 1, n, idx, val);
    }
     return 0;
 }
