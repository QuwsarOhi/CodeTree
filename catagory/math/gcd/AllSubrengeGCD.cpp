// Codeforces
// http://codeforces.com/contest/475/problem/D
// D. CGCDSSQ

// Count number of occurance of a GCD value in all sub ranges

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define SIZE(a) ((int)a.size())
#define Equal(a, b) (abs(a-b) < EPS)
#define Greater(a, b) (a >= (b+EPS))
#define GreaterEqual(a, b) (a > (b-EPS)) 
#define fr(i, a, b) for(register int i = (a); i < (int)(b); i++)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari) cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;

ll v[100100];

int main() {
    ll n, m, x;
    sf("%lld", &n);
    for(int i = 0; i < n; ++i)
        sf("%lld", &v[i]);
    
    map<ll, ll> NewGcd, PastGcd, GcdCount;
    
    // Calculate all GCD in any sub-range
    // Gcd may reduce in log2(n) (on average, can stay constant also), where n is the first value
    
    for(int i = 0; i < n; ++i) {
        map<ll, ll>::iterator it;
        for(it = PastGcd.begin(); it != PastGcd.end(); ++it)        // For all past Unique gcd's calculate the new gcd with the new value v[i]
            NewGcd[__gcd(v[i], it->first)] += it->second;           // as there may be same past gcd more than once, so incrementing with that count
        NewGcd[v[i]]++;                                             // also add a new subrange from i'th index, so add new count here
        
        for(it = NewGcd.begin(); it != NewGcd.end(); ++it)          // for every newGcd's found here, add it to count
            GcdCount[it->first]+=it->second;
        
        PastGcd = NewGcd;                                           // Now NewGcd is the past Gcd
        NewGcd.clear();                                             // Empty NewGcd for further use
    }
    
    sf("%lld", &m);
    
    while(m--) {
        sf("%lld", &x);
        pf("%lld\n", GcdCount[x]);
    }
    
    return 0;
}
