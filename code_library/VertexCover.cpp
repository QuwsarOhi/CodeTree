// Vertex Cover

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


int main() {
	
	memset(lft, -1, sizeof lft);
	memset(rht, -1, sizeof rht);
	
	// Min Edge Cover = TotalNodes - MinVertexCover
	
	for(int i = 1; i <= n; ++i) { 	// n is the number of left-side nodes
		vis.reset();				// if left-side nodes are unspecified then do bicoloring
		cnt += VertexCover(i); 		// Cnt is the answer
	}

	
	return 0;
}
