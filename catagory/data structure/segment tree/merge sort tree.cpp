// SOPJ - KQUERYO
// http://www.spoj.com/problems/KQUERYO/

// SEGMENT TREE WITH VECTORS (Merge Sort Tree)
// at each level there exists total of n values (if we sum up all vector element sizes at each level)
// there is log_n levels of a segment tree of 1 - n interval

// so total memory complexity nlog_n

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

vi tree[1200000];
int val[1200000];

void init(int pos, int l, int r) {
    if(l == r) {
        tree[pos].pb(val[l]);
        return;
    }
    
    int mid = (l+r)>>1;
    
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    
    merge(tree[pos<<1].begin(), tree[pos<<1].end(), tree[pos<<1|1].begin(), tree[pos<<1|1].end(), back_inserter(tree[pos]));
}


int query(int pos, int l, int r, int L, int R, int k) {
    if(r < L || R < l)
        return 0;
    
    if(L <= l && r <= R)
        return (int)tree[pos].size() - (upper_bound(tree[pos].begin(), tree[pos].end(), k) - tree[pos].begin());
    
    int mid = (l+r)>>1;
    
    return query(pos<<1, l, mid, L, R, k) + query(pos<<1|1, mid+1, r, L, R, k);
}


int main() {
    ll n, l, r, k, q, lst;
    
    scanf("%lld", &n);
    
    for(int i = 1; i <= n; ++i) 
        scanf("%d", &val[i]);
    
    scanf("%lld", &q);
    
    init(1, 1, n);
    lst = 0;
    
    while(q--) {
        scanf("%lld%lld%lld", &l, &r, &k);
        l ^= lst;
        r ^= lst;
        k ^= lst;
        if(l < 1)
            l = 1;
        if(r > n)
            r = n;
        if(l > r) {
            lst = 0;
            printf("0\n");
        }
        else {
            lst = query(1, 1, n, l, r, k);
            printf("%lld\n", lst);
        }
    }
    
    return 0;
}
    
