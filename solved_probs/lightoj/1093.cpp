// LightOJ
// 1093 - Ghajini
// Segment Tree, Interval Tree, Sliding Range Minimum, SQRT decomposition, Priority Query

// Solved With Priority Query
// used two priority_queues, one for the min value, other for max value, also saved the position of that value in the queue
// l r monitors the left index and r monitors the r index so that we have exact d values
// in every input, push it in the two queues, and search if the Max and Min val of the queue is out of the range d, then pop it up
// in this way we can have the maximum distance in O(n * 2log_n)
// get the maximum distance from the queues

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, l, d, n, r, x, MaxDis;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		priority_queue<pair<int, int> >pqMin, pqMax;
		scanf("%d%d", &n, &d);
		l = r = 1;
		MaxDis = -1;
		for(int r = 1; r <= n; ++r) {
			scanf("%d", &x);
			pqMin.push(make_pair(-x, r)), pqMax.push(make_pair(x, r));
			
			if(r - l + 1 > d)
				++l;
			
			while(pqMin.top().second < l) pqMin.pop();
			while(pqMax.top().second < l) pqMax.pop();
			
			MaxDis = max(pqMax.top().first + pqMin.top().first, MaxDis);
		}
		
		printf("Case %d: %d\n", Case, MaxDis);
	}
	
	return 0;
}
