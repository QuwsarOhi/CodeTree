// Codeforces
// C. A and B and Team Training
// http://codeforces.com/problemset/problem/519/C

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

ll cnt = 0;

void recur(int mn, int mx) {
	if(mn >= 1 && mx >= 2) {
		++cnt;
		recur(min(mn-1, mx-2), max(mn-1, mx-2));
	}
	return;
}

int main() {
	int n, m;
	sf("%d%d", &n, &m);
	recur(min(n, m), max(n, m));
	pf("%lld\n", cnt);
	return 0;
}
