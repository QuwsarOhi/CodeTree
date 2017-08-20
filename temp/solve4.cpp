#include <bits/stdc++.h>
using namespace std;


int main() {
	long long t, n, a, b;
	scanf("%lld", &t);
	
	while(t--) {
		scanf("%lld%lld%lld", &n, &a, &b);
		long long m = (n/2) + 1;
		if(n & 1)
			m += 1;
		long long opp_mid = (a+(m-1))%n;
		//cout << m << " " << opp_mid << endl;
		if(b < opp_mid && a != opp_mid && opp_mid > 0 && n != 3) {
			if(a > b)
				b += n;
			//cout << a << " " << b << endl;
			printf("%lld\n", abs(a-b)-1);
		}
		else
			printf("0\n");
			
	}
	return 0;
}
