// CodeChef
// ForbiddenSum - FRBSUM

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
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

vl val[MAX*5], prefix[MAX*5];
int v[MAX];

void init(int pos, int l, int r) {
    if(l == r) {
        val[pos].pb(v[l]);
        prefix[pos].pb(v[l]);
        return;
    }
    
    int mid = (l+r)>>1;
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    
    merge(val[pos<<1].begin(), val[pos<<1].end(), val[pos<<1|1].begin(), val[pos<<1|1].end(), back_inserter(val[pos]));
    merge(val[pos<<1].begin(), val[pos<<1].end(), val[pos<<1|1].begin(), val[pos<<1|1].end(), back_inserter(prefix[pos]));
    
    for(int i = 1; i < SIZE(prefix[pos]); ++i)
        prefix[pos][i] += prefix[pos][i-1];
}

ll query(int pos, int l, int r, int L, int R, ll sum) {
    if(r < L || R < l)
        return 0;
    
    if(L <= l && r <= R) {
        int idx = upper_bound(val[pos].begin(), val[pos].end(), sum) - val[pos].begin();
        if(idx <= 0)
            return 0;
        return prefix[pos][idx-1];
    }
    
    int mid = (l+r)>>1;
    
    return query(pos<<1, l, mid, L, R, sum) + query(pos<<1|1, mid+1, r, L, R, sum);
}



int main() {
    int n, q, l, r;
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    
    init(1, 1, n);
    scanf("%d", &q);
    
    while(q--) {
        scanf("%d%d", &l, &r);
        
        ll cSum = 0;
        while(1) {
            ll newSum = query(1, 1, n, l, r, cSum+1);
            
            if(newSum <= cSum)
                break;
            cSum = newSum;
        }
        printf("%lld\n", cSum+1);
    }
    
    return 0;
}


/*
Input:
7
3 1 4 2 1 1 5
6
1 3
2 4
2 6
3 4
3 7
2 3
Output:
2
8
10
1
14
2
*/
