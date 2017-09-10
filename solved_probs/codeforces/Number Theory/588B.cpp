// Codeforces
// B. Duff in Love
// http://codeforces.com/problemset/problem/588/B

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define ull unsigned long long
#define ll long long
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define msi map<string, int>
#define mii map<int, int>
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pair<int, int> >
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);


bool ok(ll n) {
	int lim = sqrt(n);
	for(int i = 2; i <= lim; ++i) {
		int cnt = 0;
		while(n % i == 0) {
			n /= i;
			++cnt;
		}
		if(cnt > 1)
			return 0;
	}
	return 1;
}


int main() {
	ll n, ans = 1;
	sf("%lld", &n);
	
	int lim = sqrt(n);
	
	if(ok(n)) {
		pf("%lld\n", n);
		return 0;
	}
	
	for(ll i = 2; i <= lim; ++i) {
		if(n%i == 0) {
			ll t = n/i;
			if(ok(i))
				ans = max(ans, i);
			if(i != t && ok(t))
				ans = max(t, ans);
		}
	}
	
	pf("%lld\n", ans);
	
	return 0;
}
