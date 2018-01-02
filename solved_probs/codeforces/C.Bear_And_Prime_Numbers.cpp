// Codeforces
// C. Bear and Prime Numbers
// http://codeforces.com/contest/385/problem/C


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


bitset<10001000>isPrime;
vi primes;
int f[10000100], divisor[10000100];
map<int, int>Map;

void sieve(ll lim) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 0; i <= lim; ++i) {
        if(isPrime[i]) {
            primes.pb(i);
            for(ll j = i; j <= lim; j += i) {
                isPrime[j] = 0;
                divisor[j] = i;
            }
        }
    }
}


void factorize(int val, int cnt) {
    if(isPrime[val]) {
        f[val] += cnt;
        return;
    }
    for(int i = 0; i < SIZE(primes); ++i) {
        if(primes[i] > val)
            break;
        
        if(val%primes[i] == 0)
            f[primes[i]] += cnt;
        
        while(val%primes[i] == 0)
            val /= primes[i];
    }
    
    if(val != 1)
        f[val] += cnt;
}


int main() {
    //fileRead("in");
    //FastRead;
    sieve(10000010);
    
    //cout << "done\n";
    int n, x, l, r, q;
    sf("%d", &n);
    
    for(int i = 0; i < n; ++i) {
        sf("%d", &x);
        int pastDiv = 0;                    // 0 : no divisor is present
        while(x > 1) {
            if(divisor[x] != pastDiv)       // For this problem, a divisor is counted only once
                f[divisor[x]]++;
            pastDiv = divisor[x];
            x /= divisor[x];
        }
    }
    
    for(auto it : Map)
        factorize(it.first, it.second);
    
    for(int i = 1; i <= 10000000; ++i)
        f[i] += f[i-1];
    
    sf("%d", &q);
    while(q--) {
        sf("%d %d", &l, &r);
        l = min(10000000, l);
        r = min(10000000, r);
        
        pf("%d\n", f[r]-f[l-1]);
    }
    
    return 0;
}
