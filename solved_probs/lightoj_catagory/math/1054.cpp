// LightOJ
// http://lightoj.com/volume_showproblem.php?problem=1054
// 1054 - Efficient Pseudo Code

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
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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

bitset<100100>isPrime;
vi prime;

void sieve(ll lim) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    
    for(ll i = 2; i <= lim; ++i)
        if(isPrime[i]) {
            prime.pb(i);
            for(ll j = i*i; j <= lim; j += i)
                isPrime[j] = 0;
        }
}


map<ll, ll> factorize(ll val, ll power) {
    map<ll, ll>factor;
    power %= (MOD-1);
    for(int i = 0; i < SIZE(prime); ++i) {
        if(ll(prime[i]*prime[i]) > val)
            break;
        ll cnt = 0;
        while(val%prime[i] == 0) {
            val /= prime[i];
            cnt++;
        }
        if(cnt)
            factor[prime[i]] = (power * (cnt % (MOD-1))) % (MOD-1);
    }
    
    if(val != 1)
        factor[val] = power;
    
    return factor;
}
 

ll gcdExtended(ll a, ll b, ll *x, ll *y) {          // C function for extended Euclidean Algorithm
    if (a == 0) {                                   // Base Case
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1;                                     // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
ll modInverse(ll a, ll mod) {
    ll x, y;
    ll g = gcdExtended(a, mod, &x, &y);
    if (g != 1)                             // ModInverse doesnt exist
        return -1;
    ll res = (x%mod + mod) % mod;           // m is added to handle negative x
    return res;
}


long long powMod(long long N, long long P, long long M) {
	if(P==0)
		return 1;
	if(P%2==0) {
		long long ret = powMod(N, P/2, M)%M;
		return (ret * ret)%M;
	}
    return ((N%M) * (powMod(N, P-1, M)%M))%M;
}

ll SumOfDiv(map<ll, ll>&factor) {
    map<ll, ll> :: iterator it;
    ll sumDiv = 1;
    for(it = factor.begin(); it != factor.end(); ++it) {
        ll n = it->first;
        ll p = it->second;
        
        ll up = ((powMod(n, p+1, MOD) - 1) + MOD)%MOD;
        ll down = modInverse(n-1, MOD);
        
        sumDiv = (sumDiv * ((up*down) % MOD)) % MOD;
    }
    
    return sumDiv;
}


int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t;
    ll n, m;
    map<ll, ll> factor;
    
    sf("%d", &t);
    sieve(100000);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%lld %lld", &n, &m);
        factor = factorize(n, m);
        
        ll ans = SumOfDiv(factor);
        pf("Case %d: %lld\n", Case, ans);
        factor.clear();
    }
    
    return 0;
}
