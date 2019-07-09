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

	int n = 6;
	cout << n << endl;

	for(int i= 0; i < n; ++i) {
		cout << scale(rand(), 1, 100) << endl;
	}

	return 0;
}