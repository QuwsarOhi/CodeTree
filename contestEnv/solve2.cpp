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
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
}}

vll doubleHash(char *s, int len) {      // Returns Double Hash vector for a full string
    ll hashVal1 = 0, hashVal2 = 0;
    vector<pll>v;
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].fi)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].se)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
    return v;
}

pll SubHash(vll &Hash, ll l, ll r, ll LIM = 1500) {    // Produce SubString Hash
    pll H;
    H.fi = (Hash[r].fi - (l-1 >= 0 ? Hash[l-1].fi:0) + mod1)%mod1;
    H.se = (Hash[r].se - (l-1 >= 0 ? Hash[l-1].se:0) + mod2)%mod2;
    
    H.fi = (H.fi * Power[LIM-l].fi)%mod1;
    H.se = (H.se * Power[LIM-l].se)%mod2;
    return H;
}

char s[3000];
vll H1, H2;
set<int> END;
ll START[3000];
string ss;

void checkPalin(int L, int R, int k, int len) {
    for(int l = L; l <= R; ++l) {
        for(int r = l+k-1; r <= R; ++r) {
            int rl = len-1-l;
            int rr = len-1-r;
            swap(rl, rr);
            
            pll hash1 = SubHash(H1, l, r);
            pll hash2 = SubHash(H2, rl, rr);
            
            if(hash1 == hash2) {
                END.insert(r);
                START[r]++;
                cout << ss.substr(l, r-l+1) << endl;
                //ENDpoints.insert(r);
            }
        }
    }
}

bool cmp(ll l, ll r) {
    return l >= r;
}

int main() {
    PowerGen(2000);
    
    int t, K;
    ll cnt;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d %s", &K, s);
        int len = strlen(s);
        cnt = 0;
        
        ss = string(s);
        
        H1.clear();
        H1 = doubleHash(s, len);
        

        for(int i = 0, j = len-1; i < j; ++i, --j)
            swap(s[i], s[j]);
        
        H2.clear();
        H2 = doubleHash(s, len);
        memset(START, 0, sizeof START);
        
        checkPalin(0, len-1, K, len);
        
        for(int i = 0; i < len; ++i) {
            int x;
            if(END.empty())
                x = len-1;
            else
                x = *END.begin();
            
            int N = x-i;
            cerr << "FROM " << i << " " << x << endl;
            if(N >= 0) {
                cnt += (N*N+N)/2;
                cnt += (N==0);
            }
            START[x]--;
            if(START[x] == 0)
                END.erase(END.begin());
        }
            
        
        
        printf("%lld\n", cnt);
    }
    return 0;
}
                

