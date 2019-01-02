// LightOJ
// 1180 - Software Company

#include <bits/stdc++.h>
using namespace std;


bool dp[101][101][101];
int vis[101][101][101], visCnt, p[101][2], n, m;

int recur(int pos, int p1, int p2, const int maxTime) {
	if(p1 == 0 and p2 == 0)
		return 1;
	if(pos == n)
		return 0;

	bool &ret = dp[pos][p1][p2];
	if(vis[pos][p1][p2] == visCnt)
		return ret;

	vis[pos][p1][p2] = visCnt;
	ret = 0;
	for(int i = 0; i * p[pos][0] <= maxTime and i <= p1; ++i) {
		int j = (maxTime - (i* p[pos][0])) / p[pos][1];
		j = min(j, p2);
		if(recur(pos+1, p1-i, p2-j, maxTime))
			return ret = 1;
	}

	return ret;
}


int BinarySearch(int lo, int hi) {
	int mid;
	while(lo <= hi) {
		mid = (lo+hi)/2;
		++visCnt;
		if(recur(0, m, m, mid))
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return mid;
}

int main() {
	int t;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; ++i)
			scanf("%d%d", &p[i][0], &p[i][1]);

		int ans = BinarySearch(0, p[0][0]*m + p[0][1]*m);
		printf("Case %d: %d\n", Case, ans);
	}

	return 0;
}