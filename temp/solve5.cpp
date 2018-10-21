#include <bits/stdc++.h>
using namespace std;
#define MAX                 6
#define EPS                 1e-7
#define INF                 0x3f3f3f3f
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
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

double slope(pii x, pii y) {
    int xxx = x.xx-y.xx;
    int yyy = x.yy-y.yy;
    if(xxx == 0 or yyy == 0)
        return 0;
    return yyy/(double)xxx;
}



int main() {
    int n;
    cin >> n;
    vii v(20);

    for(int i = 0; i < n; ++i)
        cin >> v[i].xx >> v[i].yy;

    double s = slope(v[0], v[1]);
    bool ok = s == 0;
    for(int i = 2; i < n; ++i)
        if(slope(v[0], v[i]) != 0)
            ok = 0;

    //cerr << s << endl;
    cout << (ok?"YES":"NO") << endl;
    return 0;
}