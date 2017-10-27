// LightOJ
// 1021 - Painful Bases 
// Number DP

#include <bits/stdc++.h>
#define isOn(x, i) (x & (1<<i))
using namespace std;
typedef long long ll;


char dig[20];
ll dp[(1<<17)+10][21], k, Pow[25];
int Dig_size, base;


inline int ToDec(char x) {
	if(isalpha(x))
		return x - 'A' + 10;
	return x - '0';
}


ll recur(int mask, int rem) {
	if(mask == (1 << Dig_size) -1)
		return (rem == 0);
	
	if(dp[mask][rem] != -1)
		return dp[mask][rem];
	
	int exp = __builtin_popcount(mask);
	
	ll sum = 0;
	for(int i = 0; i < Dig_size; ++i)
		if(!isOn(mask, i))
			sum += recur(mask|(1<<i), (rem + (ToDec(dig[i]) * Pow[exp]))%k);
		
	return dp[mask][rem] = sum;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%lld", &base, &k);
		
		scanf(" %s", dig);
		Dig_size = strlen(dig);
		memset(dp, -1, sizeof dp);
		
		Pow[0] = 1;
		for(int exp = 1; exp < 20; ++exp)
			Pow[exp] = (Pow[exp-1] * base)%k;

		printf("Case %d: %lld\n", Case, recur(0, 0));
	}
	
	return 0;
}
