// LightOJ
// 1004 - Monkey Banana Problem
// Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

int dp[219][219], n, m;

int main() {
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		
		for(int i = 0; i < 105; ++i)
			for(int j = 0; j < 105; ++j)
				dp[i][j] = -1e8;
		scanf("%d", &n);
		
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= i; ++j)
				scanf("%d", &dp[i][j]);
		m = 2*n - 1;
		
		for(int i = n+1; i <= m; ++i)
			for(int j = 1; j <= m-i+1; ++j)
				scanf("%d", &dp[i][j]);
				
		for(int i = 2; i <= n; ++i)
			for(int j = 1; j <= i; ++j) {
				if(j == 1)
					dp[i][j] += dp[i-1][j];
				else if(i != j)
					dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
				else
					dp[i][j] += dp[i-1][j-1];
			}
		
		for(int i = n+1; i <= m; ++i)
			for(int j = 1; j <= m-i+1; ++j)
				dp[i][j] += max(dp[i-1][j], dp[i-1][j+1]);
		
		printf("Case %d: %d\n", Case, dp[m][1]);
	}
	return 0;
}
