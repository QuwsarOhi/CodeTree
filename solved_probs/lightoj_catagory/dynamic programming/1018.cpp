// LightOJ
// 1018 - Brush (IV)

#include <bits/stdc++.h>
#define isOn(x, i) (x & (1<<i))
#define On(x, i) (x |= (1<<i))
#define Off(x, i) (x &= ~(1<<i))

using namespace std;

inline int PointToArea(int x1, int y1, int x2, int y2, int x3, int y3) {	// Returns Positive Area in if the points are clockwise, Negative for Anti-Clockwise
	return (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
}

int n, dp[(1<<16) + 10], pointdp[20][20], points;
vector<pair<int, int> >v;

inline int recur(int mask) {
	if(__builtin_popcount(mask) == points)
		return 0;
	
	if(points-__builtin_popcount(mask) <= 2)
		return 1;
	
	if(dp[mask] != -1)
		return dp[mask];

	int ans = 1e6;
	
	for(int l = 0; l < (int)v.size()-1; ++l) {
		if(isOn(mask, l))
			continue;
		
		for(int r = l+1; r < (int)v.size(); ++r) {
			if(isOn(mask, r))
				continue;

			ans = min(recur(mask | pointdp[l][r])+1, ans);
		}
		break;
	}
	
	dp[mask] = ans;
	return ans;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, x, y;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		map<pair<int, int>, bool>mp;
		points = 0;
		
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &x, &y);
			if(mp.find(make_pair(x, y)) == mp.end()) {
				v.push_back(make_pair(x, y));
				mp[make_pair(x, y)] = 1;
				++points;
			}
		}
		
		memset(dp, -1, sizeof dp);
		
		for(int i = 0; i < (int)v.size()-1; ++i) {
			for(int j = i+1; j < (int)v.size(); ++j) {
				int tmp = 0;
				for(int k = 0; k < (int)v.size(); ++k) {
					if(PointToArea(v[i].first, v[i].second, v[j].first, v[j].second, v[k].first, v[k].second) == 0)
						On(tmp, k);
				}
				pointdp[i][j] = pointdp[j][i] = tmp;
			}
		}
		
		printf("Case %d: %d\n", Case, recur(0));
		v.clear();
		
	}
	
	return 0;
}
