// UVa
// 562 - Dividing coins
// 0-1 Knapsack

#include <bits/stdc++.h>
using namespace std;


//Note : val array contains element values starting from 1 index, 0 index is empty
int Knapsack(int totalWeight, int val[], int totalElements) {
	int dp[50001][101];				// DP Table [BagWeight][TotalElements]
	//int track[101] = {0};			// Use this if you want to print the taken elements
	for(int i = 0; i <= totalWeight; i++)
		dp[i][0] = 0;						// Base Case
	
	// Calculating best weight(that will be taken) for every possible element
	for(int i = 1; i <= totalElements; i++) {		// Element starts from 1
		for(int weight = 1; weight <= totalWeight; weight++) {
			if(val[i] > weight)						// If elements weight is greater than available weight
				dp[weight][i] = dp[weight][i-1];	// Skip this element
			else {									// If enough space is available for this element
				if(dp[weight][i-1] >= dp[weight-val[i]][i-1] + val[i])
					dp[weight][i] = dp[weight][i-1];	// If ignoring this element causes good outcome, ignore this
				else {
					dp[weight][i] = dp[weight - val[i]][i-1] + val[i];	// Otherwise take this element
					//track[dp[weight][i]] = i;							// This tracks the taken element
				}
			}
		}
	}
	/* These code outputs the taken values
	int sumWeight = dp[totalWeight][totalElements];
	int lastTakenElement = track[totalWeight];
	while(lastTakenElement != 0) {					// lastTakenElement is the index of element
		printf("%d ", val[lastTakenElement]);		// val[lastTakenElement] is taken value
		sumWeight -= val[lastTakenElement];
		lastTakenElement = track[sumWeight];
	}
	printf("\n");*/
	
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
