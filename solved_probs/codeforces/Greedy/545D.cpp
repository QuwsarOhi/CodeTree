// Codeforces
// D. Queue
// http://codeforces.com/problemset/problem/545/D

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
	int n, v[100100];
	
	sf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		sf("%d", &v[i]);
	}
	
	sort(v, v+n);
	
	int t = 0, cnt = 0;
	
	for(int i = 0; i < n; ++i) {
		if(t <= v[i]) {
			t += v[i];
			++cnt;
		}
	}
	
	pf("%d\n", cnt);
	return 0;
}
