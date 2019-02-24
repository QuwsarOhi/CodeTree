// LightOJ
// 1153 - Internet Bandwidth
// Max-Flow

#include <bits/stdc++.h>
#define MAX 102
#define INF 10000000000000
using namespace std;
typedef long long ll;

vector<int> G[MAX];
ll rG[MAX][MAX], vis[MAX], parent[MAX];
set<pair<int, int>> Edge;

bool bfs(int s, int d) {                // augment path : source, destination
    memset(parent, -1, sizeof parent);
    memset(vis, 0, sizeof vis);
    queue<int>q;
    q.push(s);
    vis[s] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); ++i) {
        	int v = G[u][i];
            if(vis[v] == 0 && rG[u][v] > 0) {                
                parent[v] = u, vis[v] = 1;
                if(v == d) return 1;
                q.push(v);
        }
    }}
    return 0;
}

ll maxFlow(int s, int d) {             // source, destination
    ll max_flow = 0;
    while(bfs(s, d)) {
        ll flow = INF;
        for(int v = d; v != s; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, rG[u][v]);
        }
        for(int v = d; v != s; v = parent[v]) {
            int u = parent[v];
            rG[u][v] -= flow;
            rG[v][u] += flow;
        }
        max_flow += flow;
    }
    return max_flow;
}

int main() {
	int t, u, v, V, E, w, s, d;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d %d %d", &V, &s, &d, &E);

		memset(rG, 0, sizeof rG);
		for(int i = 0; i < MAX; ++i)
			G[i].clear();
		Edge.clear();

		for(int i = 0; i < E; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			if(u > v) swap(u, v);

			if(Edge.find(make_pair(u, v)) == Edge.end()) {
				G[u].push_back(v);
				G[v].push_back(u);
				Edge.insert(make_pair(u, v));
			}
			rG[u][v] += w, rG[v][u] += w;
		}

		printf("Case %d: %lld\n", Case, maxFlow(s, d));
	}

	return 0;
}

/*

1

4
1 4 6
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
2 3 5

*/