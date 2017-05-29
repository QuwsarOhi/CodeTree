//LightOJ
//1083 - Histogram 

#include <bits/stdc++.h>
using namespace std;


int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, n;
	long long R[30010], L[30010], H[30010];
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%lld", &H[i]);
		// Generate Segments
		// We'll allways try to spread segment, as it can maximize the area
		// So, for every histogram point i, we'll try to spread left and right segment point
		// Generating best left points of segment
		for(int i = 1; i <= n; ++i) {		// For poin i, calculate the largest segment
			int j = i;						// We'll find the best left segment point using j
			while(j > 1 && H[j-1] >= H[i])	// If the previous height is higher than the current height
				j = L[j-1];					// take the left segment point of previous node
			L[i] = j;						// set j as a left segment point
		}
		// Generating best right points of segment
		for(int i = n; i >= 1; --i) {
			int j = i;
			while(j < n && H[j+1] >= H[i])
				j = R[j+1];
			R[i] = j;
		}
		long long mx = 0;
		for(int i = 1; i <= n; ++i) {
			mx = max(mx, H[i] * (R[i] - L[i] + 1));
		}
		printf("Case %d: %lld\n", Case, mx);
	}
	return 0;
}
