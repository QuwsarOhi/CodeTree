#include <bits/stdc++.h>
using namespace std;
#define MAX                 6
#define EPS                 1e-2
#define INF                 0x3f3f3f3f
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

double Pow(ll val, ll p) {
	if(p == 0) return 1;
	if(p == 1) return val;
	if(p & 1)  return val * Pow(val, p-1);
	double tmp = Pow(val, p/2);
	return tmp*tmp;
}

double calZ(ll x, ll k, ll b, ll Time) {
	double z = Pow(k, Time)*(double)x;
	//cerr << "First " << z << endl;
	if(Time-1 >= 0) {
		if(k > 1)
			z += b * ((Pow(k, Time) - 1) / (k-1));
		else if(k == 1)
			z += b * Time;
	}
	return z;
}

int main() {
	ll k, b, n, t;
	cin >> k >> b >> n >> t;

	double z = calZ(1, k, b, n);
	cerr << "Z " << z << endl;
	ll lo = 0, hi = 1000010, ans = 0, mid;

	while(lo <= hi) {
		mid = (lo+hi)/2;
		double tmp = calZ(t, k, b, mid);
		cerr << "T " << mid << " " << tmp << endl;
		if(isinf(tmp))
			hi = mid-1;
		else if(tmp >= z) {
			cerr << "Less\n" << endl;
			ans = mid, hi = mid-1;
		}
		else
			lo = mid+1;
	}

	//for(int i = 0; i <= hi; ++i)
	//	cerr << "Time " << i << " " << calZ(t, k, b, i) << endl;

	cout << ans << endl;
	return 0;
}