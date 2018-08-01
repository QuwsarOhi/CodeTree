#include <bits/stdc++.h>
using namespace std;
#define MAX                 1000009
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

ll powerMOD(ll x, ll y, ll mod) {                   // Can find modular inverse by a^(MOD-2),  a and MOD must be co-prime
    ll res = 1;
    x %= mod;
    while(y > 0) {
        if(y&1) res = (res*x)%mod;          // If y is odd, multiply x with result
        y = y >> 1, x = (x * x)%mod;
    }
    return res%mod;
}

bool miillerTest(int d, int n) {        
    int a = 2 + rand() % (n - 4);       // Pick a random number in [2..n-2]. 
    int x = powerMOD(a, d, n);               // Compute a^d % n
    if (x == 1  || x == n-1)
       return 1;
    while (d != n-1) {                      // Keep squaring x while one of the following doesn't happen
        x = (x * x) % n;                    // (i)   d does not reach n-1
        d *= 2;                             // (ii)  (x^2) % n is not 1
        if (x == 1)      return 0;          // (iii) (x^2) % n is not n-1
        if (x == n-1)    return 1;
    }
    return 0;               // Return composite
}

bool isPrime(int n, int k = 10) {               // Higher value of k gives more accuracy (Use k >= 9)
    if(n <= 1 || n == 4)  return 0;             // Corner cases
    if(n <= 3) return 1;
    int d = n - 1;                              // Find r such that n = 2^d * r + 1 for some r >= 1
    while(d % 2 == 0)  d /= 2;
    for(int i = 0; i < k; i++)                  // Iterate given nber of 'k' times
        if(miillerTest(d, n) == 0)
            return 0;
    return 1;
}

int pd[MAX];                        // Contains minimum prime factor/divisor, for primes pd[x] = x
vector<int>primes;                  // Contains prime numbers
void SieveLinear(int N) {
    pd[1] = 1;
    for(int i = 2; i <= N; ++i) {
        if(pd[i] == 0) pd[i] = i, primes.push_back(i);                  // if pd[i] == 0, then i is prime
        for(int j=0; j < (int)primes.size() && primes[j] <= pd[i] && i*primes[j] <= N; ++j)
            pd[i*primes[j]] = primes[j];
}}

unordered_map<int, int>MP;

bool checkOK2(int &x, int k) {
    // if this is prime return 0
    
    if(isPrime(x))
        return 0;
    
    for(auto p : primes) {
        if(p > x or p > k) break;
        while(x%p == 0)
            x /= p;
    }
    
    if(x <= k) {
        x = 1;
        return 1;
    }
    return 0;
}

bool checkOK1(int &x, int k) {
    //cerr << "GOT " << x << endl;
    while(x > k) {
        int T = pd[x];
        if(T > k) break;
        //cerr << x << " / " << pd[x] << endl;
        x /= T;
    }
    
    if(x <= k) {
        x = 1;
        return 1;
    }
    return 0;
}

const int LIM = 31700;
int main() {
    SieveLinear(LIM);
    int T, n, k, x;
    scanf("%d", &T);
    
    while(T--) {
        bool ok = 0;
        int gcd;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            
            if(ok) continue;
            
            //while(x%2==0) x/=2;
            
            if(x < LIM)    
                ok |= checkOK1(x, k);
            else
                ok |= checkOK2(x, k);
            
            if(i == 0) gcd = x;
            else gcd = __gcd(gcd, x);
        }
        
        printf("%s\n", (gcd==1?"YES":"NO"));
    }
    return 0;
}
