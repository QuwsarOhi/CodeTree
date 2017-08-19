// UVa
// 10057 - A mid-summer night's dream.
// Find the median

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int n, val[1000010], a, b, c, mid;
	while(scanf("%d", &n) == 1) {
		for(int i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		// Minimum distance number of any list of number is the median of the list
		sort(val+1, val+n+1);
		if(n & 1) {		// Odd
			mid = n/2 + 1;
			a = val[mid];
		}
		else {			// Even
			mid = n/2;
			a = min(val[mid], val[mid+1]);
		}
		b = 0;
		for(int i = 1; i <=n; ++i) {		// Search for the same value
			if(val[i] == val[mid])
				++b;
			if(!(n & 1))
				if(val[i] == val[mid+1] && val[mid] != val[mid+1])
					++b;
		}
		if(n & 1) {
			c = 1;
		}
		else
			c = val[mid+1] - val[mid] + 1;
			
		printf("%d %d %d\n", a, b, c);
	}
		
	return 0;
}
