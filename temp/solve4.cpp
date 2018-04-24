#include <bits/stdc++.h>
using namespace std;
#define MAX                 510000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define pf                  printf
#define sf(XX)              scanf("%lld", &XX)
#define SIZE(a)             ((ll)a.size())
#define ALL(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define FOR(i, a, b)        for(ll i = (a); i < (ll)(b); ++i)
#define FORR(i, a, b)       for(ll i = (a); i > (ll)(b); --i)
#define FastIO              ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FileRead(S)         freopen(S, "r", stdin);
#define FileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define STOLL(X)            stoll(X, 0, 0)

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
typedef vector<ll>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

vll HASH, Power;
vl v;
const ll p = 11, mod1 = 1e9+9, mod2 = 1e9+7;
unordered_map<ll, vi>V;

void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
    }
}

pll SubHash(vll &Hash, ll l, ll r, ll LIM) {
    pll H;
    
    H.fi = (Hash[r].fi - (l-1 >= 0 ? Hash[l-1].fi:0) + mod1)%mod1;
    H.se = (Hash[r].se - (l-1 >= 0 ? Hash[l-1].se:0) + mod2)%mod2;
    
    H.fi = (H.fi * Power[LIM-l].fi)%mod1;
    H.se = (H.se * Power[LIM-l].se)%mod2;
    
    return H;
}

int main() {
    //FileRead("out");
    ll n, x, LIM = 100010;
    sf(n);
    
    PowerGen(100100);
    pll h = {0, 0};
    
    FOR(i, 0, n) {
        sf(x);
        v.pb(x);
        V[x].pb(i);
        
        h.fi = (h.fi + x * Power[i].fi)%mod1;
        h.se = (h.se + x * Power[i].se)%mod2;
        HASH.pb(h);
    }
    
    ll b = -1;
    FOR(i, 0, n) {
        //cout << "AT " << i << endl;
        auto L = V[v[i]].end();
        for(auto it = lower_bound(ALL(V[v[i]]), b); it != L; ++it) {
            ll idx = *it;
            //cout << "GOT " << idx << endl;
            if(idx < b or idx >= i)
                break;

            x = i - idx;
            
            if(idx-x+1 < 0)
                continue;
            
            //cout << "Range " << idx << " " << i << endl;
            
            pll H1 = SubHash(HASH, idx-x+1, idx, LIM);
            pll H2 = SubHash(HASH, idx+1, i, LIM);
            
            if(H1 == H2) {
                //cout << "MATCH \n";
                b = max(b, (ll)idx+1);
            }
        }
    }
    
    
    //cout << "B " << b << endl;
    if(b == -1) b = 0;
    pf("%lld\n", n-b);
    FOR(i, b, n)
        pf("%lld ", v[i]);
    
    return 0;
}
    
/*
8
1 2 1 2 1 2 1 2

*/
