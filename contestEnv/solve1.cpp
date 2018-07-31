#include <bits/stdc++.h>
using namespace std;
#define MAX                 1000100
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

/*
int pd[MAX];                        // Contains minimum prime factor/divisor, for primes pd[x] = x
vector<int>primes;                  // Contains prime numbers
void SieveLinear(int N) {
    for(int i = 2; i <= N; ++i) {
        if(pd[i] == 0) pd[i] = i, primes.push_back(i);                  // if pd[i] == 0, then i is prime
        for(int j=0; j < (int)primes.size() && primes[j] <= pd[i] && i*primes[j] <= N; ++j)
            pd[i*primes[j]] = primes[j];
}}*/

int pd[MAX];                        // Contains minimum prime factor/divisor, for primes pd[x] = x
vector<int>primes;                  // Contains prime numbers
vector<int>PF[MAX];
void SieveLinearRangePF(int N, ll low, ll hi) {             // also returns unique prime factors in range [low, hi]
    for(int i = 2; i <= N; ++i) {
        if(pd[i] == 0) {
            pd[i] = i, primes.push_back(i);                  // if pd[i] == 0, then i is prime
            for(ll x = (low-1)-(low-1)%i+i; x <= hi; x += i)        // inserting all prime factors [prime will be inserted only once]
                PF[x-low].push_back(i);                             // just to be sure, used low-1, instead of low
        }
        for(int j=0; j < (int)primes.size() && primes[j] <= pd[i] && i*primes[j] <= N; ++j)
            pd[i*primes[j]] = primes[j];
}}

ll low, hi;

ll RET(ll n) {
    ll T = n, mul = 1, tmp;
    priority_queue<ll>pq;
    
    //for(auto it : PF[n-low]) cout << it << " ";
    //cout << endl;
    
    for(auto it : PF[n-low]) {
        ll cnt = 0;
        //cout << it << " : ";
        if(T == 1) break;
        while(T%it == 0) {
            ++cnt;
            T/=it;
        }
        pq.push(cnt+1);
        mul *= cnt+1;
        //cout << cnt+1 << endl;
    }
    
    if(T != 1) {
        mul *= 2;
        pq.push(2);
    }
    
    ll ret = 0;
    while(not pq.empty() and pq.top() != 1) {
        ret += mul;
        tmp = pq.top();
        pq.pop();
        mul /= tmp;
        tmp--;
        mul *= tmp;
        if(tmp>1)
            pq.push(tmp);
    }
    return ret;
}

int main() {
    cin >> low >> hi;
    //low = 10, hi = 20;
    SieveLinearRangePF(1000010, low, hi);
    
    ll ans = 0;
    for(ll i = low; i <= hi; ++i)
        ans += RET(i);
    
    cout << ans << endl;
    //cout << RET(12) << endl;    
    return 0;
}
