// Codeforces
// C. Drazil and Factorial
// http://codeforces.com/problemset/problem/515/C

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
	ll n, f[15] = {0}, p[15], x, d[4] = {7, 5, 3, 2};
	char s;
	string ans;
	
	p[0] = 1;
	for(int i = 1; i <= 10; ++i)
		p[i] = i*p[i-1];
	
	sf("%lld", &n);
	fr(i, 0, n) {
		sf(" %c", &s);
		x = p[s - '0'];
		if(x != 1)
			one = 0;
		for(int i = 0; i < 4; ++i) {
			while(x % d[i] == 0) {
				x /= d[i];
				++f[d[i]];
			}
		}
	}

	while(f[7] > 0) {
		ans += "7";
		f[7] -= 1, f[3] -= 2, f[5] -= 1, f[2] -= 4;
	} 
	
	while(f[5] > 0) {
		ans += "5";
		f[5] -= 1, f[3] -= 1, f[2] -= 3;
	}
	
	while(f[3] > 0) {
		ans += "3";
		f[3] -= 1, f[2] -= 1;
	}
	
	while(f[2] > 0) {
		ans += "2";
		f[2] -= 1;
	}
	
	pf("%s\n", ans.c_str());
	
	return 0;
}
