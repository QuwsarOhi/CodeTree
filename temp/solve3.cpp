#include <bits/stdc++.h>
using namespace std;
#define MAX                 11000
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
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

const ll mod1 = 1e9+9, mod2 = 1e9+7, p = 31, block = 110;
vector<vll > SubSeqHash;
vll Power;
int Ans[MAX], LIM = 25;

map<pll, int>Count;

struct query {
    int l, r, id;
    char str[15];
}q[MAX];

// Genarates Powers
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
    }
}

// Returns Double Hash vector for a full string
vector<pair<ll, ll> > doubleHash(char s[], int len) {
    ll hashVal1 = 0, hashVal2 = 0;
    vector<pair<ll, ll> >v;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].first)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].second)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
    
    return v;
}


pll doubleHashPatt(char s[], int len) {
    ll hashVal1 = 0, hashVal2 = 0;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[LIM-i].fi)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[LIM-i].se)%mod2;
    }
    return {hashVal1, hashVal2};
}

bool cmp(query &a, query &b) {
    int block_a = a.l/block, block_b = b.l/block;
    if(block_a == block_b)
        return a.r < b.r;
    return block_a < block_b;
}


void add(int x) {       // Add x'th value in range
    for(auto it : SubSeqHash[x])
        Count[it]++;
}


void remove(int x) {    // Remove x'th value from range
    for(auto it : SubSeqHash[x])
        Count[it]--;
}

int AnsGen(char s[]) {
    pll H = doubleHashPatt(s, strlen(s));
    
    cout << H.fi << " " << H.se << endl;
    if(Count.find(H) != Count.end())
        return Count[H];
    return 0;
}

int main() {
    int n, len, Q;
    sf(n);
    
    char str[50];
    PowerGen(30);
    
    FOR(i, 0, n) {
        scanf("%s", str);
        len = strlen(str);
        vll Hash = doubleHash(str, len);
        
        SubSeqHash.pb(vll());
        
        for(int l = 1; l <= len; ++l) {
            cout << "LEN " << l << endl;
            for(int j = l-1; j < len; ++j) {
                pll SubHash;
                
                SubHash.fi = (Hash[j].fi - (j-l < 0 ? 0:Hash[j-l].fi) + mod1)%mod1;
                SubHash.se = (Hash[j].se - (j-l < 0 ? 0:Hash[j-l].se) + mod2)%mod2;
                
                SubHash.fi = (SubHash.fi * Power[LIM-j].fi)%mod1;
                SubHash.se = (SubHash.se * Power[LIM-j].se)%mod2;
                SubSeqHash[i].pb(SubHash);
                cout << j << " " << j-l << " " << SubHash.fi << " " << SubHash.se << " " << LIM-j << endl;
            }
        }
        cout << "Processed " << i << endl;
    }
    
    cout << "DONE\n";
    sf(Q);
    
    FOR(i, 0, Q) {
        sf(q[i].l), sf(q[i].r);
        scanf("%s", q[i].str);
        q[i].l--, q[i].r--;
    }
    
    sort(q, q+Q, cmp);    
    int l = 0, r = -1;
    for(int i = 0; i < Q; ++i) {
        while(l > q[i].l)   add(--l);
        while(r < q[i].r)   add(++r);
        while(l < q[i].l)   remove(l++);
        while(r > q[i].r)   remove(r--);
        Ans[q[i].id] = AnsGen(q[i].str);                     // Add Constraints
    }
    
    FOR(i, 0, Q)
        pf("%d\n", Ans[i]);
    
    return 0;
}
