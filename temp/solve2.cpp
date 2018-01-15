#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
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

ll tree[150][150][150];
int xMax = 150, yMax = 150, zMax = 150;

void update(int x, int y, int z, ll val) {
    int y1, z1;
    while(x <= xMax) {
        y1 = y;
        while(y1 <= yMax) {
            z1 = z;
            while(z1 <= zMax) {
                tree[x][y1][z1] += val;
                z1 += (z1 & -z1);
            }
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

ll read(int x, int y, int z) {
    ll sum = 0;
    int y1, z1;
    while(x > 0) {
        y1 = y;
        while(y1 > 0) {
            z1 = z;
            while(z1 > 0) {
                sum += tree[x][y1][z1];
                z1 -= (z1 & -z1);
            }
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return sum;
}


ll readRange(int x1, int y1, int z1, int x2, int y2, int z2) {
    --x1, --y1, --z1;
    return  read(x2, y2, z2) 
    - read(x1, y2, z2)
    - read(x2, y1, z2)
    - read(x2, y2, z1)
    + read(x1, y1, z2) 
    + read(x1, y2, z1) 
    + read(x2, y1, z1)
    - read(x1, y1, z1);
}


int main() {
    //fileRead("in");
    int t, x1, x2, y1, y2, z1, z2, n, q;
    ll w;
    sf("%d", &t);
    char str[50];
    stack<pair<pii, pair<int, ll> > >v;
    //memset(tree, 0, sizeof tree);
    while(t--) {
        sf("%d %d", &n, &q);

        while(q--) {
            sf(" %s", str);
            if(tolower(str[0]) == 'u') {
                sf("%d %d %d %lld", &x1, &y1, &z1, &w);
                ++x1, ++y1, ++z1;
                update(x1, y1, z1, w);
                v.push({{x1, y1}, {z1, w}});
            }
            else {
                sf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
                ++x1, ++y1, ++z1, ++x2, ++y2, ++z2;
                if(x1 > x2) {
                    swap(x1, x2);
                    swap(y1, y2);
                    swap(z1, z2);
                }
                pf("%lld\n", readRange(x1, y1, z1, x2, y2, z2));
            }
        }
        
        if(t != 0) {
            while(!v.empty()) {
                update(v.top().fi.fi, v.top().fi.se, v.top().se.fi, -v.top().se.se);
                v.pop();
            }
        }
    }
    return 0;
}
