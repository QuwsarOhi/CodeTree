// Codeforces
// Round 429 Div.2
// B. Godsend
// Math, Game
// http://codeforces.com/contest/841/problem/B


#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, odd = 0, x;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		if(x & 1) {
			odd++;
		}
	}
	
	if(odd == 0)
		printf("Second\n");
	else
		printf("First\n");
	
	return 0;
}
