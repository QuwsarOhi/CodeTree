// UVa
// 11138 - Nuts and Bolts

#include <bits/stdc++.h>
using namespace std;

bitset<1010>vis;
int lft[1010], rht[1010];
vector<int>G[1010];

bool VertexCover(int u) {
	vis[u] = 1;
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		if(vis[v])
			continue;
		vis[v] = 1;
		
		if(lft[v] == -1) {
			lft[v] = u;
			rht[u] = v;
			return 1;
		}
		
		else if(VertexCover(lft[v])) {
			lft[v] = u;
			rht[u] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, nuts, bolts, x;
	
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &nuts, &bolts);
		
		int lm = nuts+bolts, cnt = 0;
		
		for(int i = 1; i <= nuts; ++i) {
			for(int j = nuts+1; j <= lm; ++j) {
				scanf("%d", &x);
				if(x) {
					G[i].push_back(j);
					G[j].push_back(i);
					//cout << i << " --- " << j << endl;
				}
			}
		}
		
		//cout << "input done" << endl;
		
		memset(lft, -1, sizeof lft);
		memset(rht, -1, sizeof rht);
		
		for(int i = 1; i <= nuts; ++i) {
			vis.reset();
			cnt += VertexCover(i);
		}
		//cout << "done\n";
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", Case, cnt);
		
		for(int i = 0; i <= lm; ++i)
			G[i].clear();
	}
	
	return 0;
}
		
