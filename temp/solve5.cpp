#include <bits/stdc++.h>
#define MAX 20100
using namespace std;

vector<int>G[MAX];
int indegree[MAX], vis[MAX], timer, leaf;
set<int>SET;

/*void dfs(int u) {
	timer++;
	if(vis[u] != -1) {
		SET.insert(vis[u]);
		return;
	}

	cnt += G[u].empty();

	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		dfs(v);
	}

	vis[u] = timer;
}*/

void dfs(int u) {
	vis[u] = 1;
	leaf += G[u].empty();

	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];

		if(vis[v] == -1)
			dfs(v);
	}
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int t, V, u, v;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &V);
		memset(indegree, 0, sizeof indegree);

		for(int i = 1; i < V; ++i) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			//rG[v].push_back(u);
			indegree[v]++;
		}

		memset(vis, -1, sizeof vis);

		leaf = 0;
		int root = 0;
		for(u = 0; u < V; ++u) {
			if(indegree[u] != 0)
				continue;

			++root;
			dfs(u);

			/*if(SET.empty())
				cout << "empty";
			for(auto it : SET)
				cout << it << " ";
			cout << endl;

			cout << "CNT " << leaf << endl;
			leaf += SET.size();
			SET.clear();*/
		}

		//cout << "Root " << root << endl;

		int ans = 0;
		if(root > leaf)
			ans = leaf + root - leaf;
		else
			ans = leaf;

		printf("Case %d: %d\n", Case, ans);

		for(int i = 0; i <= V; ++i) G[i].clear();
	}
	return 0;
}