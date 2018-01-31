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
    node(node *L = NULL, node *R = NULL, ll v = 0) {
        val = v;
        L = lft;
        R = rht;
    }
};


node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->lft = x->lft;
        tmp->rht = x->rht;
        tmp->val = x->val;
    }
    return tmp;
}

void nINIT(node *x) {
    x = nCopy(x);
}

void update(node *pos, int l, int r, int idx, int val) {
    if(l == r) {
        pos->val += 1;
        return;
    }
    
    int mid = (l+r)>>1;
    
    if(idx <= mid) {
        nINIT(pos->lft);
        update(pos->lft, l, mid, idx, val);
    }
    else {
        nINIT(pos->rht);
        update(pos->rht, mid+1, r, idx, val);
    }
    
    pos->val = 0;
    if(pos->lft)
        pos->val += pos->lft->val;
    if(pos->rht)
        pos->val += pos->rht->val;
}


int query(node *lca0, node *lca, node *u, node *v, int l, int r, int k) {
    if(l == r)
        return l;
    
    nINIT(lca0);
    nINIT(lca);
    nINIT(u);
    nINIT(v);
    
    int mid = (l+r)>>1;
    int Count = u->lft->val + v->lft->val - lca->lft->val - lca0->lft->val;
    
    if(Count <= k)
        return query(lca0->lft, lca->lft, u->lft, v->lft, l, mid, k);
    else
        return query(lca0->rht, lca->rht, u->rht, v->rht, mid+1, r, k);
}


void dfs(int u, int prnt, int lvl) {
    // For Sparce Table
    level[u] = lvl;
    parent[u] = prnt;
    
    // Segment Tree
    update(presis[prnt], 1, V, Map[val[u]], 1);
    
    for(auto v : G[u])
        if(parent[u][0] != v)
            dfs(v, u, lvl+1);
}


void LCAinit() {
    
}

