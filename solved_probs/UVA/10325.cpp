// UVa
// 10325 - The Lottery
// LCM + GCD + Inclusion-Exclusion

#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
typedef long long ll;

ll LCM(ll a, ll b) {
	ll c = a*b;
	return c/__gcd(a, b);
} 

ll v[100];

int main() {
	ll n, m;
	while(scanf("%lld%lld", &n, &m) == 2) {
		for(int i = 0; i < m; ++i)
			scanf("%lld", &v[i]);

		ll ans = 0;
		for(int i = 1; i < (1 << m); ++i) {
			int bits = 0;
			ll lcm = 1;
			for(int p = 0; p < m; ++p)
				if(i & (1 << p))
					lcm = LCM(lcm, v[p]), ++bits;

			int sign = (bits%2 == 0) ? -1:1;
			ans += sign*(n/lcm); 
		}

		cout << n-ans << endl;
	}

	return 0;
}