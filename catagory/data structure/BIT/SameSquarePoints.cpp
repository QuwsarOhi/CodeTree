// Codeforces
// E. The Untended Antiquity
// http://codeforces.com/contest/869/problem/E

// check if two points are in same square where the sqaures are Non Overlapping Square


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
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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

ull tree[2510][2510];
int xMax = 2505, yMax = 2505;

// Updates from min point to MAX LIMIT
void update(int x, int y, ll val) {
	int y1;
	while(x <= xMax) {
		y1 =  y;
		while(y1 <= yMax) {
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

// Reads from (0, 0) to (x, y)
ll read(int x, int y) {
	ll sum = 0;
	int y1;
	while(x > 0) {
		y1 = y;
		while(y1 > 0) {
			sum += tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return sum;
}

ll readSingle(int x, int y) {
    return read(x, y) + read(x-1, y-1) - read(x-1, y) - read(x, y-1);
}

void updateSquare(pii p1, pii p2, ll val) {     // p1 : lower left point, p2 : upper right point
    update(p1.first, p1.second, val);
    update(p1.first, p2.second+1, -val);
    update(p2.first+1, p1.second, -val);
    update(p2.first+1, p2.second+1, val);
}

// Not Checked!
ull readSquare(pii p1, pii p2) {                // p1 : lower left point, p2 : upper right point
    ull ans = 0;
    ans += read(p2.first, p2.second);
    ans -= read(p1.first-1, p2.second);
    ans -= read(p2.first, p1.second-1);
    ans += read(p1.first-1, p1.second-1);
    return ans;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, m, q, r1, c1, r2, c2, t;
    map<pair<pii, pii>, ull> store;
    
    srand(20001206);                                    // Hash Seed
    memset(tree, 0, sizeof tree);
    
    sf("%d %d %d", &n, &m, &q);
    for(ll i = 0; i < q; ++i) {
        sf("%d %d %d %d %d", &t, &r1, &c1, &r2, &c2);
        if(t == 1) {
            ll val = (rand() << 10) | rand();           // Random Hash (<<10  and double rand() to be sure it's unique)
            store[mp(mp(r1, c1), mp(r2, c2))] = val;
            updateSquare(mp(r1, c1), mp(r2, c2), val);
        }
        else if(t == 2) {
            ull val = store[mp(mp(r1, c1), mp(r2, c2))];
            updateSquare(mp(r1, c1), mp(r2, c2), -val);
        }
        else {
            ll p1 = read(r1, c1);
            ll p2 = read(r2, c2); 
            p1 == p2 ? pf("Yes\n") : pf("No\n");
        }
    }
    
    return 0;
}
