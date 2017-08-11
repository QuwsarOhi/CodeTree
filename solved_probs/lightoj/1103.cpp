// LightOJ
// 1103 - Castle Walls
// Segment Tree, Interval Tree, Binary Search, Binary Indexed Tree(Fenwick Tree)
// Solved using Binary Indexed Tree

// Main idea is to sort the input according to the peasants position (no two peasants are in the same position)
// I did sorting in Counting Sort
// Then start from position 1 to n+k
// and update by 1 the hook position from right to left (Note: BIT does it in left to right, I tweaked the code)
// In this way :
// If there is any peasant who grappels on a position that is in the middle of some other hooks, then the position will contain the overlaps

#include <bits/stdc++.h>
using namespace std;

int tree[200010], MaxVal = 200005, person[200010];

void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int read(int idx) {
	int ans = 0;
	while(idx > 0) {
		ans += tree[idx];
		idx -= (idx & -idx);
	}
	return ans;
}


int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	register int t, x, y, n, m;
	long long ans = 0;
	
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &m);
		int k = n+m;
		
		for(int i = 0; i < 200010; ++i) {
			person[i] = -1;
			tree[i] = 0;
		}
		
		for(int i = 0; i < k; ++i) {
			scanf("%d %d", &x, &y);
			person[x] = y;
		}
		
		ans = 0;
		for(int i = 1; i <= k; ++i) {
			if(person[i] != -1) {
				ans += read(MaxVal - person[i]);
				update(MaxVal - person[i], 1);
			}
		}
		
		printf("Case %d: %lld\n", Case, ans);

	}
	
	
	return 0;
}
