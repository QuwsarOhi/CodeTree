// UVa
// 13085 - Forming Teams

#include <bits/stdc++.h>
using namespace std;
#define MAX                 1000010
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


ll powerMOD(ll x, ll y) {                   // Can find modular inverse by a^(MOD-2),  a and MOD must be co-prime
    ll res = 1;
    x %= MOD;
    while(y > 0) {
        if(y&1) res = (res*x)%MOD;          // If y is odd, multiply x with result
        y = y >> 1, x = (x * x)%MOD;
    }
    return res%MOD;
}

// Multinomial : nC(k1,k2,k3,..km)    is such that k1+k2+k3+....km = n and ki == kj and ki != kj both can be possible.
// Here Multinomial can be described as : nC(k1, k2, .. km) = nCk1 * (n-k1)Ck2 * (n-k1-k2)Ck3 * ..... (n-k1-k2-...)Ckm
// Let (a+b+c)^3 = a^3 + b^3 + c^3 + 3a^2b + 3b^c + 3b^2a + 3b^2c + 3c^2a + 3c^2b + 6abc
// The coefficient can be retrieved as : 6abc = 3C(1, 1, 1) = 6     3b^2c = 3C(0, 2, 1) = 3
// In general terms it tells how many ways we can place k1, k2, k3, k4 people in 3 unique teams such that k1+k2+k3
// NOTE: if k1=k2=k3 = 2 and n = 6, and players numberd from 1 to 6, then 1,2|3,4|5,6 and 3,4|1,2|5,6 are considered to be different

ll fa[MAX] = {0};                                       // fa and fainv must be in global
ll Multinomial(ll N, vector<ll>& K) {                   // K contains all k1, k2, k3,  if k1=k2=k3, then just push k1 once!!
    if(fa[0] == 0) {                                    // Auto initialize
        fa[0] = 1; //fainv[0] = powerMOD(1, MOD-2);
        for(int i = 1; i < MAX; ++i) {
            fa[i] = (fa[i-1]*i) % MOD;                  // Constant MOD
            //fainv[i] = powerMOD(fa[i], MOD-2);        // Use factorial inverse if required
    }}
    ll k = 1;
    if((int)K.size() == 1)  k = powerMOD(fa[K[0]], N/K[0]);         // k1 = k2 = .. = km, so k occurs N/K time
    else for(auto it : K)   k = (k*fa[it])%MOD;
    return (fa[N]*powerMOD(k, MOD-2))%MOD;                          // Inverse mod
}

ll NumOfWaysToPlace(ll N, ll K) {                                   // Number of ways to make N/K teams from N people so that each team contais K people
    vector<ll>v;                                                    // If N = 6, then 1,2|3,4|5,6  and  3,4|1,2|5,6 is considered same
    v.push_back(K);
    return (Multinomial(N, v)*powerMOD(fa[N/K], MOD-2))%MOD;        // divide by k!, as 1,2|3,4|5,6  and  3,4|1,2|5,6 is considered same
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    ll t, n;
    
    scanf("%lld", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld", &n);
        
        ll lim = sqrt(n), sum = 0;
        for(int d = 2; d <= lim; ++d) {
            if(n%d != 0) continue;
            sum += NumOfWaysToPlace(n, d);
            if(n/d != d) sum += NumOfWaysToPlace(n, n/d);
            sum %= MOD;
        }
        if(n >= 1) ++sum;
        if(n > 1) ++sum;
        printf("Case %d: %lld\n", Case, sum%MOD);
    }
    return 0;
}
