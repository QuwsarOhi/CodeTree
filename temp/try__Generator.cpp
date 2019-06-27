#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int scale(int n, int x, int y) {
	if(n < x)
		n = x;
	if(n > y) {
		n %= y;
		n+1;
	}
	return max(n, x);
}

int main() {
	ll seed;
	cout << 1 << endl;
	cin >> seed;
	srand(seed);
	ll lim = 1000000000;
	ll k = scale(rand(), 1, lim);
	ll n = scale(rand(), 1, max(k/3, 1LL));
	
	cout << n << " " << k << " ";

	//for(int i= 0; i < n; ++i) {
		ll a = scale(rand(), 2, max(n/4, 1LL));
		ll b = scale(rand(), 1, a);
		cout << a << " " << b << endl;
	//}

	return 0;
}