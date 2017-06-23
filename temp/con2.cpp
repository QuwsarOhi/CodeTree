#include <bits/stdc++.h>
using namespace std;


int main() {
	//freopen("in", "r", stdin);
	
	int n, m, val[55];
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &val[i]);
	}
	long long dp[n+10] = {0};
	dp[0] = 1;
	sort(val, val+m);
	for(int coin = 0; coin < m; ++coin) {
		for(int value = 1; value <= n; ++value) {
			if(val[coin] <= value)
				dp[value] = dp[value] + dp[value-val[coin]];
		}
	}
	
	printf("%lld\n", dp[n]);
	return 0;
}
