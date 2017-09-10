// Codeforces
// B. Wet Shark and Bishops
// http://codeforces.com/problemset/problem/621/B

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
	int n, x, y;
	sf("%d", &n);
	
	map<int, int>d1, d2;
	
	fr(i, 0, n) {
		sf("%d %d", &x, &y);
		d1[x-y]++;
		d2[x+y]++;
	}
	
	ll ans = 0;
	for(auto i : d1) {
		if(i.se > 1) {
			ans += (i.se * (i.se-1))/2;
		}
	}
	
	for(auto i : d2) {
		if(i.se > 1) {
			ans += (i.se * (i.se-1))/2;
		}
	}
	
	pf("%lld\n", ans);
	
	return 0;
}
		 
