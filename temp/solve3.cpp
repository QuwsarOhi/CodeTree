// Codeforces 
// C. Till I Collapse

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
    int val;
    node *lft, *rht;
    
    node(node *L = NULL, node *R = NULL, int v = 0) {
        lft = L;
        rht = R;
        val = v;
    }
};

node *presis[101000], *null;
int IDX[100000], val[100000];

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
        pos->lft = pos->rht = null;         // DEFINE NULL
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


int query(node *pos, int l, int r, int val) {
    
    if(l == r)
        return l;
    
    printf("At %d --------- %d :: %d %d: %d\n", l, r, pos->lft ? pos->lft->val:-1, pos->rht ? pos->rht->val:-1, pos->val);
    int mid = (l+r)>>1;
    
    if(pos->lft && pos->lft->val >= val) {
        printf("Going left\n");
        return query(pos->lft, l, mid, val);
    }
    else {
        printf("Going right\n");
        return query(pos->rht, mid+1, r, val-pos->lft->val);
    }
}


int main() {
    int n, x;
    
    cin >> n;
    
    null = new node();
    presis[0] = new node();
    null->lft = null;
    null->rht = null; 
    
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    
    for(int i = n; i >= 1; --i) {
        
        presis[i] = nCopy(presis[i-1]);
        
        if(IDX[val[i]])
            update(presis[i], 1, n, IDX[val[i]], -1);
        update(presis[i], 1, n, i, 1);
        IDX[val[i]] = i;
    }
    
    for(int k = 1; k <= n; ++k) {
        int cnt = 0, pos = k, tot = k;
        while(pos <= n) {                                       // How to gurantee that k values are in presis[pos] ?
            printf("Search from %d for %d\n", pos, tot);
                
            int idx = query(presis[pos], 1, n, tot);
            printf("Found at %d\n", idx);
            //tot += k;
            pos = idx+1;
            ++cnt;
        }
        
        cout << cnt << " ";
    }
    
    return 0;
}
