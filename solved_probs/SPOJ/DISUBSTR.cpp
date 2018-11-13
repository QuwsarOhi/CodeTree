// SPOJ
// DISUBSTR

#include <bits/stdc++.h>
using namespace std;
#define MAX                 2100
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
 
const ll p = 31;
const ll mod1 = 1e9+9, mod2 = 1e9+7;
vll Power;
unordered_set<ll>SET;
char str[1111];
 
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
}}
 
int main() {
    int t;
    sf("%d", &t);
    PowerGen(1111);
    
    while(t--) {
        sf("%s", str);
        int len = strlen(str);
        
        // HAZARD!
        for(int i = 0; i < len; ++i) {
            pll Hash = {0, 0};
            for(int j = i, l = 0; j < len; ++j, ++l) {
                Hash.fi = (Hash.fi + (str[j] - 'a' + 1) * Power[l].fi)%mod1;
                Hash.se = (Hash.se + (str[j] - 'a' + 1) * Power[l].se)%mod2;
                SET.insert(Hash.fi*1e9+Hash.se);
            }
        }
        
        pf("%d\n", SIZE(SET));
        SET.clear();
    }
    return 0;
}
