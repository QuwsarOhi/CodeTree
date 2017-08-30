// Codeforces
// B. Cormen — The Best Friend Of a Man
// http://codeforces.com/problemset/problem/732/B
// Greedy

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
	int n, k, cnt = 0, v[550];
	sf("%d%d", &n, &k);
	fr(i, 0, n) {
		sf("%d", &v[i]);
	}
	
	fr(i, 1, n) {
		int t = v[i-1] + v[i];
		if(t < k) {
			cnt += k-t;
			v[i] += k-t;
		}
	}
	
	pf("%d\n", cnt);
	
	fr(i, 0, n-1)
		pf("%d ", v[i]);
	
	pf("%d\n", v[n-1]);
	
	return 0;
}
	
