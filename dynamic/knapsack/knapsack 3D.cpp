// UVa
// 10616 - Divisible Group Sums
// DP

#include <bits/stdc++.h>
using namespace std;


int n, m, q, d, cnt, num[210], dp[205][205][12];

int knapsack(int i, int sum, int taken) {
	if(taken > m || i > n || taken > 10)
		return 0;
	if(taken == m) {
		if(sum != 0)
			return 0;
		else
			return 1;
	}
	if(dp[i][sum][taken] != -1) {
		//printf("cache hit on %d %d %d : %d\n", i, sum, taken, dp[i][sum][taken]);
		return dp[i][sum][taken];
	}
	//printf("%d %d %d\n", i, sum, taken);
	return dp[i][sum][taken] = knapsack(i+1, (sum+num[i])%d, taken+1) + knapsack(i+1, sum, taken);
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int t = 0;
	while(scanf("%d %d", &n, &q) && (n || q)) {
		for(int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		printf("SET %d:\n", ++t);
		knapsack(0, 0, 0);
		for(int s = 1; s <= q; ++s) {
			scanf("%d %d", &d, &m);
			memset(dp, -1, sizeof(dp));
			printf("QUERY %d: %d\n", s, knapsack(0, 0, 0));
		}
	}
	return 0;
}
