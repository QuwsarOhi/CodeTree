// UVa
// 
//

#include <bits/stdc++.h>
using namespace std;


//Note : val array contains element values starting from 1 index, 0 index is empty
int Knapsack(int totalWeight, int val[], int totalElements) {
	int dp[50001][101];						// DP Table [BagWeight][TotalElements]
	
	for(int i = 0; i <= totalWeight; i++)
		dp[i][0] = 0;						// Base Case
	
	// Calculating best weight(that will be taken) for every possible element
	for(int i = 1; i <= totalElements; i++) {		// Element starts from 1
		for(int weight = 0; weight <= totalWeight; weight++) {
			if(val[i] <= weight)					// Take this element, Skip this element
				dp[weight][i] = max(dp[weight-val[i]][i-1]+val[i], dp[weight][i-1]);
			else 									// Skip this element
				dp[weight][i] = dp[weight][i-1];
		}
	}
	return dp[totalWeight][totalElements];
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int t, n, val[103];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &val[i]);
			sum += val[i];
		}
		int knap = Knapsack(sum/2, val, n);
		printf("%d\n", sum - (2*knap));
	}
	return 0;	
}
