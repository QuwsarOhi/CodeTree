// UVa
// 10717 - Mint

#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
typedef long long ll;

ll LCM(ll a, ll b) {
	ll c = a*b;
	return c/__gcd(a, b);
}

ll v[100], u[100], mn[100], mx[100];

int main() {
	ll n, m;
	while(scanf("%lld%lld", &n, &m) == 2) {
		if(n == 0 and m == 0)
			break;

		for(int i = 0; i < n; ++i)
			scanf("%lld", &v[i]);
		for(int i = 0; i < m; ++i)
			scanf("%lld", &u[i]);

		memset(mn, 0, sizeof mn);
		for(int i = 0; i < 100; ++i)
			mx[i] = 1e14;

		for(int i = 0; i+3 < n; ++i) {
			for(int j = i+1; j+2 < n; ++j) {
				for(int k = j+1; k+1 < n; ++k) {
					for(int l = k+1; l < n; ++l) {
						ll lcm = LCM(v[i], LCM(v[j], LCM(v[k], v[l])));
						//cout << i << " " << j << " " << k << " " << l << " -> " << lcm << endl;

						for(int p = 0; p < m; ++p) {
							ll tmn = (u[p]/lcm)*lcm;
							ll tmx = tmn;
							if(tmx < u[p])
								tmx += lcm;
							if(mn[p] < tmn)
								mn[p] = tmn;
							if(mx[p] > tmx)
								mx[p] = tmx;
							//printf("%lld %lld\n", mn, mx);
						}
					}
				}
			}
		}

		for(int i = 0; i < m; ++i)
			printf("%lld %lld\n", mn[i], mx[i]);
	}

	return 0;
}