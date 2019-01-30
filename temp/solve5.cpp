#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<bitset>
#define MAX 100100
using namespace std;




void dfs(int u, int p, long long w) {
	par[u][0] = p;
	lvl[u] = lvl[v]+1;
	timer[vis[u] = ++dfsTime] = u;

	for(int i = 1; i <= 20; ++i)
		par[u][i] = par[par[u][i-1]][i-1];

	for(int i = 0; i < G[u].size(); ++i)
		if(G[u][i] != p)
			dfs(G[u][i], u, w+W[u][i]);
}

int LCA(int u, int v) {
	if(lvl[u] < lvl[v]) swap(u, v);

	for(int p = 20; p >= 0; --p)
		if(lvl[u] - (1 << p) >= lvl[v])
			u = par[u][p];

	if(u == v) return u;
	
	for(int p = 20; p >= 0; --p)
		if(par[u][p] != par[v][p])
			u = par[u][p], v = par[v][p];

	return par[u][p];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	for(int i = 1; i < n; ++i) {
		cin >> u >> v >> w;
		G[u].push_back(v);
		G[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}

	cin >> q;
	dfs(1, 0, 0);

	while(q--) {
		cin >> ch >> x;

		int l[]

	}

	
}