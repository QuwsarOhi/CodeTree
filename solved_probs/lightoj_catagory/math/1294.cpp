// LightOJ
// 1294 - Positive Negative Sign
// Basic Math

// Look at fist example:

// -1 -2 -3 +4 +5 +6 -7 -8 -9 +10 +11 +12
//  |     |  |     |  |     |   |       |
//  -------  -------  -------   ---------
//     -6      +15      -24        +33 
//      |--------|        |----------|
//		     +9                +9
// +9 is (n/(2*m)) times!

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

inline ll sum(ll a, ll n, ll d) {
	return (n*(2*a + (n-1)*d))/2;
}

int main() {
	int t, n, m;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &m);
		ll a = sum(1, m, 1);
		ll b = sum(m+1, m, 1);
		ll d = b - a;
		printf("Case %d: %lld\n", Case, (n/(2*m)) * d);
	}
	
	return 0;
}
