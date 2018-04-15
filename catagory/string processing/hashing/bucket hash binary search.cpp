// HackerEarth
// SUBSTRINGS COUNT
// Hashing (Bucket) + Binary Search

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
#define sf(XX)              scanf("%d", &XX)
#define sfll(XX)            scanf("%lld", &XX)
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

const ll mod1 = 1e9+9, mod2 = 1e9+7, p = 31;
vll Power;
set<pll>Set;
map<pll, vi>Bucket;
int LIM = 30;

void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
    }
}


pll doubleHashPatt(char s[], int len) {
    ll hashVal1 = 0, hashVal2 = 0;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[LIM-len+i+1].fi)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[LIM-len+i+1].se)%mod2;
    }
    return {hashVal1, hashVal2};
}

vll doubleHash(char s[], int len) {
    ll hashVal1 = 0, hashVal2 = 0;
    vector<pair<ll, ll> >v;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].first)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].second)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
    
    return v;
}


int main() {
    int n, l, r, q;
    char str[50];
    
    sf(n);
    PowerGen(50);
    
    FOR(i, 0, n) {
        scanf("%s", str);
        int len = strlen(str);
        
        vll Hash = doubleHash(str, len);
        Set.clear();
        
        for(int l = 1; l <= len; ++l)
            for(int j = l-1; j < len; ++j) {
                pll SubHash;
                
                SubHash.fi = (Hash[j].fi - (j-l < 0 ? 0:Hash[j-l].fi) + mod1)%mod1;
                SubHash.se = (Hash[j].se - (j-l < 0 ? 0:Hash[j-l].se) + mod2)%mod2;
                
                SubHash.fi = (SubHash.fi * Power[LIM-j].fi)%mod1;
                SubHash.se = (SubHash.se * Power[LIM-j].se)%mod2;
                
                if(!Set.count(SubHash)) {
                    Bucket[SubHash].pb(i);
                    Set.insert(SubHash);
                }
            }
    }
    
    
    sf(q);
    while(q--) {
        sf(l), sf(r), scanf("%s", str);
        --l, --r;
        
        pll Hash = doubleHashPatt(str, strlen(str));
        int Ans = upper_bound(Bucket[Hash].begin(), Bucket[Hash].end(), r) - lower_bound(Bucket[Hash].begin(), Bucket[Hash].end(), l);
        pf("%d\n", Ans);
    }
    
    return 0;
}
