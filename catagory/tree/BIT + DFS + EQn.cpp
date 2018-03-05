// Codeforces
// http://codeforces.com/contest/396/problem/C
// C. On Changing Tree


#include <bits/stdc++.h>
using namespace std;
#define MAX                 1100000
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
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

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

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------


struct BIT{
    ll Tree[MAX], MaxVal;
    
    void update(int idx, ll val) {
        val = (val+MOD)%MOD;
        while(idx <= MaxVal) {
            Tree[idx] = (Tree[idx] + val + MOD)%MOD;
            idx += (idx & -idx);
        }
    }
    
    ll read(int idx) {
        ll sum = 0;
        while(idx > 0) {
            sum = (sum + Tree[idx] + MOD)%MOD;
            idx -= (idx & -idx);
        }
        return (sum+MOD)%MOD;
    }
    
    void update(int l, int r, ll val) {
        update(l, val);
        update(r+1, -val);
    }
};

BIT t1, t2;
vi G[MAX];
int level[MAX], start[MAX], finish[MAX], timer;

void dfs(int u, int lvl) {
    level[u] = lvl;
    start[u] = ++timer;
    
    for(auto v : G[u])
        dfs(v, lvl+1);
    
    finish[u] = timer;
}

int main() {
    ll n, u, v, x, k, q, t;
    
    scanf("%lld", &n);
    for(int v = 2; v <= n; ++v) {
        scanf("%lld", &u);
        G[u].push_back(v);
    }
    
    dfs(1, 1);
    t1.MaxVal = t2.MaxVal = n;
    
    scanf("%lld", &q);
    
    //for(int i = 1; i <= n; ++i)
    //    printf("DFS %d %d %d\n", start[i], finish[i], level[i]);
    
    while(q--) {
        scanf("%lld", &t);
        
        if(t == 1) {
            scanf("%lld%lld%lld", &v, &x, &k);
            t1.update(start[v], finish[v], (x + (k%MOD*level[v])%MOD)%MOD);
            t2.update(start[v], finish[v], k%MOD);
        }
        else {
            scanf("%lld", &v);
            printf("%lld\n", (t1.read(start[v])%MOD - t2.read(start[v])%MOD * level[v]%MOD + MOD)%MOD);
        }
    }
    
    return 0;
}
    
