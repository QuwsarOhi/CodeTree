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

const ll p = 31, mod = 1e9+7;
vl Power, HASH;
vi v;
map<int, vi>IDX;

void PowerGen(int n) {
    Power.resize(n);
    Power[0] = 1;
    for(int i = 1; i < n; ++i)
        Power[i] = (Power[i-1] * p)%mod;
}

vl ContHash(vector<int> &s) {
    vl H;
    ll Hash = 0;
    
    for(int i = 0; i < (int)s.size(); ++i) {
        Hash = (Hash + s[i] * Power[i])%mod;
        H.pb(Hash);
    }
    return H;
}

ll SubHash(vl &Hash, ll l, ll r, ll LIM) {
    ll H;
    H = (Hash[r] - (l-1 >= 0 ? Hash[l-1]:0) + mod)%mod;
    H = (H * Power[LIM-l])%mod;
    return H;
}

int main() {
    //FileRead("out");
    //FileWrite("out2");
    int n, x;
    
    scanf("%d", &n);
    
    int LIM = n+100;
    
    PowerGen(n+1000);
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        v.push_back(x);
        IDX[x].push_back(i);
    }
    
    int mx = -1;
    for(auto it : IDX) mx = max(mx, (int)SIZE(it.se));
    
    //cout << "MAX " << mx << " " << SIZE(IDX) << endl;  
    
    HASH = ContHash(v);
    priority_queue<pii>pq;
    
    
    //cout << "PRECAL DONE\n";
    
    ll CNT = 0;
    for(auto it = IDX.begin(); it != IDX.end(); it++) {
        vi V = (it->se);
        //cout << it->fi << " " << SIZE(V) << endl;
        for(int i = 0; i < SIZE(V); ++i)
            for(int j = i+1; j < SIZE(V); ++j) {
                int l = V[i], r = V[j];
                //cout << "Boundary " << l << " " << r << " CNT " << CNT << endl;
                ++CNT;
                if(r+r-l-1 < n and SubHash(HASH, l, r-1, LIM) == SubHash(HASH, r, r+r-l-1, LIM)) {
                    //cout << "PB " << l << " " << r << endl;
                    pq.push({-(r-l), -l});
                }
            }
    }
    
    //cout << "PAIR DONE " << CNT << endl;
    
    int b = 0;
    while(!pq.empty()) {
        if(-pq.top().se >= b)
            b = -pq.top().fi-pq.top().se;
        pq.pop();
    }
    
    pf("%d\n", n-b);
    for(int i = b; i < n; ++i)
        pf("%d ", v[i]);
    pf("\n");
    return 0;
}
