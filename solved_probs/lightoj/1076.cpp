// LightOJ
// 1076 - Get the Containers
// Bisection, Greedy

// To solve this problem we have to use bisection, and to test the bisect value isPossible function is used (this function is greedy)
// One thing to note, the upper limit of bisect may become too much high
// Check for n = 1000, c = 10^6 (for all of the vessel) and m = 1


#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

ull v[1010], n, k;

bool isPossible(ull lim) {
	ull taken = 0, full = 0;
	for(int i = 0; i < (int)n; ++i) {
		if(v[i] > lim)
			return 0;
		if(taken+v[i] > lim) {
			taken = v[i];
			++full;
		}
		else
			taken+=v[i];
	}
	++full;
	if(full > k)
		return 0;
	return 1;
}

ull bisection(ull lo, ull hi) {
	ull mid, ans;
	for(int i = 0; i < 60; ++i) {
		mid = (hi+lo)/2;
		if(isPossible(mid)) {
			ans = mid;
			hi = mid;
		}
		else
			lo = mid;
	}
	return ans;
}
			

int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t;
	//ull mx;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
			//mx = 0;
			scanf("%llu%llu", &n, &k);
			for(int i = 0; i < (int)n; ++i) {
				scanf("%llu", &v[i]);
				//mx = max(v[i], mx);
			}
			printf("Case %d: %llu\n", Case, bisection(1, 1e15));
	}
	return 0;
}
