// LightOJ
// 1271 - Better Tour

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 50010
using namespace std;

map<pair<int, int>, bool> EDGE;
vector<int> G[MAX];
int dis[MAX], par[MAX], a[MAX];

void recur(int v) {
	if(par[v] != -1)
		recur(par[v]);
	else {
		printf("%d", v);
		return;
	}
	printf(" %d", v);
}


void bfs(int s, int t) {
	memset(par, -1, sizeof par);
	memset(dis, INF, sizeof dis);
	queue<int> q;
	q.push(s);
	dis[s] = 0;

	int u, v, d, l = 0;
	while(not q.empty()) {
		u = q.front();
		d = dis[u]+1;
		q.pop();

		if(u == t)
			return;
		
		for(int i = 0; i < G[u].size(); ++i) {
			v = G[u][i];

			if(dis[v] != INF)
				continue;

			par[v] = u;
			dis[v] = d;
			q.push(v);
		}
	}
}



bool newEdge(int u, int v) {
	if(u > v)
		swap(u, v);
	if(u == v)
		return 0;
	if(EDGE.find(make_pair(u, v)) == EDGE.end()) {
		EDGE[make_pair(u, v)] = 1;
		return 1;
	}
	return 0;
}

int main() {
	int t, n;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);

		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			if(i > 0 and newEdge(a[i-1], a[i])) {
				G[a[i-1]].push_back(a[i]);
				G[a[i]].push_back(a[i-1]);
			}
		}

		for(int i = 0; i < MAX; ++i)
			sort(G[i].begin(), G[i].end());

		bfs(a[0], a[n-1]);
		printf("Case %d:\n", Case);
		recur(a[n-1]);
		printf("\n");

		for(int i = 0; i < MAX; ++i)
			G[i].clear();
		EDGE.clear();
	}
	return 0;
}