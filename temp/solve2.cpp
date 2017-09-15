// Codeforces
// A. Dima and Continuous Line
// http://codeforces.com/problemset/problem/358/A
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define Equal(a, b) (abs(a-b) < EPS)
#define Greater(a, b) (a >= (b+EPS))
#define GreaterEqual(a, b) (a > (b-EPS)) 
#define fr(i, a, b) for(register int i = (a); i < (int)(b); i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari) cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;


int main() {
	int n, x, y;
	sf("%d", &n);
	sf("%d", &x);
	vii v;
	fr(i, 0, n-1) {
		sf("%d", &y);
		v.pb({min(x, y), max(x, y)});
		x = y;
	}
	sort(v.begin(), v.end());
	
	//for(auto i : v)
		//pf("%d %d\n", i.fi, i.se);
	
	fr(i, 0, v.size()) {
		fr(j, i+1, v.size()) {
			if(v[i].se > v[j].fi && v[i].fi < v[j].fi && v[i].se < v[j].se) {
				//pf("%d %d\n", i, j);
				pf("yes\n");
				return 0;
			}
		}
	}
	
	pf("no\n");
	return 0;
} 
