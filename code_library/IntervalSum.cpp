// Codeforces
// http://codeforces.com/contest/915/problem/E

// Interval Sum
// Complexity: query*log(query)

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e8
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


int main() {
    ll lim, q, l, r, k, sum = 0;
    set<pll>Set;
    
    sf("%lld %lld", &lim, &q);
    
    while(q--) {
        sf("%lld %lld %lld", &l, &r, &k);         // k is the set or remove segment command
        
        //first remove the overlapping segments;
        // set contains : r', l'
        // Search boundary : l, r
        // because we need to find l' and r' such that l <= r'
        // inserting r' as first pair element because lower_bound will return first l <= r'
        // also checking l' <= r
        
        // 4 Cases:
        // l, r : search boundary
        // l', r': boundaries exist in set
        
        // l'----l-----r----r'  or  l----l'----r'----r
        // l'----l-----r'---r   or  l----l'----r-----r'
        
        auto it = Set.lower_bound(make_pair(l, 0LL));       // Always use Set.lower_bound(), lower_bound() function works slow in set
        
        while(it != Set.end() && it->second <= r) {
            ll segL = it->second;
            ll segR = it->first;
            
            it = Set.erase(it);                    // Erase and point to the next segment
            
            ll L = max(segL, l);
            ll R = min(segR, r);
            
            sum -= (R-L+1);
            
            if(segL < l)                          // l'----l-----r----r'  or  l'----l-----r'---r
                Set.insert({l-1, segL});
            if(segR > r)                          // l'----l-----r----r'  or  l----l'----r-----r'
                Set.insert({segR, r+1});
        }
        
        if(k == 1) {                // Insertion
            sum += (r-l+1);
            Set.insert({r, l});
        }
        
        pf("%lld\n", lim - sum);
    }
    
    return 0;
}
