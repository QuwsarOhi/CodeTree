// Codeforces
// C. Number of Ways
// http://codeforces.com/problemset/problem/466/C
// Dynamic Programming, Math

// The array can only be divided into 3 parts if sum % 3 == 0 and each part will be of value sum/3
// so, the cumulative frequency of the first half (last point) is sum/3, the second half (last point) is 2 * (sum/3) and third half is sum 

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


int n, v[500100], cnt1[500100] = {0}, cnt2[500100] = {0};
ll sum = 0, sum2 = 0, s[500010];

int main() {	
	sf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		sf("%d", &v[i]);
		sum += v[i];
		s[i] = v[i];
		if(i != 0)
			s[i] += s[i-1];
	}
	
	if(sum % 3 != 0) {
		pf("0\n");
		return 0;
	}
	
	sum /= 3;
	sum2 = sum*2;
	ll tmp = 0;
	for(int i = n-1; i > 0; --i) {
		tmp += v[i];
		cnt1[i] = cnt1[i+1];
		cnt2[i] = cnt2[i+1];
		if(tmp == sum)
			++cnt1[i];
		if(s[i] == sum2)
			cnt2[i] = cnt1[i+1];
	}
	
	ll ans = 0;
	tmp = 0;
	for(int i = 0; i < n-2; ++i) {
		tmp += v[i];
		if(tmp == sum)
			ans += cnt2[i+1];
	}
	
	pf("%lld\n", ans);
	
	return 0;
}
	
	
