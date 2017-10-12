// LightOJ
// 1011 - Marriage Ceremonies

#include <bits/stdc++.h>
using namespace std;

int v[20][20], n, dp[18][270000];

int recur(int i, int mask) {
	if(i == n)
		return 0;
	
	if(dp[i][mask] != -1)
		return dp[i][mask];
	
	for(int j = 0; j < n; ++j)
		if(!(mask & (1<<j)))
			dp[i][mask] = max(recur(i+1, mask|(1<<j))+v[i][j], dp[i][mask]);
	
	return dp[i][mask];
}

int main() {
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		
		for(int i = 0; i < 18; ++i)
			for(int j = 0; j < 270000; ++j)
				dp[i][j] = -1;
				
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &v[i][j]);
		
		printf("Case %d: %d\n", Case, recur(0, 0));
	}
	return 0;
}
