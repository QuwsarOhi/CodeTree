#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-2
#define INF                 0x3f3f3f3f
#define MOD					1000000007
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

ll SUM(ll a, ll d, ll n) {
	return ((2*a + (n-1)*d)*n)/2;
}

ll n, k;

ll BSd(ll a) {
	ll lo = 1, hi = n;
	while(lo <= hi) {
		ll mid = (lo+hi)/2;
		ll ss = SUM(a, mid, k);

		cerr << a << " " << mid << " " << ss << endl;

		if(ss == n)
			return mid;
		else if(ss < n)
			lo = mid+1;
		else
			hi = mid-1;
	}
	return 0;
}

pll BSval(ll lo, ll hi) {
	ll ans = -1, d = -1;
	while(lo <= hi) {
		ll mid = (lo+hi)/2;
		ll dd = BSd(mid);
		//cerr << mid << " " << dd << endl;

		if(dd) {
			ans = mid;
			d = dd;
			lo = mid+1;
		}
		else
			hi = mid-1;
	}
	return {ans, d};
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		cin >> n >> k;

		if(k == 1) {
			cout << (n*n - n)%MOD << endl;
			continue;
		}

		pll x = BSval(1, n);
		//cerr << x.first << " " << x.second << endl;
		
		if(x.first == 1) {
			cout << "0\n";
			continue;
		}
		if(x.first <= 0) {
			cout << "-1\n";
			continue;
		}

		ll ans = 1;
		for(int i = 0; i < k; ++i) {
			ans *= (x.first*x.first - x.first);
			ans %= MOD;
			x.first += x.second;
		}

		cout << ans << endl;
	}
	return 0;
}


/*
9
4 2
6 2
5 1
5 2
5 3
5 4
5 5
8 3
12 2
14 4
*/

//2, 3, 4