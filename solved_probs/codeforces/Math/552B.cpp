// Codeforces
// B. Vanya and Books
// http://codeforces.com/problemset/problem/552/B

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
#define fr(i, a, b) for(register int i = a; i < b; ++i)
#define msi map<string, int>
#define mii map<int, int>
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pair<int, int> >
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;

int main() {
	ll x, ans = 9;
	
	sf("%lld", &x);
	
	if(x <= 9) {
		pf("%lld\n", x);
		return 0;
	}
	
	for(ll i = 10, len = 2; i <= x; i*=10, ++len) {
		ll nxt = i*10LL;
		ans += len * (min(x, nxt-1) - i + 1);
	}
	
	pf("%lld\n", ans);

	return 0;
}
