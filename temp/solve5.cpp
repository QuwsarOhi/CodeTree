#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
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



vector<ll>u_list, u_set;
vl ans;
map<pii, bool>Map;

//u_list[x] contains the size of a set x
//u_set[x] contains the root of x

ll unionRoot(ll n)
{
    if(u_set[n] == n)
        return n;
    else
        return u_set[n] = unionRoot(u_set[n]);
}

ll makeUnion(ll a, ll b)
{
    ll x = unionRoot(a);
    ll y = unionRoot(b);

    if(x == y)
        return x;
    else if(u_list[x] > u_list[y]) {
        u_set[y] = x;
        u_list[x] += u_list[y];
        return x;
    }
    else {
        u_set[x] = y;
        u_list[y] += u_list[x];
        return y;
    }
}

void unionInit(ll len)
{
    u_list.resize(len+5, 1);
    u_set.resize(len+5);

    for(int i = 0; i <= len; i++)
        u_set[i] = i;
}

bool isSameSet(ll a, ll b)
{
    if(unionRoot(a) == unionRoot(b))
        return 1;
    return 0;
}

int main() {
    ll V, E, u, v;
    
    cin >> V >> E;
    
    fr(i, 0, E) {
        cin >> u >> v;
        Map[{min(u, v), max(u, v)}] = 1;
    }
    
    unionInit(V+100);
    
    fr(u, 1, V+1) {
        fr(v, u+1, V+1) {
            if(Map.find({u, v}) == Map.end())
                makeUnion(u, v);
        }
    }
    
    fr(u, 1, V+1)
        if(unionRoot(u) == u)
            ans.pb(u_list[u]);
    
    sort(All(ans));    
    
    cout << SIZE(ans) << "\n";
    bool first = 1;
    for(auto c : ans) {
        if(!first) cout << " ";
        first = 0;
        cout << c;
    }
    
    cout << "\n";
    return 0;
}
    
    
