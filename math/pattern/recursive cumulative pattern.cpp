// UVa
// 10994 - Simple Addition
// Recursive Cumulative Sum
#include <bits/stdc++.h>
using namespace std;

long long cSum(long long x) {
	return (x*(x+1))/2;
}

long long cal(long long x) {
	if(x < 10)
		return cSum(x);
	if(x == 0)
		return 0;
	return (x/10 * 45) + cSum(x%10) + cal(x/10);
}



int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	long long p, q;
	while(1) {
		scanf("%lld %lld", &p, &q);
		if(p < 0 || q < 0)
			break;
		printf("%lld\n", cal(q) - cal(p-1));
	}
	return 0;
}
