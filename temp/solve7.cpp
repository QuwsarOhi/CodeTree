#include <bits/stdc++.h>
#define MAX 500100
using namespace std;

vector<int>G[MAX];
int cnt[MAX][27];

void dfs(int u, int par = -1, int lvl = 1) {
	startTime[u] = t;
	lvlTime[lvl].push_back(t);
	timeNode[t] = u;

	for(auto v : G[u])
		if(v != par) {
			++t;
			dfs(v, u, lvl+1);
		}

	endTime[u] = t;
}

int main() {
	int n, m;

	scanf("%d%d", &n, &m);

	for(int v = 2; v <= n; ++v) {
		scanf("%d", &u);
		G[u].push_back(v);
		G[v].push_back(u)
	}

	scanf("%s", (str+1));
	dfs(1);

	for(int lvl = 1; not lvlTime[lvl].empty(); ++lvl) {
		for(int i = 0; i < lvlTime[i].size(); ++i) {
			for(int j = 0; j < 26; ++j)
				cnt[i][j] = cnt[i-1][j];
			++cnt[i][str[timeNode[lvlTime[lvl][i]]] - 'a'];
		}
	}

	int v, l;
	while(m--) {
		scanf("%d%d", &v, &l);

		if(lvlTime[l].empty()) {
			printf("No\n");
			continue;
		}

		int st = startTime[v], ed = endTime[v];
		auto l = lower_bound(lvlTime[l].begin(), lvlTime[l].end(), st);
		auto r = upper_bound(lvlTime[l].begin(), lvlTime[l].end(), ed);

		if(r == lvlTime[l].end() or l == r) {
			printf("No\n");
			continue;
		}

		st = (l - lvlTime[l].begin());
		ed = (r - lvlTime[l].begin()) - 1;

		int ansCnt[26];
		for(int i = 0; i < 26; ++i)
			ansCnt[i] = cnt[l][ed][i] - cnt[l][st > 0 ? st-1:0][st];

		int len = ed-st+1;
	}

	return 0;
}