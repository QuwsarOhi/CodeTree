// CodeForces
// B. Bash's Big Day
// http://codeforces.com/problemset/problem/757/B
// GCD
// Calculate maxumum number of elements can be taken from n elements where GCD > 1 and

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, factor[100100], mx = 0;
	
	memset(factor, 0, sizeof factor);
	
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		int l = sqrt(x);
		for(int i = 2; i <= l; ++i) {
			if(x%i == 0)
				mx = max(mx, ++factor[i]);
			while(x%i == 0)		// Taking one factor only once
				x/=i;
		}
		
		if(x > 1)		// Excludint 1, we dont need it!
			mx = max(mx, ++factor[x]);
	}
	
	if(mx == 0) ++mx;	// A critical case of the problem
	
	printf("%d\n", mx);
	
	return 0;
}
