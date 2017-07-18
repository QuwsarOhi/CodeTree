// LightOJ
// 1089 - Points in Segments (II)
// Segment Tree, Binary Indexed Tree

// This problem can be easily solved with Binary Indexed Tree
// in BIT, update index L, R+1 with 1 for every point, so if we query in any point which is L <= x <= R, then we will get the
// number of updates for each pair of points (which is the answer)

// Another problem arises due to the input number range [0, 10^8], this range of data can't be placed in 64mb memory limit
// This can be solved with mapping

// Every test case can contains total 2 * 50000 (points) + 50000 (query points) = 150000 points in total
// sort the total points, and give an unique integer index in sorted point, then work with this mapped value


#include <bits/stdc++.h>
using namespace std;

int tree[150010], MaxVal = 150005;
vector<pair<int, int> >point_pair;
vector<int>point, sorted_point;
map<int, int>mp;

void update(int idx, int x) {
	while(idx < MaxVal) {
		tree[idx] += x;
		idx += (idx & -idx);
	}
}

int read(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, n, q, x, y, cnt, ans;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &n, &q);
		printf("Case %d:\n", Case);
		cnt = 0;
		point_pair.clear(), sorted_point.clear(), mp.clear(), point.clear();
		memset(tree, 0, sizeof(tree));
		
		
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &x, &y);
			point_pair.push_back(make_pair(x, y));
			sorted_point.push_back(x);
			sorted_point.push_back(y);
		}
		
		for(int i = 0; i < q; ++i) {
			scanf("%d", &x);
			sorted_point.push_back(x);
			point.push_back(x);
		}
		
		sort(sorted_point.begin(), sorted_point.end());
		
		for(int i = 0; i < (int)sorted_point.size(); ++i) {
			if(mp[sorted_point[i]] == 0)
				mp[sorted_point[i]] = ++cnt;
		}
		
		for(int i = 0; i < (int)point_pair.size(); ++i) {
			update(mp[point_pair[i].first], 1);
			update(mp[point_pair[i].second]+1, -1);
		}
		
		for(int i = 0; i < (int)point.size(); ++i) {
			ans = read(mp[point[i]]);
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
