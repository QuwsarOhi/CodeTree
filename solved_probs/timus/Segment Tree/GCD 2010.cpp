// TIMUS - GCD 2010
// http://acm.timus.ru/problem.aspx?space=1&num=1846

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

ll val[110000], tree[510000];

void update(ll pos, ll l, ll r, ll idx, ll val) {
    if(l == r) {
        tree[pos] = val;
        return;
    }
    
    ll mid = (l+r)>>1;
    
    if(idx <= mid)
        update(pos<<1, l, mid, idx, val);
    else
        update(pos<<1|1, mid+1, r, idx, val);
    
    if(!tree[pos<<1])
        tree[pos] = tree[pos<<1|1];
    else if(!tree[pos<<1|1])
        tree[pos] = tree[pos<<1];
    else
        tree[pos] = __gcd(tree[pos<<1], tree[pos<<1|1]);
}

map<ll, ll>Count, IDX;
bitset<110000>first;

int main() {
    ll n, idx = 0, val;
    char c;
    
    scanf("%lld", &n);
    
    for(int i = 0; i < n; ++i) {
        scanf(" %c%lld", &c, &val);
        
        if(c == '+') {
            Count[val]++;
            if(Count[val] == 1) {
                if(IDX[val] == 0)
                    IDX[val] = ++idx;
                update(1, 1, n, IDX[val], val);
            }
            printf("%lld\n", tree[1]);
        }
        else {
            Count[val]--;
            if(Count[val] == 0)
                update(1, 1, n, IDX[val], 0);
            printf("%lld\n", max(tree[1], 1LL));
        }
    }
    
    return 0;
}
        
