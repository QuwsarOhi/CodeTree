// Codeforces
// A. Laptops
// http://codeforces.com/problemset/problem/456/A
// Greedy, Sorting
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
#define fr(i, a, b) for(register int i = a; i < (int)b; i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;

int main() {
	int n, p, q;
	vii v;
	sf("%d", &n);
	
	fr(i, 0, n) {
		sf("%d %d", &p, &q);
		v.pb({p, q});
	}
	
	sort(v.begin(), v.end());
	
	int past_q = v[0].se;
	fr(i, 1, v.size()) {
		if(v[i].se < past_q) {
			pf("Happy Alex\n");
			return 0;
		}
		past_q = v[i].se;
	}
	
	pf("Poor Alex\n");
	
	return 0;
}
