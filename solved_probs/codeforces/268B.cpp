// Codeforces
// B. Buttons
// http://codeforces.com/problemset/problem/268/B

#include <bits/stdc++.h>
using namespace std;


int main() {
	long long n, sum = 0;
	scanf("%lld", &n);
	sum = n;
	
	if(n== 1) {
		printf("1\n");
		return 0;
	}
	
	for(int i = 2; i < n; ++i) {
		sum += i*(n-i) + 1;
	}

	printf("%lld\n", sum+1);
	return 0;
}
