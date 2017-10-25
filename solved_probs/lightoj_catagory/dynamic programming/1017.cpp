// LightOJ
// 1017 - Brush (III)

#include <bits/stdc++.h>
using namespace std;

int N, W, K, cnt, dp[110][110];
vector<int>v;

int AllPossibleC(int pos, int k) {
	++cnt;
	if(pos == (int)v.size() || k == K)
		return 0;
	
	if(dp[pos][k] != -1)
		return dp[pos][k];
	
	int points = 0, i;
	for(i = pos; i < (int)v.size(); ++i) {
		if(v[pos] + W >= v[i])
			++points;
		else
			break;
	}
	
	return dp[pos][k] = max(AllPossibleC(i, k+1)+points, AllPossibleC(pos+1, k));
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, x, y;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d %d", &N, &W, &K);
		
		for(int i = 0; i < N; ++i) {
			scanf("%d %d", &x, &y);
			v.push_back(y);
		}
		
		sort(v.begin(), v.end());
		
		for(int i = 0; i < 105; ++i)
			for(int j = 0; j < 105; ++j)
				dp[i][j] = -1;
		
		printf("Case %d: %d\n", Case, AllPossibleC(0, 0));
		v.clear();
	}
	return 0;
}
		
		
