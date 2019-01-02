// LightOJ
// 1092 - Lighted Panels

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m;

void trigger(int x, int y, int G[]) {
	G[x] ^= (1 << y);
	G[x-1] ^= (1 << y);
	G[x+1] ^= (1 << y);

	if(y-1 >= 0) {
		G[x-1] ^= (1 << (y-1));
		G[x] ^= (1 << (y-1));
		G[x+1] ^= (1 << (y-1));
	}
	
	if(y+1 < m) {
		G[x-1] ^= (1 << (y+1));
		G[x] ^= (1 << (y+1));
		G[x+1] ^= (1 << (y+1)); 
	}
}

int G[10], dp[8][(1<<8)+10][(1<<8)+10], cur[8][(1<<8)+10][(1<<8)+10], curCnt = 0;

int recur(int r, int pstMsk, int presMsk) {
	if(r == n) {
		if(pstMsk == ((1 << m)-1))
			return 0;
		return INF;
	}

	if(cur[r][pstMsk][presMsk] == curCnt)
		return dp[r][pstMsk][presMsk];

	cur[r][pstMsk][presMsk] = curCnt;
	int &ret = dp[r][pstMsk][presMsk];
	ret = INF;

	for(int i = 0; i < (1 << m); ++i) {
		int g[] = {pstMsk, presMsk, G[r+1]};
		int toggle = 0;

		for(int j = 0; j < m; ++j)
			if(i & (1 << j))
				++toggle, trigger(1, j, g);

		if(g[0] == (1 << m)-1 or r == 0)
			ret = min(ret, recur(r+1, g[1], g[2])+toggle);
	}

	return ret;
}

int main() {
	int t;
	char cc;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; ++i) {
			G[i] = 0;
			for(int j = 0; j < m; ++j) {
				scanf(" %c", &cc);
				if(cc == '*')
					G[i] |= (1<<j);
			}
		}

		++curCnt;
		int ans = recur(0, 0, G[0]);
		printf("Case %d: ", Case);

		if(ans >= INF)
			printf("impossible\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}