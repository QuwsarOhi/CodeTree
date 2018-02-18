// SPOJ - KGSS
// http://www.spoj.com/problems/KGSS/

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

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

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------

struct node {
    ll a, b;
    
    node(ll a = -1, ll b = -1) {
        this->a = a;
        this->b = b;
    }
    
    void merge(node a, node b) {
        ll v[] = {a.a, a.b, b.a, b.b};
        sort(v, v+4);
        this->a = v[3];
        this->b = v[2];
    }
};


node tree[5*1000000];
ll v[1000000];

void init(int pos, int l, int r) {
    if(l == r) {
        tree[pos] = node(v[l], -1);
        return;
    }
    
    int mid = (l+r)>>1;
    
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    
    tree[pos].merge(tree[pos<<1], tree[pos<<1|1]);
}


node query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l)
        return node(-1, -1);
    
    if(L <= l && r <= R)
        return tree[pos];
    
    int mid = (l+r)>>1;
    
    node x = query(pos<<1, l, mid, L, R);
    node y = query(pos<<1|1, mid+1, r, L, R);
    
    node tmp = node(-1, -1);
    tmp.merge(x, y);
    
    return tmp;
}


void update(int pos, int l, int r, int idx, ll val) {
    if(l == r) {
        tree[pos] = node(val, -1);
        return;
    }
    
    int mid = (l+r)>>1;
    
    if(idx <= mid)
        update(pos<<1, l, mid, idx, val);
    else
        update(pos<<1|1, mid+1, r, idx, val);
    
    tree[pos].merge(tree[pos<<1], tree[pos<<1|1]);
}
    
int main() {
    ll l, r, n, q;
    char c;
    
    scanf("%lld", &n);
    
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &v[i]);
    
    init(1, 1, n);
    
    scanf("%lld", &q);
    
    while(q--) {
        scanf(" %c%lld%lld", &c, &l, &r);
        
        if(c == 'Q') {
            node t = query(1, 1, n, l, r);
            printf("%lld\n", t.a+t.b);
        }
        else
            update(1, 1, n, l, r);
    }
        
    return 0;
}
