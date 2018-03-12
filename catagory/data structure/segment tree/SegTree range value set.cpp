// CodeForces
// http://codeforces.com/contest/292/problem/E


#include <bits/stdc++.h>
using namespace std;
#define MAX                 110000
#define LIM                 100
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

// Only Supports Range Value set and Point Query
struct SegTree {
    vector<int>tree;
    vector<bool>prop;
    
    void init(int n) {
        tree.resize(n+10);
        prop.resize(n+10);
    }
    
    void propagate(int pos, int l, int r) {
        if(!prop[pos] || l == r)
            return;
        tree[pos<<1|1] = tree[pos<<1] = tree[pos];
        prop[pos<<1|1] = prop[pos<<1] = 1;
        prop[pos] = 0;
    }
    
    void update(int pos, int l, int r, int L, int R, int val) {
        if(r < L || R < l)
            return;
        
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            tree[pos] = val;
            prop[pos] = 1;
            return;
        }
        
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
    }
    
    int query(int pos, int l, int r, int idx) {
        if(l == r)
            return tree[pos];
        
        propagate(pos, l, r);
        int mid = (l+r)>>1;
        if(idx <= mid)
            return query(pos<<1, l, mid, idx);
        else
            return query(pos<<1|1, mid+1, r, idx);
    }
};

SegTree aStart;
SegTree bStart;

ll a[MAX], b[MAX];

void errorTest(int n) {
    for(int i = 1; i <= n; ++i)
        printf("%d ", aStart.query(1, 1, n, i));
    printf("\n");
    for(int i = 1; i <= n; ++i)
        printf("%d ", bStart.query(1, 1, n, i));
    printf("\n");
}

int main() {
    int n, q, t, x, y, k;
    
    scanf("%d%d", &n, &q);
    
    aStart.init(5*n);
    bStart.init(5*n);
    
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &b[i]);
    
    while(q--) {
        scanf("%d", &t);
        
        if(t == 1) {
            scanf("%d%d%d", &x, &y, &k);
            
            aStart.update(1, 1, n, y, y+k-1, x);
            bStart.update(1, 1, n, y, y+k-1, y);
        }
        else {
            scanf("%d", &x);
            y = aStart.query(1, 1, n, x);
            k = bStart.query(1, 1, n, x);
            
            if(y == 0)
                printf("%lld\n", b[x]);
            else
                printf("%lld\n", a[y+x-k]);
        }
    }
    
    return 0;
}
