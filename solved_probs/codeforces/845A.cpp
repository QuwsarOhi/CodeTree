// CodeForces
// A. Chess Tourney
// http://codeforces.com/contest/845/problem/A


#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, x[500];
	
	scanf("%d", &n);
	for(int i = 0; i < 2*n; ++i) {
		scanf("%d", &x[i]);
	}
	bool ok = 1;
	sort(x, x+(2*n));
	for(int i = 0, j = 2*n-1; i < n; ++i, j--) {
		if(x[i] == x[j])
			ok = 0;
	}
	if(ok)
		printf("YES\n");
	else
		printf("NO\n");
		
	return 0;
}
