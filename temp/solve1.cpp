#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define node vector<bitset<50>>
using namespace std;
typedef long long ll;

bitset<1000009>H;

int main() {
	ll n, m, k, u, v, h;
	scanf("%lld%lld%lld", &n, &m, &k);

	for(int i = 0; i < m; ++i) {
		scanf("%lld", &h);
		H[h] = 1;
	}

	ll ans = 1;
	bool hole = H[ans];
	for(int i = 0; i < k; ++i) {
		scanf("%lld%lld", &u, &v);
		if(hole)
			continue;
		if(ans == u)
			ans = v;
		else if(ans == v)
			ans = u;
		if(H[ans])
			hole = 1;
		//cerr << ans << endl;
	}

	cout << ans << endl;
	return 0;
}