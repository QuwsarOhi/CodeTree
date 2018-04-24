// TO-DO LIST
// http://codeforces.com/contest/964/problem/C

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
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define FOR(i, a, b)        for(register int i = (a); i < (int)(b); i++)
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

ll v[MAX], n, a, b, k;
char s[MAX];


long long powMod(long long N, long long P, long long M) {
	if(P==0)
		return 1;
	if(P%2==0) {
		long long ret = powMod(N, P/2, M)%M;
		return (ret * ret)%M;
	}
    return ((N%M) * (powMod(N, P-1, M)%M))%M;
}


unsigned long long Pow(unsigned long long N, unsigned long long P) {
	if(P == 0)
		return 1;
	if(P % 2 == 0) {
		unsigned long long ret = Pow(N, P/2);
		return ret*ret;
	}
    return N * Pow(N, P-1);
}


ll F(ll i, ll N) {
    return i + (N-1)*k;
}


ll BinarySearch(ll I) {
    ll low = 0, hi = n/k+1, ret = -1;
    
    while(low <= hi) {
        ll mid = (low+hi)/2;
        
        ll x = F(I, mid);
        
        if(x <= n) {
            low = mid+1;
            ret = max(mid, ret);
        }
        else
            hi = mid-1;
    }
    
    return ret;
}
    
    

int main() {
    sf(n), sf(a), sf(b), sf(k);
    
    //scanf("%s", s);
    
    FOR(i, 1, k+1)
        v[i] = BinarySearch(i);
    
    FOR(i, 1, k+1)
        cout << v[i] << endl;
    
    return 0;
}
