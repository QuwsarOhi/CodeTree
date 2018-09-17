#include <bits/stdc++.h>
using namespace std;
#define MAX                 300000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
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
 
#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------
 
ull ans = 0;
vi l, r;

void recur(vi v) {
	ll cal = 0;
	cerr << "len " << SIZE(v) << endl;


	if(SIZE(v) == 1) {
		if(SIZE(v) == SIZE(r))
			cal = abs(v[0]-r[0]);
		else
			cal = 10-v[0]-(v[0] == 0);
	}
	else if(SIZE(v) == 2) {
		if(SIZE(v) == SIZE(r))
			cal = min(r[0], r[1]);
		else
			cal = 9;

	}
	else {
		cal = 1;
		for(int i = 1; i < SIZE(v)-1; ++i) {
			if(SIZE(v) == SIZE(r))
				cal *= abs(v[i] - r[i]);
			else
				cal *= 9;
		}
		if(SIZE(v) == SIZE(r))
			cal *= min(r.front(), r.back());
		else
			cal *= 9;
	}

	ans += cal;
	if(SIZE(v)+1 > SIZE(r)) return;

	int len = SIZE(v)+1;
	v.clear();
	for(int i = 0; i < len; ++i) v.pb(0);
	recur(v);
}

int main() {
	ull x, y;
	cin >> x >> y;

	while(x) {
		l.pb(x%10);
		x/=10;
	}

	while(y) {
		r.pb(y%10);
		y/=10;
	}
	
	cerr << "DONE" <<endl;
	if(l.empty()) l.pb(0);

	recur(l);
	cout << ans << endl;
	return 0;
}