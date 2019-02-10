#include <bits/stdc++.h>
#define MAX 100010
#define INF 0x3f3f3f3f
using namespace std;

int root[MAX], sz[MAX], st[MAX], ed[MAX], recieve[MAX], qTag[MAX], gotNode[MAX], timer, isRoot[MAX];
vector<int>G[MAX];
vector<pair<int, int>>Query;

int Root(int x) {
	if(root[x] == x)
		return x;
	return root[x] = Root(root[x]);
}

void Union(int x, int y) {
	x = Root(x), y = Root(y);
	if(x == y) return;

	if(sz[x] < sz[y]) {
		sz[y] += sz[x];
		root[x] = y;
	}
	else {
		sz[x] += sz[y];
		root[y] = x;
	}
}

bool SameCompo(int x, int y) {
	return Root(x) == Root(y);
}

void dfs(int u) {
	st[u] = ++timer;
	for(auto v : G[u])
		dfs(v);
	ed[u] = timer;
}

bool isChild(int ch, int par) {
	return st[par] <= st[ch] and st[ch] <= ed[par];
}

int main() {
	int n, m, u, v, qCnt = 0, typ;
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; ++i)
		root[i] = i, qTag[i] = INF, sz[i] = 1, isRoot[i] = 1;

	for(int i = 0; i < m; ++i) {
		scanf("%d", &typ);

		if(typ == 1) {
			scanf("%d%d", &u, &v);
			G[v].push_back(u);
			qTag[v] = min(qTag[v], qCnt);
			isRoot[u] = 0;
			Union(u, v);
			cerr << v << " :: " << qTag[v] << endl;
		}
		else if(typ == 2) {
			scanf("%d", &u);
			recieve[u] = ++qCnt;
			gotNode[qCnt] = u;
		}
		else {
			scanf("%d%d", &u, &v);
			Query.push_back({u, v});
		}
	}

	for(int i = 1; i <= n; ++i)
		if(isRoot[i])
			dfs(i);

	for(int i = 1; i <= n; ++i)
		cerr << qTag[i] << ", ";
	cerr << endl;

	for(int i = 0; i < Query.size(); ++i) {
		u = Query[i].first;
		int x = Query[i].second;
		v = gotNode[x];

		if((isChild(v, u) and qTag[u] < x) or u == v)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

/*

4 9
1 4 3
2 4
3 3 1
1 2 3
2 2
3 1 2
1 3 1
2 2
3 1 3


5 12
1 4 3
2 4
3 3 1
1 2 3
2 2
3 1 2
1 3 1
2 2
3 1 3
1 5 4
3 5 1
3 4 1

*/