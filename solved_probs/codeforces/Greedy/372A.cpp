// Codeforces
// A. Counting Kangaroos is Fun
// http://codeforces.com/problemset/problem/372/A

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
	vi v;
	int n, x;
	
	sf("%d", &n);
	
	fr(i, 0, n) {
		sf("%d", &x);
		v.pb(x);
	}
	
	sort(v.begin(), v.end());
	int cnt = 0, lastPoint = n/2;
	for(int i = 0; i < n/2; ++i) {
		cnt+=2;
		while(lastPoint < n && v[i]*2 > v[lastPoint])
			lastPoint++;
		if(lastPoint < n && v[i]*2 <= v[lastPoint]) {
			--cnt;
			++lastPoint;
		}
	}
	if(n%2 != 0)
		++cnt;
	pf("%d\n", cnt);
	
	return 0;
}
