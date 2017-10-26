// LightOJ
// 1025 - The Specials Menu 

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char s[100];
int len;
ll dp[70][70];


ll recur(int l, int r) {
	if(l >= len || r < 0 || l > r)
		return 0;
		
	if(l == r)
		return 1;
	
	if(dp[l][r] != -1)
		return dp[l][r];
		
	ll leftSeg = recur(l, r-1);
	ll rightSeg = recur(l+1, r);
	ll midSeg = recur(l+1, r-1);
	
	if(s[l] == s[r])												// If the boundary matches the number of permutation increases, 
		dp[l][r] = (1 + midSeg) + rightSeg + leftSeg - midSeg;		// The increase value is (1 + midSeg), the other part contains different segments
	else
		dp[l][r] = rightSeg + leftSeg - midSeg;
	
	return dp[l][r];
}

int main() {
	int t;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf(" %s", s);
		
		len = strlen(s);
		memset(dp, -1, sizeof dp);
		
		printf("Case %d: %lld\n", Case, recur(0, len-1));
	}
	
	return 0;
}
