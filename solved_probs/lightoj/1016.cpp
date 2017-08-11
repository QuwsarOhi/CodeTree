// LightOJ
// 1016 - Brush (II)
// Greedy

// There is only one way to maximize the process
// Sort points according to x
// Start from most positive or most negative value of x
// Mark it as first point
// Take other points for which (x1 - x2) <= w
// If x1 - x2 > w, then make the x2 as new starting point, and increment the counter
// Continue this process

#include <bits/stdc++.h>
using namespace std;


int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, x, y, n, w, cnt, start;
	priority_queue<int>pq;
	
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &n, &w);
		
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &x, &y);
			pq.push(y);
		}
		
		if(n == 0) {
			printf("Case %d: 0\n", Case);
			continue;
		}
		
		cnt = 0;
		start = pq.top();
		while(!pq.empty()) {
			if(abs(pq.top() - start) <= w) {
				pq.pop();
				if(pq.empty()) {
					++cnt;
				}
			}
			else {
				start = pq.top();
				pq.pop();
				++cnt;
				if(pq.empty()) {
					++cnt;
				}
			}
		}
			
		printf("Case %d: %d\n", Case, cnt);
	}
	
	
	return 0;
}
