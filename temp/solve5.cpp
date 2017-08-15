#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t, x, y, ans = 0;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld", &x, &y);
		ans += (x-y);
	}
	if(ans >= 0)
		printf("1 %lld\n", ans);
	else
		printf("2 %lld\n", -1*ans);
	return 0;
}
