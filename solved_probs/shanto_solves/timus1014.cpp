// Timus
// 1014. Product of Digits
#include <bits/stdc++.h>
using namespace std;


int main() {
	long long n;
	scanf("%lld", &n);
	vector<int>ans;
	
	// Your task is to find the minimal ''''''positive'''''' integer number Q so that the product of digits of Q is exactly equal to N.
	if(n == 0) { 		// According to number theory, Zero is nor positive or negative number
		printf("10\n");
		return 0;
	}
	
	if(n < 10) {
		printf("%lld\n", n);
		return 0;
	}
	
	for(int i = 9; i >= 2; --i) {
		while(n%i == 0) {
			n /= i;
			ans.push_back(i);
		}
	}
	
	if(n != 1) {
		printf("-1\n");
		return 0;
	}
	
	for(auto it = ans.rbegin(); it != ans.rend(); ++it)
		printf("%d", *it);
	
	printf("\n");
	return 0;
}
