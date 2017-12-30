// Codeforces
// D. Multipliers
// http://codeforces.com/contest/615/problem/D

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e9+10
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

ll powMod(ll N, ll P, ll M) {
	if(P==0)
		return 1;
	if(!(P&1)) {
		ull ret = powMod(N, P/2, M)%M;
		return (ret * ret)%M;
	}
	else
		return ((N%M) * (powMod(N, P-1, M)%M))%M;
}


int main() {
    map<ll, ll>prime;
    ll n, x, lftMul[200010], rhtMul[200010], idx, ans;
    cin >> n;
    
    while(n--) {
        cin >> x;
        prime[x]++;
    }
    
    for(int i = 0; i <= 200005; ++i)
        lftMul[i] = rhtMul[i] = 1;
    
    idx = 1;
    for(auto it = prime.begin(); it != prime.end(); ++it, ++idx)
        lftMul[idx] = (lftMul[idx-1] * (it->second+1)) % (MOD-1);
    
    idx = SIZE(prime);
    for(auto it = prime.rbegin(); it != prime.rend(); ++it, --idx)
        rhtMul[idx] = (rhtMul[idx+1] * (it->second+1)) % (MOD-1);
    
    ans = idx = 1;
    for(auto it : prime) {
        ll val = it.first;
        ll power = it.second;
        ll mul = (lftMul[idx-1] * rhtMul[idx+1]) % (MOD-1);
        
        power = ((power * (power+1))/2) % (MOD-1);
        power = (power * mul) % (MOD-1);
                
        ll tmp = powMod(val, power, MOD);
        ans = (ans * tmp) % MOD;
        ++idx;
    }
    
    cout << ans << endl;
    return 0;
}
