// LightOJ
// 1174 - Commandos

#include <bits/stdc++.h>
using namespace std;

vector<int>G[110];

int bfs(int s, int t) {
	queue<pair<int, int> >q;
	q.push(make_pair(s, 0));

	int u, v, w;
	while(not q.empty()) {
		u = q.front().first;
		w = q.front().second;
		q.pop();

		if(u == t)
			return w;

		for(int i = 0; i < G[u].size(); ++i) {
			v = G[u][i];
			q.push(make_pair(v, w+1));
		}
	}
	return -1;
}

int main() {
	int t, V, E, u, v, S, T;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &V, &E);
		
		for(int i = 0; i < E; ++i) {
			scanf("%d%d", &v, &u);
			G[u].push_back(v);
			G[v].push_back(u);
		}

		scanf("%d%d", &S, &T);

		int ans = 0;
		for(u = 0; u < V; ++u)
			ans = max(ans, bfs(S, u) + bfs(u, T));

		printf("Case %d: %d\n", Case, ans);

		for(int i = 0; i < V; ++i)
			G[i].clear();
	}
	return 0;
}