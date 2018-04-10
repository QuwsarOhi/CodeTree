// Codeforces
// Sad Powers
// http://codeforces.com/contest/955/problem/C

// Number Theory

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

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

set<ll>Set;
vl val;

void PreCal(ll lim) {
    ll halfLim = pow(lim, 1/3.0);
    
    for(ll i = 2; i <= halfLim; ++i) {
        ll T = sqrt(i);
        
        if(T*T == i)
            continue;

        ll L = log(1e18)/log(i);
        T = i*i;
        
        for(ll p = 3, v = i*i*i; p <= L and v <= 1e18 and v > 0; v *= T, p += 2)
            Set.insert(v);
    }
    
    for(auto it : Set)
        val.push_back(it);
}


ll floorSqrt(ll x) {
    ll ret = sqrt(x);
    if(ret*ret > x)
        ret--;
    return ret;
}
            

int main() {
    PreCal(1e18);
    
    ll q, l, r;
    sf("%lld", &q);
    
    while(q--) {
        sf("%lld%lld", &l, &r);
        
        ll pSqr = floorSqrt(r) - floorSqrt(l-1);
        ll Ans = upper_bound(All(val), r) - lower_bound(All(val), l);
        
        pf("%lld\n", pSqr+Ans);
    }
    
    return 0;
}
