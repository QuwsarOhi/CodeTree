// LightOJ
// 1184 - Marriage Media
// Bipartite Matching

#include <bits/stdc++.h>
#define MAX 200
using namespace std;

bitset<MAX>vis;
int lft[MAX], rht[MAX];
vector<int>G[MAX];

int VertexCover(int u) {                    // Min Vertex Cover
	vis[u] = 1;
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		if(vis[v])                          // If v is used earlier, skip
			continue;
		vis[v] = 1;
        
		if(lft[v] == -1) {                  // If there is no node present on left of v
			lft[v] = u, rht[u] = v;
			return 1;
		}
		else if(VertexCover(lft[v])) {      // If there is one node present on the left side of v (Let it be u')
			lft[v] = u, rht[u] = v;         // and if it is possible to match u' with another node (not v ofcourse!)
			return 1;                       // then we can match this u with v, and u' is matched with another node as well
    }}
	return 0;
}

int BPM(int n) {                            // Bipartite Matching
    int cnt = 0;
    memset(lft, -1, sizeof lft);
    memset(rht, -1, sizeof rht);
    for(int i = 1; i <= n; ++i) {           // Nodes are numbered from 1 to n
        vis.reset();
        cnt += VertexCover(i);              // Check if there exists a match for node i
    }
    return cnt;
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, n, m;
    int mh[MAX], nh[MAX], my[MAX], ny[MAX], md[MAX], nd[MAX];
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &m, &n);
        
        for(int i = 0; i < m; ++i)
            scanf("%d%d%d", &mh[i], &my[i], &md[i]);
            
        for(int i = 0; i < n; ++i)
            scanf("%d%d%d", &nh[i], &ny[i], &nd[i]);
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(abs(mh[i]-nh[j]) > 12 || abs(my[i]-ny[j]) > 5 || md[i] != nd[j])
                    continue;
                int u = i+1, v = m+j+1;
                G[u].push_back(v);
                G[v].push_back(u);
            }
        
        printf("Case %d: %d\n", Case, BPM(m));

        int t = n+m+5;
        for(int i = 0; i < t; ++i)
            G[i].clear();
    }
    return 0;
}
