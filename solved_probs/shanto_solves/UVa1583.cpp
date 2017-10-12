// UVa
// 1583 - Digit Generator

#include <bits/stdc++.h>
using namespace std;


int main() {
	int t, n;
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		bool found = 0;
		for(int i = 45; i > 0 && !found; --i) {
			int t = n-i, sum = 0;
			while(t > 0) {
				sum += t%10;
				t /= 10;
			}
			if(i == sum) {
				found = 1;
				printf("%d\n", n-i);
			}
		}
		
		if(!found)
			printf("0\n");
	}
	
	return 0;
}
