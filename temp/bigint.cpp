#include <bits/stdc++.h>
#define INF -1e10
using namespace std;

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	int t, n, p[100010], q[100010], lsum[100010], rsum[100010], best_point;
	long long sum = 0;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		sum = 0;
		best_point = -1;
		for(int i = 0; i < n; ++i)
			scanf("%d", &p[i]);				// Contains the ammount of petrol i'th gas station contains
		
		for(int i = 0; i < n; ++i) {
			scanf("%d", &q[i]);
			sum += p[i] - q[i];
		}
		//printf("\n");
		lsum[0] = p[0] - q[0];
		rsum[0] = sum;
		sum -= p[0] - q[0];
		printf("%d %d\n", lsum[0], rsum[0]);
		for(int i = 1; i < n; ++i) {
			lsum[i] = p[i] - q[i] + lsum[i-1];
			rsum[i] = sum;
			sum -= p[i] - q[i];
			printf("%d %d\n", lsum[i], rsum[i]);
		}
		//if(p[n-1] - q[n-1] >= 0 && lsum[n-2] + p[n-1] - p[n-1] >= 0)
			//best_point = n-1;
		for(int i = n-1; i > 0; --i) {
			// this point is positive && can cover from this point clockwise && the left gas can fill up the previous gas needs 
			//if(rsum[i] >= rsum[i+1] && rsum[i] >= 0 && lsum[i-1] + rsum[i] >= 0)
				//best_point = i;
			//if(best_point != -1 && rsum[i] < 0)
				//break;
			if(best_point == -1 && rsum[i] >= 0 && lsum[i-1] + rsum[i] >= 0)
				best_point = i;
			else if(best_point == i+1 && rsum[i] >= 0 && rsum[i] + lsum[i-1] >= 0 && p[i] - q[i] >= 0)
				best_point = i;
		}
		if(best_point == -1 && lsum[0] >= 0 && lsum[0] + rsum[1] >= 0)
			best_point = 0;
		else if(best_point == 1 && p[0] - q[0] >= 0)
			best_point = 0;
		//if(best_point == 1 && (p[0] - q[0]) >= 0)
			//best_point = 0;
		
		if(best_point != -1)
			printf("Case %d: Possible from station %d\n", Case, best_point+1);
		else
			printf("Case %d: Not possible\n", Case);
	}
	return 0;
}
