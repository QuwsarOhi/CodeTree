// Directed Minimum Spanning Tree (Edmonds' algorithm)
// Complexity : O(E*V) ~ O(E + VlogV)                           [ works in O(E + VlogV) for almost all cases ]
// https://en.wikipedia.org/wiki/Edmonds%27_algorithm

// LightOJ
// 1380 - Teleport

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;

struct edge {
    int u, v, w;
    edge() {}
    edge(int a,int b,int c) : u(a), v(b), w(c) {}
};

int DMST(vector<edge> &edges, int root, int V) {
    int ans = 0;
    int cur_nodes = V;
    while(1) {
        vector<int> lo(cur_nodes, INF), pi(cur_nodes, INF);     // lo[v] : contains minimum weight to go to node v              (for an edge u -> v)
                                                                // pi[v] : contains the minimum weight edge's starting node u
        for(int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if(w < lo[v] and u != v)
                lo[v] = w, pi[v] = u;
        }

        lo[root] = 0;                                           // by default the weight to go to root node is 0
        for(int i = 0; i < (int)lo.size(); ++i) {
            if(i == root) continue;
            if(lo[i] == INF) return -1;                         // if there is no way to visit a node v, then Directed MST doesn't exist
        }
        
        int cur_id = 0;
        vector<int> id(cur_nodes, -1), mark(cur_nodes, -1);
        
        for(int i = 0; i < cur_nodes; ++i) {
            ans += lo[i];                                       // adding node i's minimum weight to answer
            
            int u;
            for(u = i; u != root && id[u] < 0 && mark[u] != i; u = pi[u])       // marking minimum weighted path from root to node i
                mark[u] = i;
        
            if(u != root && id[u] < 0) {                            // Contains cycle, as a result u can not reach to i
                for(int v = pi[u]; v != u; v = pi[v])               // mark all cycle nodes with id
                    id[v] = cur_id;
                id[u] = cur_id++;                                   // ??
        }}

        if(cur_id == 0) break;                                      // there is no cycle, so all node is possibly visited
        for(int i = 0; i < cur_nodes; ++i)
            if(id[i] < 0) id[i] = cur_id++;

        for(int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i].u, v = edges[i].v;
            edges[i].u = id[u];
            edges[i].v = id[v];
            if(id[u] != id[v]) edges[i].w -= lo[v];
        }
        
        cur_nodes = cur_id;
        root = id[root];
    }
    return ans;
}

vector<edge>edges;

int main() {
    int t, V, E, w, u, v, Root;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d", &V, &E, &Root);
        
        for(int i = 0; i < E; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            edges.push_back(edge(u, v, w));
        }
        
        long long ans = DMST(edges, Root, V);
        printf("Case %d: ", Case);
        if(ans != -1) printf("%lld\n", ans);
        else printf("impossible\n");
        edges.clear();
    }
    return 0;
}
