// LightOJ
// 1257 - Farthest Nodes in a Tree (II)

#include <bits/stdc++.h>
using namespace std;

#define MAX 30100
typedef pair<int, int> pii;


vector<int> G[MAX], W[MAX];

int dst[MAX];

pii dfs(int u, int par, int d) {
    pii ret(d, u);                                      // {distance, node}
    for(int i = 0; i < (int)G[u].size(); ++i)
        if(G[u][i] != par)
            ret = max(ret, dfs(G[u][i], u, d+W[u][i]));
    return ret;
}


void distDfs(int u, int par, int d) {
	dst[u] = max(dst[u], d);
	for(int i = 0; i < G[u].size(); ++i) {
		if(G[u][i] == par) 
			continue;

		dst[u] = max(d, dst[u]);
		distDfs(G[u][i], u, d+W[u][i]);
	}
}


int GetDistance() {
    pii left = dfs(0, -1, 0);
    pii right = dfs(left.second, -1, 0);

    distDfs(left.second, -1, 0);
    distDfs(right.second, -1, 0);

    return right.first;
}


int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	int t, u, v, w, V;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &V);

		for(int i = 1; i < V; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(v);
			G[v].push_back(u);
			W[u].push_back(w);
			W[v].push_back(w);
		}

		memset(dst, 0, sizeof dst);
		GetDistance();

		printf("Case %d:\n", Case);
		for(int i = 0; i < V; ++i)
			printf("%d\n", dst[i]);

		for(int i = 0; i < V; ++i)
			G[i].clear(), W[i].clear();
	}

	return 0;
}