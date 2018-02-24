// SPOJ - GSS2 - Can you answer these queries II
// http://www.spoj.com/problems/GSS2/

#include <bits/stdc++.h>
using namespace std;
#define MAX                 110000
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
    ll lazy, maxLazy, ans, childMax;
    
    node(ll val=0) {
        lazy = maxLazy = ans = childMax = val;
    }
};


node tree[5*MAX];
ll ans[MAX], val[MAX], IDX[3*MAX];
set<pair<pll, ll> >Query;

void propagate(int pos, int l, int r) {
    if(l == r)
        return;
    
    for(int child = pos<<1; child <= (pos<<1|1); ++child) {
        tree[child].maxLazy = max(tree[child].maxLazy, tree[child].lazy + tree[pos].maxLazy);
        tree[child].ans = max(tree[child].ans, tree[child].childMax + tree[pos].maxLazy);
        
        tree[child].lazy += tree[pos].lazy;
        tree[child].childMax += tree[pos].lazy;
    }
    
    tree[pos].lazy = tree[pos].maxLazy = 0;
}


void update(int pos, int l, int r, int L, int R, ll val) {
    if(r < L || R < l)
        return;
    
    propagate(pos, l, r);
    if(L <= l && r <= R) {
        tree[pos].maxLazy = max(tree[pos].maxLazy, tree[pos].lazy += val);
        tree[pos].ans = max(tree[pos].ans, tree[pos].childMax += val);
        
        return;
    }
    
    int mid = (l+r)>>1;
    
    update(pos<<1, l, mid, L, R, val);
    update(pos<<1|1, mid+1, r, L, R, val);
    
    tree[pos].ans = max(tree[pos<<1].ans, tree[pos<<1|1].ans);
    tree[pos].childMax = max(tree[pos<<1].childMax, tree[pos<<1|1].childMax);
}


ll query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l)
        return 0;
    
    propagate(pos, l, r);
    if(L <= l && r <= R)
        return tree[pos].ans;
    
    int mid = (l+r)>>1;
    
    return max(query(pos<<1, l, mid, L, R), query(pos<<1|1, mid+1, r, L, R));
}


int main() {
    ll n, l, r, q;
    
    scanf("%lld", &n);
    
    for(ll i = 1; i <= n; ++i)
        scanf("%lld", &val[i]);
    
    scanf("%lld", &q);
    for(ll i = 1; i <= q; ++i) {
        scanf("%lld %lld", &l, &r);
        Query.insert({{r, l}, i});
    }
    
    ll pos = 1;
    for(auto it : Query) {
        l = it.first.second;
        r = it.first.first;
        
        for( ; pos <= r; ++pos) {
            //printf("Update from %lld to %lld\n", IDX[val[pos]+100010]+1, pos);
            update(1, 1, n, IDX[val[pos]+100010]+1, pos, val[pos]); 
            IDX[val[pos]+100010] = pos;
        }
        
        ans[it.second] = query(1, 1, n, l, r);
    }
    
    for(int i = 1; i <= q; ++i)
        printf("%lld\n", ans[i]);
    
    return 0;
}
