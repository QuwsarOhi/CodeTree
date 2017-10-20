// LightOJ
// 1149 - Factors and Multiples

#include <bits/stdc++.h>
using namespace std;

bitset<210>vis;
int lft[210], rht[210];
vector<int>G[210], v1, v2;

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

void BuildGraph(int n1, int n2) {
	for(int i = 0; i < n1; ++i)
		for(int j = 0; j < n2; ++j)
			if(v2[j] % v1[i] == 0) {
				G[i+1].push_back(j+1+n1);
				G[j+1+n1].push_back(i+1);
			}
}

int main() {
	int t, cnt, n1, n2, x;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n1);
		cnt = 0;
		
		for(int i = 1; i <= n1; ++i) {
			scanf("%d", &x);
			v1.push_back(x);
		}
		
		scanf("%d", &n2);
		
		for(int i = 1; i <= n2; ++i) {
			scanf("%d", &x);
			v2.push_back(x);
		}
		
		BuildGraph(n1, n2);
		
		memset(lft, -1, sizeof lft);
		memset(rht, -1, sizeof rht);
		
		for(int i = n1+1; i <= n1+n2; ++i) {
			vis.reset();
			cnt += VertexCover(i);
		}
		
		printf("Case %d: %d\n", Case, cnt);
		
		v1.clear();
		v2.clear();
		for(int i = 0; i <= n1+n2; ++i)
			G[i].clear();
	}
	
	return 0;
}
