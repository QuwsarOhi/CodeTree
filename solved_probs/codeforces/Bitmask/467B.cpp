// Codeforces
// B. Fedor and New Game
// http://codeforces.com/problemset/problem/467/B
// Bitwise

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9;
#define INF 1e9
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define msi map<string, int>
#define mii map<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
	int n, m, k, v[1100], cnt = 0;
	
	sf("%d%d%d", &n, &m, &k);
	
	fr(i, 0, m+1) {
		sf("%d", &v[i]);
	}
	
	fr(i, 0, m) {
		if(__builtin_popcount (v[m] ^ v[i]) <= k)
			++cnt;
	}
	
	pf("%d\n", cnt);
	
	return 0;
}
	
