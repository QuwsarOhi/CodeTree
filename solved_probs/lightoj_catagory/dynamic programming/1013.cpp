// LightOJ
// 1013 - Love Calculator 

#include <bits/stdc++.h>
using namespace std;

char s1[40], s2[40];
int len1, len2, MinLCS;
long long dp[32][32][70];

long long recur(int p1, int p2, int taken) {
	if((p1 == len1 && p2 == len2) && taken == MinLCS)
		return 1;
	if((p1 == len1 && p2 == len2) && taken != MinLCS)	
		return 0;
	
	if(dp[p1][p2][taken] != -1)
		return dp[p1][p2][taken];
	
	long long ans = 0;
	if(p1 == len1)
		ans += recur(p1, p2+1, taken+1);
	else if(p2 == len2)
		ans += recur(p1+1, p2, taken+1);
	else if(s1[p1] == s2[p2])
		ans += recur(p1+1, p2+1, taken+1);
	else
		ans += recur(p1+1, p2, taken+1) + recur(p1, p2+1, taken+1);
		
	return dp[p1][p2][taken] = ans;
}

int MinLen(int p1, int p2, int taken) {
	if(p1 >= len1)
		return taken+abs(len2-p2);
	if(p2 >= len2)
		return taken+abs(len1-p1);

	if(dp[p1][p2][taken] != -1)
		return dp[p1][p2][taken];
		
	if(s1[p1] == s2[p2])
		return dp[p1][p2][taken] = MinLen(p1+1, p2+1, taken+1);
	else
		return dp[p1][p2][taken] = min(MinLen(p1+1, p2, taken+1), MinLen(p1, p2+1, taken+1));
}


int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%s %s", s1, s2);
		len1 = strlen(s1);
		len2 = strlen(s2);
		
		memset(dp, -1, sizeof dp);
		MinLCS = MinLen(0, 0, 0);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d %lld\n", Case, MinLCS, recur(0, 0, 0));
	}
	return 0;
}
