#include <bits/stdc++.h>
using namespace std;


int main() {
	long long t, k, a, b;
	
	scanf("%lld", &t);
	
	while(t--) {
		scanf("%lld%lld%lld", &k, &a, &b);
		if(k == 3) {
			printf("0\n");
			continue;
		}
		long long mid = k/2 + 1;
		long long op_mid = (a + (mid-1))%k;
		if((k & 1) && b <= op_mid) {
			if(a > b)
				b += k;
			printf("%lld\n", abs(a-b)-1);
		}
		else if(!(k & 1) && b < op_mid) {
			if(a > b)
				b += k;
			printf("%lld\n", abs(a-b)-1);
		}
		else
			printf("0\n");
	}
	
	return 0;
}
