// SPOJ DQUERY
// Segment Tree/BIT

// Number of unique values in sub array

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

int tree[31000], val[30100], IDX[1001000], MaxVal = 30100;
set<pair< pair<int, int>, int> >Boundary;

void update(int idx, int val) {
    for( ; idx <= MaxVal; idx += idx&-idx)
        tree[idx] += val;
}

int read(int idx) {
    ll sum = 0;
    for( ; idx > 0; idx -= idx&-idx)
        sum += tree[idx];
    return sum;
}

int main() {
    int n, l, r, q;
    FastRead;
    
    cin >> n;
    
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    
    cin >> q;
    
    for(int i = 0; i < q; ++i) {
        cin >> l >> r;
        Boundary.insert({{r, l}, i});
    }
    
    int pos = 1;
    vector<int>ans(q);
    memset(IDX, -1, sizeof IDX);
    
    for(auto it : Boundary) {
        r = it.first.first, l = it.first.second;
        
        for( ; pos <= r; ++pos) {
            if(IDX[val[pos]] == -1) {
                update(pos, 1);
                IDX[val[pos]] = pos;
            }
            else {
                int pstPos = IDX[val[pos]];
                IDX[val[pos]] = pos;
                update(pos, 1);
                update(pstPos, -1);
            }
        }
        
        ans[it.second] = read(r) - read(l-1);
    }
    
    for(auto it : ans)
        cout << it << "\n";
    
    return 0;
}
