// UVa
// 11436 - Cubes - EXTREME!!!
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2431&mosmsg=Submission+received+with+ID+21815253

#include <bits/stdc++.h>
using namespace std;
#define MAX                 110
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

// N = x^3 - y^3
// N = x^3 - y^3 = (x-y)(x^2 + xy + y^2)
// N/i = (x^2 + xy + y^2)
// N%i must be 0
// i = x-y
// x = i + y

ll findRoot(ll a, ll b, ll c) {
    ll s = b*b - 4*a*c;
    if(s < 0) return 0;
    s = sqrt(s);
    ll x1 = -b + s;
    ll x2 = -b - s;
    x1 /= 2*a, x2 /= 2*a;
    if(x2 <= 0)
        return x1;
    return x2;
}

int main() {
    // fileRead("in");
    // fileWrite("out");
    ll n;
    while(sf("%llu", &n) and n) {
        for(ll i = pow(n, 1/3.0)+2; i >= 1; --i) {
            if(n%i != 0) continue;
            //cerr << "at " << i << endl;
            ll k = n/i;
            ll y = findRoot(3, 3*i, i*i-k);
            ll x = i+y;
            //cerr << "I " << i << " X " << x << " Y " << y << endl;
            if(x*x*x - y*y*y == n and x > 0 and y > 0) {
                pf("%llu %llu\n", x, y);
                goto pass;
            }
        }
        pf("No solution\n");
        pass:;
    }
    return 0;
}
