#include <bits/stdc++.h>
using namespace std;
#define MAX 30100

/*struct pair_hash {
	size_t operator()(const pair<int,int> &p)const {
		return hash<long long>()(((long long)p.first)^(((long long)p.second)<<32));
	}
};*/

struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
unordered_map<pair<int,int>,long long,HASH>dp;

vector<int> G[MAX], W[MAX];
//map<pair<int, int>, long long, pair_hash> dp;



long long dfs(int u, int par, int w) {
	long long ret = 0;

	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(v == par)
			continue;

		if(dp.find(make_pair(v, u)) != dp.end()) {
			// DO SOMETHING??
			//printf("HIT  %d - %d :: %lld\n", u, v, dp[make_pair(v, u)]);
			ret = max(ret, dp[make_pair(v, u)]);
			continue;
		}

		ret = max(ret, dfs(v, u, W[u][i]));
	}

	//printf("From %d to %d :: %lld\n", par, u, ret + w);
	return dp[make_pair(u, par)] = ret + w;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	int t, u, v, w, E;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &E);

		for(int i = 1; i < E; ++i) {
			scanf("%d%d%d", &v, &u, &w);
			G[u].push_back(v);
			G[v].push_back(u);
			W[u].push_back(w);
			W[v].push_back(w);
		}

		printf("Case %d:\n", Case);

		for(int i = 0; i < E; ++i) {
			//printf("Start %d\n", i);
			printf("%lld\n", dfs(i, -1, 0));
		}

		for(int i = 0; i < E; ++i)
			G[i].clear(), W[i].clear();
		dp.clear();
	}

	return 0;
}