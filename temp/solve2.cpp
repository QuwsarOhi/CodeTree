// NOT SUBMITTED!
// https://www.codechef.com/DEC17/problems/CHEFUNI

#include <bits/stdc++.h>
using namespace std;
#define MAX                 1e6
#define EPS                 1e-9
#define INF                 1e9+10
#define MOD                 1000000007
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

ll a, b, c;
ll CalA(ll x, ll y, ll z);
ll CalB(ll x, ll y, ll z, bool GoToC);
ll CalC(ll x, ll y, ll z);

ll CalA(ll x, ll y, ll z) {
    return (x+y+z)*a;
}

ll CalB(ll x, ll y, ll z, bool GoToC) {
    //cout << "CalB " << x << " " << y << " " << z << endl; 
    if(x == 0 && y == 0 && z == 0)
        return 0;
        
    ll x1 = x - min(x, y);      // x, y
    ll y1 = y - min(x, y);
    ll z1 = z;
    ll cst1 = min(x, y)*b;
    
    ll x2 = x;                 // y, z
    ll y2 = y - min(y, z);
    ll z2 = z - min(y, z);
    ll cst2 = min(y, z)*b;
    
    ll x3 = x - min(x, z);     // x, z
    ll y3 = y;
    ll z3 = z - min(x, z);
    ll cst3 = min(x, z)*b;
    
    ll v[10];
    
    for(int i = 0; i < 10; ++i)
        v[i] = INT_MAX;
    
    v[0] = cst1 + CalA(x1, y1, z1);
    v[1] = cst2 + CalA(x2, y2, z2);
    v[2] = cst3 + CalA(x3, y3, z3);
    
    if(GoToC) {
        v[3] = cst1 + CalC(x1, y1, z1);
        v[4] = cst2 + CalC(x2, y2, z2);
        v[5] = cst3 + CalC(x3, y3, z3);
    }
    
    if(cst1 != 0)
        v[7] = cst1 + CalB(x1, y1, z1, GoToC);
    if(cst2 != 0)
        v[8] = cst2 + CalB(x2, y2, z2, GoToC);
    if(cst3 != 0)
        v[9] = cst3 + CalB(x3, y3, z3, GoToC);
    
    //for(int i = 0; i < 10; ++i)
        //cout << v[i] << " ";
        
    //cout << endl;
    
    //cout << "B " << min_element(v, v+6)-v << endl;
    
    return *min_element(v, v+10);
}


ll CalC(ll x, ll y, ll z) {
    //cout << "CalC" << x << " " << y << " " << z << endl;
    if(x == 0 && y == 0 && z == 0)
        return 0;
    if(x == 0 || y == 0 || z == 0)
        return INT_MAX;
    
    ll t = min(x, min(y, z));
    x -= t, y -= t, z -= t;
    ll cst = t*c;
    
    return min(cst+CalB(x, y, z, 0), cst+CalA(x, y, z));
}


int main() {
    ll t, x, y, z;
    
    sf("%lld", &t);
    
    while(t--) {
        sf("%lld %lld %lld %lld %lld %lld", &x, &y, &z, &a, &b, &c);
        pf("%lld\n", min(CalA(x, y, z), min(CalB(x, y, z, 1), CalC(x, y, z))));
    }
    
    return 0;
}
