// Codeforces
// A. Ilya and Bank Account
// http://codeforces.com/problemset/problem/313/A

#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	
	if(n >= 0) {
		printf("%d\n", n);
		return 0;
	}
	
	n *= -1;
	int tmp1 = n/10, tmp2 = (n/100)*10 + n%10;
	
	if(tmp1 < tmp2)
		printf("%d\n", -tmp1);
	else
		printf("%d\n", -tmp2);
		
		
	return 0;
}
