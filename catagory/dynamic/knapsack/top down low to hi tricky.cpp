// UVa
// 10819 - Trouble of 13-Dots
// Took help from
// https://saicheems.wordpress.com/2013/09/06/uva-10819-trouble-of-13-dots/
#include <bits/stdc++.h>
# define INF 1e7
using namespace std;

int cost[102], favour[102], dp[400000][102], totalCost, n, m;

// In this knapsack problem, there is a boundary case that needs to be taken care of
// If 13-dot is permitted to use less or equal than 1800 dollar, then it's not possible for her
// to take an extra bonus of 200, (1800 + 200 = 2000, to get extra she needs to spend more than 2000! )
// If she is permitted to use more than 1800 dollar, then there is a chance of getting a 200 dollar extra
// example: permitted to use 1801 dollar
// buyes a product of 2001 dollar, (this is possible as the bank gives 200 dollar to her as she spent more than 2000 dollar)
// in this case she actually spent 1801 dollar (she gave 2001 dollar for a product, and the atm gave 200 dollar bonus)
// so total spent money : 2001 - 200 = 1801 dollar

int knapsack(int totalMoney, int element) {
	if(totalMoney > m && m <= 1800)		// Won't take if total spent money is greater than given money
		return -INF;					// and given money is less than 1800 as to get extra 200 we need to spent more than 2000
	if(totalMoney > m + 200)			// Won't take either if the spent money is more than m + 200 (in this case the given money	
		return -INF;					// is more than 1800
	if(element == n) {					// All elements are used
		if(totalMoney > m && totalMoney <= 2000)	// If total spent money is greater than given money (and less than given money + 200)
			return -INF;				// and total money is less or equal to 2000, then this case is not possible  [m + 200 <= total_spent <= 2000]
		return 0;						// else this can be used
	}
	if(dp[totalMoney][element] != -1)
		return dp[totalMoney][element];
	return dp[totalMoney][element] = max(knapsack(totalMoney+cost[element], element+1) + favour[element],\
		knapsack(totalMoney, element+1));
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	while(scanf("%d %d", &m, &n) == 2) {
		for(int i = 0; i < n; ++i)
			scanf("%d %d", &cost[i], &favour[i]);
		//for(int i = 0; i <= m; ++i)
			//for(int j = 0; j <= n; ++j)
				//dp[i][j] = -1;
		memset(dp, -1, sizeof(dp));
		printf("%d\n", knapsack(0, 0));
	}
	return 0;
}
