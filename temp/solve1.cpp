#include <bits/stdc++.h>
using namespace std;
#define MAX                 13333333
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

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

// 13333333

bitset<MAX+10>isPrime;
vector<ll>primes, v;

void sieveGen(unsigned long long N) {
    isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for(unsigned long long i = 2; i <= N; i++) {
		if(isPrime[i]) {
			for(unsigned long long j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
            if(i != 2)
                primes.push_back(i);
		}
	}
}


void Gen() {
    for(register int i = 0; i < SIZE(primes)-2; ++i)
        for(register int j = i+1; j < SIZE(primes)-1; ++j)
            for(register int k = j+1; k < SIZE(primes); ++k)
                v.pb(primes[i]*primes[j]*primes[k]);
    
    sort(v.begin(), v.end());
}

int main() {
    sieveGen(MAX);
    Gen();
    
    //for(int i = 0; i < min(20, SIZE(v)); ++i)
    //    cout << v[i] << " ";
    //cout << endl;
    
    ll t, l, r;
    sf("%lld", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%lld%lld", &l, &r);
        auto L = lower_bound(v.begin(), v.end(), l);
        auto R = lower_bound(v.begin(), v.end(), r);
        
        pf("Case %d: ", Case);
        
        if(L == R)
            pf("0\n");
        else {
            if(*R > r) --R;
            pf("%d\n", (R-v.begin()) - (L-v.begin()) + 1);
        }
    }
    
    return 0;
}
