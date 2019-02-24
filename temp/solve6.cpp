#include <bits/stdc++.h>
using namespace std;

int dp[100001];
vector<int>G[100001];

int dfs(int u) {
	int &ret = dp[u];
	if(ret != -1)
		return ret;

	ret = 0;
	for(auto v : G[u])
		ret = max(ret, dfs(v)+1);

	return ret;
}

int main() {
	int u, v, V, E;
	cin >> V >> E;

	for(int i = 0; i < E; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
	}

	memset(dp, -1, sizeof dp);
	int ans = 0;
	for(int i = 1; i <= V; ++i)
		ans = max(ans, dfs(i));

	cout << ans << endl;
	return 0;
}