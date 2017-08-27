// Codeforces
// A. Even Odds
// http://codeforces.com/problemset/problem/318/A

#include <bits/stdc++.h>
using namespace std;


int main() {
	long long n, k;
	cin >> n >> k;
	n = ceil(n/2.0);
	if(k <= n) {
		cout <<  1+(k-1)*2 << endl;
	}
	else {
		//printf("%lld\n", k-n-2);
		cout << 2+(k-n-1)*2 << endl;
	}
	return 0;
}
