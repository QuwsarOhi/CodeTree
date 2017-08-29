// Codeforces
// A. Kirill And The Game
// http://codeforces.com/contest/842/problem/A
// Math

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


int main() {
	ll l, r, x, y, k;
	sf("%lld%lld%lld%lld%lld", &l, &r, &x, &y, &k);
	
	for(ll i = x; i <= y; ++i) {
		ll t = k*i;
		if(t >= l && t <= r) {
			printf("YES\n");
			return 0;
		}
	}
	
	printf("NO\n");
	return 0;
}
