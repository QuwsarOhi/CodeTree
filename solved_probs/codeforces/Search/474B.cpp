// Codeforces
// B. Worms
// http://codeforces.com/problemset/problem/474/B
// Binary Search

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
	int n, m, x;
	vi v;
	sf("%d", &n);
	
	fr(i, 0, n) {
		sf("%d", &x);
		v.pb(x);
		if(i != 0)
			v[i] += v[i-1];
	}
	
	sf("%d", &m);
	
	fr(i, 0, m) {
		sf("%d", &x);
		auto p = lower_bound(v.begin(), v.end(), x);
		pf("%d\n", (int)(p-v.begin())+1);
	}
	
	return 0;
}
		
