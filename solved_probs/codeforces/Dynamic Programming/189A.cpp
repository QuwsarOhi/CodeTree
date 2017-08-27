// Codeforces
// A. Cut Ribbon
// http://codeforces.com/problemset/problem/189/A

#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int n, x[3], dp[4010];

int recur(int len) {
	
	if(len == 0)
		return 0;
		
	if(len < 0)
		return -INF;
	
	if(dp[len] != -INF)
		return dp[len];
		
	for(int i = 0; i < 3; ++i) {
		dp[len] = max(dp[len], recur(len-x[i])+1);
	}
	
	return dp[len];
}


int main() {
	scanf("%d%d%d%d", &n, &x[0], &x[1], &x[2]);
	for(int i = 0; i <= n; ++i) {
		dp[i] = -INF;
	}
	printf("%d\n", max(0, recur(n)));
	return 0;
}
