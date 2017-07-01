// UVa
// 11093 - Just Finish it up
// 1D array manipulation

#include <bits/stdc++.h>
#define INF -1e10
using namespace std;

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, n, p[100010], q, rsum[100010], diff[100010], req[100010], best_point;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		best_point = -1;
		for(int i = 0; i < n; ++i)
			scanf("%d", &p[i]);				// Contains the ammount of petrol i'th gas station contains
		
		for(int i = 0; i < n; ++i) {
			scanf("%d", &q);
			diff[i] = p[i] - q;				// Difference of value
		}
		long long neg = 0;
		req[n] = rsum[n] = 0;
		for(int i = n-1; i >= 0; --i) {		// Scan from right to left			req[] contains which points require how much ammount of gas
			if(diff[i] + neg >= 0) {
				req[i] = diff[i] + neg;
				if(req[i+1] > 0)
					req[i] += req[i+1];
				neg = 0;
			}
			else {
				req[i] = diff[i] + neg;
				neg = req[i];
			}
			rsum[i] = diff[i] + rsum[i+1];	// Cumulative sum from right 
		}
		
		/*for(int i = 0; i < n; i++)
			printf("(%d %d)", req[i], rsum[i]);
		printf("\n---------------------------------------------------\n");
		*/
		
		if(req[0] >= 0)
			best_point = 0;
		else {
			for(int i = 1; i < n; i++)
				if(req[i] >= 0 && rsum[i] + req[0] >= 0) {
					best_point = i;
					break;
				}
		}
		
		if(best_point != -1)
			printf("Case %d: Possible from station %d\n", Case, best_point+1);
		else
			printf("Case %d: Not possible\n", Case);
	}
	return 0;
}
