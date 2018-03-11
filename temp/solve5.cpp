#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e9
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

struct SegLazy {
    vector<pair<ll, ll> > tree;         // Resize First
    
    void Resize(ll n) {
        tree.resize(5*n);
    }
    
    void init(int pos, int l, int r, ll val[]) {
        if(l == r) {
            tree[pos].fi = val[l];
            return;
        }
        
        int mid = (l+r)/2;
        init(pos*2, l, mid, val);
        init(pos*2+1, mid+1, r, val);
        tree[pos].fi = (tree[pos*2].fi + tree[pos*2+1].fi)%MOD;
    }

    // (l, r) : tree segment, (x, y) : update segment
    void update(int pos, int l, int r, int x, int y, ll val) {
        if(y < l || x > r)
            return;
	
        if(x <= l && r <= y) {		            // Tree segment in update segment
            tree[pos].fi = (((r-l+1)*val)%MOD + tree[pos].fi)%MOD;
            tree[pos].se = (val + tree[pos].se)%MOD;	            // Lazy
            return;
        }
	
        int mid = (l+r)/2LL;
	
        update(pos*2LL, l, mid, x, y, val);
        update(pos*2LL + 1, mid+1, r, x, y, val);
	
        tree[pos].fi = (tree[pos*2].fi + tree[pos*2+1].fi + (r-l+1)*tree[pos].se)%MOD;
    }

    // Pass propagate value through carry
    ll query(ll pos, ll l, ll r, ll x, ll y, ll carry = 0) {
        if(y < l || x > r)
            return 0;
	
        if(x <= l && r <= y)
            return (tree[pos].fi + (carry * (r-l+1)))%MOD;
	
        int mid = (l+r)/2LL;
        ll lft = query(pos*2LL, l, mid, x, y, carry + tree[pos].se);
        ll rht = query(pos*2LL + 1, mid+1, r, x, y, carry + tree[pos].se);
        return (lft + rht)%MOD;
    }
};

// A, 2A, 3A, 4A
struct SegTreeSequence {
    vector<ll>sum;
    vector<bool>prop;
    vector<ll>propVal;
    
    void Resize(ll n) {
        sum.resize(5*n);
        prop.resize(5*n);
        propVal.resize(5*n);
    }
    
    ll intervalSum(ll l, ll r, ll val) {
        ll tmp = (r*(r+1)/2 - l*(l-1)/2)%MOD;
        return (tmp*val)%MOD;
    }
    
    void propagate(int pos, int l, int r) {
        if(!prop[pos] || l == r)
            return;
        
        int mid = (l+r)>>1;
        sum[pos<<1] = (intervalSum(l, mid, propVal[pos]) + sum[pos<<1])%MOD;
        sum[pos<<1|1] = (intervalSum(mid+1, r, propVal[pos]) + sum[pos<<1|1])%MOD;
        prop[pos<<1] = prop[pos<<1|1] = 1;
        propVal[pos<<1] = (propVal[pos<<1] + propVal[pos])%MOD;
        propVal[pos<<1|1] = (propVal[pos<<1|1] + propVal[pos])%MOD;
        
        //printf("parent Prop : %lld\n", propVal[pos]);
        propVal[pos] = prop[pos] = 0;
        
        //printf("%d - %d : %lld\n", l, mid, sum[pos<<1]);
        //printf("%d - %d : %lld\n", mid+1, r, sum[pos<<1|1]);
    }
    
    void init(int pos, int l, int r, ll val[]) {
        if(l == r) {
            sum[pos] = (val[l]*l)%MOD;
            return;
        }
        
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }
    
    void update(int pos, int l, int r, int L, int R, ll val) {          // add val in range [L, R]
        if(r < L || R < l)
            return;
            
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            //cout << l << " - " << r << " adding " << intervalSum(l, r, val) << endl;
            sum[pos] = (intervalSum(l, r, val)+ sum[pos])%MOD;
            prop[pos] = 1;
            propVal[pos] = (val + propVal[pos])%MOD;
            return;
        }
        
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }
    
    ll query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l)
            return 0;
        
        propagate(pos, l, r);
        if(L <= l && r <= R)
            return sum[pos];
        
        int mid = (l+r)>>1;
        return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R))%MOD;
    }
};
    

SegLazy rangeSum;
SegTreeSequence series;
ll val[110000];

void check(int n) {
    for(int i = 1; i <= n; ++i)
        cout << series.query(1, 1, n, 1, i) << " ";
    cout << endl;
}

int main() {
    ll l, r, d, typ, n, q, t;
    
    scanf("%lld", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &n, &q);
        
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &val[i]);
            //cout << val[i] << endl;
        }
        
        rangeSum.Resize(n);
        series.Resize(n);
        
        rangeSum.init(1, 1, n, val);
        series.init(1, 1, n, val);
        //cout << "INIT DONE\n";
        printf("Case %d:\n", Case);
        
        while(q--) {
            scanf("%lld%lld%lld%lld", &typ, &l, &r, &d);
            d = (d+MOD)%MOD;
            
            if(typ == 1) {
                rangeSum.update(1, 1, n, l, r, d);
                series.update(1, 1, n, l, r, d);
            }
            else {
                ll sum = rangeSum.query(1, 1, n, l, r);
                ll seriesSum = 0;
                
                //cout << "Sum " << sum << endl;
                //cout << "Seq " << (series.query(1, 1, n, l+1, r) - rangeSum.query(1, 1, n, l+1, r)*l) << endl;
                
                
                if(l < r)
                    seriesSum = ((series.query(1, 1, n, l+1, r) - rangeSum.query(1, 1, n, l+1, r)*l + MOD)*d)%MOD;
                
                printf("%lld\n", (sum+seriesSum)%MOD);
            }
            
            //cout << "CHK ";
            //check(n);
        }
    }
    return 0;
}
