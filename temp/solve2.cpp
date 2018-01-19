#include <bits/stdc++.h>
using namespace std;
#define MAX                 50
#define EPS                 1e-9
#define INF                 1000000000
#define MOD                 1000003
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

bitset<1100000>isPrime;
vi primes, G[100010], W[100010];
int S[100010];

void sieveGen(unsigned long long N) {
    isPrime.set();
    //0 and 1 are not prime
	isPrime[0] = isPrime[1] = 0;
	for(unsigned long long i = 2; i <= N; i++) {
		if(isPrime[i]) {
			for(unsigned long long j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
			primes.push_back(i);
		}
	}
}


int findPrime(ll sum) {
    for(int p = 1; p <= 1e5; ++p)
        if(isPrime[sum+p])
            return p;
    return -1;
}

int main() {
    sieveGen(1099990);
    //cout << "DONE\n";
    int n, m, w;
    cin >> n >> m;
    
    for(int i = 1; i < n; ++i) {
        if(i == n-1)
            w = findPrime(n-2);
        else
            w = 1;
        cout << i << " " << i+1 << " " << w << endl;
    }
    
    m -= (n-1);
    //cout << m << endl;
    
    for(int i = 1; i <= n && m > 0; ++i)
        for(int j = i+2; j <= n && m > 0; ++j, --m)
            cout << i << " " << j << " " << INF << endl;
    
    return 0;
}
