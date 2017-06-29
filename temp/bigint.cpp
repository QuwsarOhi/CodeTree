#include <bits/stdc++.h>
using namespace std;

int F(int n) {
	if(n == 0)
		return 0;
	else if(n%10 > 0)
		return n%10;
	else {
		printf("recurse (%d) ", n);
		return F(n/10);
	}
}

int main() {
	long long p,q;
	while(1) {
		scanf("%lld %lld", &p, &q);
		if(p < 0 || q < 0)
			break;
		long long sum = 
		printf("\n");
	}
	
	return 0;
}
