// Codeforces
// B. Taxi
// http://codeforces.com/problemset/problem/158/B

#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, x, taxi = 0, v[5];
	
	memset(v, 0, sizeof v);
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		if(x == 4) {
			taxi++;
		}
		else
			v[x]++;
	}
	
	
	while(v[3]) {
		if(v[1] > 0)
			--v[1];
		v[3] -= 1;
		++taxi;
	}
	
	while(v[2]) {
		if(v[2] > 1)
			v[2] -= 1;
		else if(v[1] > 1)
			v[1] -= 2;
		else if(v[1] == 1)
			v[1] -= 1;
		v[2] -= 1;
		++taxi;
	}
	
	taxi += ceil(v[1]/4.0);
	
	printf("%d\n", taxi);
	return 0;
}
