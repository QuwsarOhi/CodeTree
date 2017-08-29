// Codeforces
// A. Party
// http://codeforces.com/problemset/problem/115/A

#include <bits/stdc++.h>
using namespace std;

vector<int>G[2010], roots;
int mx_level;

void dfs(int u, int level) {
	mx_level = max(level, mx_level);
	for(auto v : G[u]) {
		dfs(v, level+1);
	}
	return;
}

int main() {
	int V, x;
	mx_level = 0;
	
	scanf("%d", &V);
	
	for(int i = 1; i <= V; ++i) {
		scanf("%d", &x);
		if(x > 0)
			G[x].push_back(i);
		else
			roots.push_back(i);
	}
	
	for(auto u : roots)
		dfs(u, 1);
	
	printf("%d\n", mx_level);
	
	return 0;
}
