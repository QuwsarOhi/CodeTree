// LightOJ
// 1005 - Rooks
// Counting


#include <bits/stdc++.h>
using namespace std;

unsigned long long C(int n, int r) {
	if(n-r < r)
		r = n-r;
	
	unsigned long long ans = 1;
	for(int i = 1; i <= r; ++i) {
		ans *= (n-i+1);
		ans /= i;
	}
	return ans;
}

int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, k, n;
	scanf("%d", &t);
	unsigned long long ans;

	for(int Case = 1; Case <=t; ++Case) {
		scanf("%d%d", &n, &k);
		printf("Case %d: ", Case);

		if(n == k) {
			ans = 1;
			for(unsigned long long i = 0; i < k; ++i)
				ans *= (n-i);
				
			printf("%llu\n", ans);
		}
		else if(k > n) {
			printf("0\n");
		}
		else {
			ans = 1;
			for(unsigned long long i = 0; i < k; ++i)
				ans *= (n-i);
			ans *= C(n, k);
			printf("%llu\n", ans);
		}
		
	}
	
	
	return 0;
}
