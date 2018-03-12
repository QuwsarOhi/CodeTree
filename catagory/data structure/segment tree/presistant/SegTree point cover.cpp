// Codeforces
// http://codeforces.com/contest/500/problem/E
// New Year Domino

// Point cover

#include <bits/stdc++.h>
using namespace std;
#define MAX                 201000
#define LIM                 1000000002
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
    int val;
    bool prop;
    node *lft, *rht;
    
    node(int l, int r) {
        prop = 0;
        val = r-l+1;
        lft = NULL;
        rht = NULL;
    }
};

// if prop is on, then we should zero child node values
void propagate(node *root, int l, int r) {
    if(!root->prop || l == r)
        return;

    int mid = (l+r)>>1;
    if(!root->lft) root->lft = new node(l, mid);
    if(!root->rht) root->rht = new node(mid+1, r);
    
    if(root->lft->val != 0) {
        root->lft->val = 0;
        root->lft->prop = 1;
    }
    
    if(root->rht->val != 0) {
        root->rht->val = 0;
        root->rht->prop = 1;
    }
    
    root->prop = 0;
}

void update(node *root, int l, int r, int L, int R) {
    if(r < L || R < l)
        return;
    
    if(root->val == 0) return;          // it is already off
    if(L <= l && r <= R) {
        root->val = 0;
        root->prop = 1;
        return;
    }
    
    int mid = (l+r)>>1;
    if(!root->lft) root->lft = new node(l, mid);
    if(!root->rht) root->rht = new node(mid+1, r);
    
    update(root->lft, l, mid, L, R);
    update(root->rht, mid+1, r, L, R);
    
    root->val = root->lft->val + root->rht->val;
}


ll query(node *root, int l, int r, int L, int R) {
    if(r < L || R < l || root->val == 0)            // if this node has value 0, no need to go deeper
        return 0;

    propagate(root, l, r);
    if(L <= l && r <= R)
        return root->val;
    
    int mid = (l+r)>>1;
    if(!root->lft) root->lft = new node(l, mid);
    if(!root->rht) root->rht = new node(mid+1, r);
    
    
    return query(root->lft, l, mid, L, R) + query(root->rht, mid+1, r, L, R);
}


node *root = new node(1, LIM);
int h[MAX], x[MAX], ans[MAX];
vii Query[MAX];

int main() {
    int n, q, l, r;
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &h[i]);
    
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i) {
        scanf("%d%d", &l, &r);
        Query[l].push_back({r, i});
    }
    
    for(int i = n; i > 0; --i) {
        update(root, 1, LIM, x[i], min(x[i]+h[i]-1, int(LIM)));
        
        for(auto it : Query[i])
            ans[it.second] = query(root, 1, LIM, x[i], x[it.first]-1);
    }
    
    for(int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
    
    return 0;
}
