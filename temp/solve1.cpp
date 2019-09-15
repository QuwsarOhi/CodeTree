#include <bits/stdc++.h>
#define MAX 1000010
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long int ll;


int main() {
	ll a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;

	ll mn = n - a1*(k1-1) - a2*(k2-1);
	if(mn <= 0)
		mn = 0;
	else
		mn = min(a1+a2, mn);

	ll mx = 0;

	if(k1 < k2) {
		while(n - k1 >= 0 and a1 > 0)
			n -= k1, --a1, ++mx;
		while(n - k2 >= 0 and a2 > 0)
			n -= k2, --a2, ++mx;
	}
	else {
		while(n - k2 >= 0 and a2 > 0)
			n -= k2, --a2, ++mx;
		while(n - k1 >= 0 and a1 > 0)
			n -= k1, --a1, ++mx;
	}

	cout << mn << " " << mx << endl;
	return 0;
}