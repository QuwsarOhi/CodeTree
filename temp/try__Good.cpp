#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, a, b;

ll f(ll x) {
	ll kk = k;
	kk -= a*x;
	if(kk <= 0)
		return -1;
	if((n-x)*b >= kk)
		return 0;
	return n;
}

int main() {
	ll q;
	cin >> q;			

	while(q--) {
		cin >> k >> n >> a >> b;

		ll lo = 0, hi = n, ans = -1;

		while(lo <= hi) {
			ll mid = (lo+hi)/2;

			if(f(mid) >= n) {
				lo = mid+1;
				ans = max(ans, mid);
			}
			else
				hi = mid-1;
		}
		
		//ll tot = (step1+step0)/n;
		cout << ans << endl;
	}

	return 0;
}