#include <bits/stdc++.h>
using namespace std;

vector<int>G[110];
int color[110], isBlack[110];

int ColorDfs(int u, int p) {
	color[u] = p%2;

	
	isBlack[u] = isBlack[u] or color[u];

	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(color[v] == -1)
			ColorDfs(v, p+1);
	}

	color[u] = -1;
}

int main() {
	int t, u, v, V, E;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &V, &E);

		for(int i = 0; i < E; ++i) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}

		int ans = 0;
		memset(color, -1, sizeof color);
		memset(isBlack, 0, sizeof isBlack);

		ColorDfs(1, 0);

		for(int i = 1; i <= V; ++i)
			printf("Color %d : %d\n", i, isBlack[i]);

		for(int i = 1; i <= V; ++i) 
			ans += isBlack[i] > 0;

		printf("Case %d: %d\n", Case, ans);

		for(int i = 0; i <= V; ++i)
			G[i].clear();
	}

	return 0;
}