// Codeforces
// B. Random Teams
// http://codeforces.com/problemset/problem/478/B

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


ll countPair(ll n) {
	return (n*(n-1))/2;
}

ll findMin(ll n, ll m) {
	ll x = n/m;			// Average members in each team
	ll y = n%m;			// Extra team members left (This members will be distributed in each team by 1)
	ll ans = countPair(x)*(m-y);		// Average team members friendship count
	ans += countPair(x+1)*y;			// The leftover team members friendship count
	return ans;
}

ll findMax(ll n, ll m) {
	return countPair(n-m+1);
}

int main() {
	ll n, m;
	sf("%lld%lld", &n, &m);
	pf("%lld %lld\n", findMin(n, m), findMax(n, m));
	return 0;
}
