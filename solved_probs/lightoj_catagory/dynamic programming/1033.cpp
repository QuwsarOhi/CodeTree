// LightOJ
// 1033 - Generating Palindromes 

#include <bits/stdc++.h>
using namespace std;

char s[1000];
int dp[110][110];

int recur(int l, int r) {
	if(l > r || l == r)
		return 0;
	if(dp[l][r] != -1)
		return dp[l][r];
	if(s[l] == s[r])
		return dp[l][r] = recur(l+1, r-1);
	else
		return dp[l][r] = min(recur(l+1, r), recur(l, r-1))+1;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf(" %s", s);
		int len = strlen(s);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", Case, recur(0, len-1));
	}
	return 0;
}
