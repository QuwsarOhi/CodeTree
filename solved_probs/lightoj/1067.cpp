// LightOJ
// 1067 - Combinations

// This problem is challenging if one doesnt know how the modulo of division works 
// How modulo of division works : https://math.stackexchange.com/questions/964149/calculating-a-b-mod-p
// The main equation is :
// (a / b) mod p = ((a mod p) * (((b^(p - 2) mod p)) mod p)) mod p 

// also the permutation must be generated in DP than using any other way (recursive or loop for binomial co-eff will not work)

#include <bits/stdc++.h>
#define MOD 1000003
typedef unsigned long long  ull;
using namespace std;

ull P[1000010];

ull PowMod(ull n, ull p) {
	ull pow = 1;
	n %= MOD;
	while(p) {
		if(p&1)
			pow = (pow * n) % MOD;
		n = (n * n) % MOD;
		p >>= 1;
	}
	return pow;
}
	

int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	P[0] = 1;
	for(ull i = 1; i <= 1000000; ++i) {
		P[i] = (P[i-1]%MOD * (i%MOD))%MOD;
		//printf("%llu\n", P[i]);
	}
		
	int t, k, n;
	ull b;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &k);
		printf("Case %d: ", Case);
		if(k == 0)
			printf("1\n");
		else {
			b = (P[k]%MOD * P[n-k]%MOD)%MOD;
			printf("%llu\n", ((P[n]%MOD) * PowMod(b, MOD-2)%MOD)%MOD);
		}
	}
	
	return 0;
}
