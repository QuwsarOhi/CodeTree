// LightOJ
// 1078 - Integer Divisibility
// Basic Math

// Ex for case 1 : 

// 3 | 111 | 37
// 		9 (3*3)
//   -------
//      21			// 2 is left, so carry exists! so add another 1
// 		21 (3*7)
//   -------
//       0			// We used three 1's, so answer is 3


#include <bits/stdc++.h>
using namespace std;

inline int addBack(int digit, int add_last) {
	while(add_last != 0) {
		digit *= 10;
		digit += (add_last%10);
		add_last /= 10;
	}
	return digit;
}


int main() {
	int t, n, digit, cnt, new_digit, carry;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; Case++) {
		scanf("%d %d", &n, &digit);
		cnt = 1;
		new_digit = digit;
		carry = new_digit%n;
		
		while(carry != 0) {
			new_digit = addBack(carry, digit);
			carry = new_digit%n;
			++cnt;
		}
		
		printf("Case %d: %d\n", Case, cnt);
	}
	return 0;
}
