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

struct RMQ {
    vector<ll>tree;
    
    void resize(ll sz) {
        tree.resize(sz, LONG_LONG_MIN);
    }
    
    void init(int pos, int l, int r, ll v[]) {
        if(l == r) {
            tree[pos] = v[l];
            return;
        }
        
        int mid = (l+r)>>1;
        
        init(pos<<1, l, mid, v);
        init(pos<<1|1, mid+1, r, v);
        
        tree[pos] = max(tree[pos<<1], tree[pos<<1|1]);
    }
    
    ll query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l)
            return LONG_LONG_MIN;
        
        if(L <= l && r <= R)
            return tree[pos];
        
        int mid = (l+r)>>1;
        
        ll x = query(pos<<1, l, mid, L, R);
        ll y = query(pos<<1|1, mid+1, r, L, R);
        
        return max(x, y);
    }
};

ll lsum[110000], rsum[110000], v[110000];

int main() {
    fileRead("in");
    fileWrite("out");
    
    ll tot, n, t, q, x1, x2, y1, y2;
    
    scanf("%lld", &t);
    
    while(t--) {
        scanf("%lld", &n);
        
        //rsum[n+1] = lsum[0] = 0;
        memset(rsum, 0, sizeof rsum);
        memset(lsum, 0, sizeof lsum);
        
        for(ll i = 1; i <= n; ++i) {
            scanf("%lld", &v[i]);
            lsum[i] = lsum[i-1] + v[i];
            //printf("%lld ", v[i]);
        }
        //printf("\n");
        
        for(int i = n; i >= 1; --i)
            rsum[i] = rsum[i+1]+v[i];
        
        tot = lsum[n];
        
        RMQ lSUM, rSUM;
        
        lSUM.resize(n*5);
        rSUM.resize(n*5);
        lSUM.init(1, 1, n, lsum);
        rSUM.init(1, 1, n, rsum);
        
        scanf("%lld", &q);
        
        for(ll i = 1; i <= q; ++i) {
            scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
            //printf("%d : %lld %lld %lld %lld\n", i, x1, y1, x2, y2);
            ll ans = lSUM.query(1, 1, n, x2, y2) + rSUM.query(1, 1, n, x1, y1) - tot;
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}
        
