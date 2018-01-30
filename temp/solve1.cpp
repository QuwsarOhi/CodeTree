// SPOJ
// MKTHNUM - K-th Number
// Presistant Segment Tree


#include <bits/stdc++.h>
using namespace std;
#define MAX                 50
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
#define StrToInt(STR)       stoi(STR, nullptr)
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
    int val;
    node *lft, *rht;
    
    node(node *l = NULL, node *r = NULL, int v = 0) {
        lft = l;
        rht = r;
        val = v;
    }
};

map<ll, ll>Map, RMap;
ll val[110000];
node *presis[100000];


node *nCopy(node *x) {                  // initialize if value doesn't exist
    node *tmp = new node();
    if(x) {
        tmp->val = x->val;
        tmp->lft = x->lft;
        tmp->rht = x->rht;
    }
    return tmp;
}

void nINIT(node *x) {
    x = nCopy(x);
}

void update(node *pos, int l, int r, int idx) {
    if(l == r) {
        pos->val += 1;
        return;
    }
    
    int mid = (l+r)>>1;
    
    if(idx <= mid) {
        pos->lft = nCopy(pos->lft);
        update(pos->lft, l, mid, idx);
    }
    else {
        pos->rht = nCopy(pos->rht);
        update(pos->rht, mid+1, r, idx);
    }
    
    pos->val = 0;
    if(pos->lft != NULL)
        pos->val += pos->lft->val;
    if(pos->rht != NULL)
        pos->val += pos->rht->val;
}


int query(node *RMax, node *LMax, int l, int r, int k) {
    if(l == r)
        return l;
        
    RMax->lft = nCopy(RMax->lft);
    LMax->lft = nCopy(LMax->lft);
    RMax->rht = nCopy(RMax->rht);
    LMax->rht = nCopy(LMax->rht);
    
    // for each range [l, r] we will ignore every [1, l-1] range numbers
    
    int Count = RMax->lft->val - LMax->lft->val; 
    int mid = (l+r)>>1;
    
    // if there exists more than or equal to k values in left range, then we'll find kth number in left segment
    
    if(Count >= k)
        return query(RMax->lft, LMax->lft, l, mid, k);
    else
        return query(RMax->rht, LMax->rht, mid+1, r, k-Count);
}


int main() {
    //fileRead("in");
    int n, m, l, r, k, pos;
    
    sf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; ++i) {
        sf("%lld", &val[i]);
        Map[val[i]];
    }
    
    int idx = 0;
    for(auto it = Map.begin(); it != Map.end(); ++it) {         // Assigning value to it's sorted index
        it->second = ++idx;
        RMap[idx] = it->first;
    }
    
    for(int i = 1; i <= n; ++i) {
        presis[i] = nCopy(presis[i-1]);
        update(presis[i], 1, idx, Map[val[i]]);
    }
    
    node *dummy = new node();
    
    while(m--) {
        sf("%d %d %d", &l, &r, &k);
        if(l == 1)
            pos = query(presis[r], dummy, 1, idx, k);
        else
            pos = query(presis[r], presis[l-1], 1, idx, k);
        pf("%lld\n", RMap[pos]);
    }
    
    return 0;
}
