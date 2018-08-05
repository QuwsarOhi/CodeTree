// LightOJ
// 1384 - Stream My Contest

// Directed Minimum Spanning Tree (Edmonds' algorithm)
// Complexity : O(E*V) ~ O(E + VlogV)                           [ works in O(E + VlogV) for almost all cases ]
// https://en.wikipedia.org/wiki/Edmonds%27_algorithm

#include <bits/stdc++.h>
#define INF 100000000
using namespace std;
typedef long long ll;

struct edge {
    ll u, v, w, b;
    edge() {}
    edge(ll a,ll b,ll c,ll d) : u(a), v(b), w(c), b(d) {}
};

ll DMST(vector<edge> edges, int root, int V, ll lim) {
    ll ans = 0;
    ll cur_nodes = V;
    while(1) {
        vector<int> lo(cur_nodes, INF), pi(cur_nodes, INF);     // lo[v] : contains minimum weight to go to node v              (for an edge u -> v)
                                                                // pi[v] : contains the minimum weight edge's starting node u
        for(int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w, b = edges[i].b;
            if(b < lim) continue;
            if(w < lo[v] && u != v)
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
    return ans;                                                     // returns total cost of MST
}

vector<edge>EDGES;

ll binarySearch(ll lo, ll hi, ll V, ll C) {
    ll ret = -1;
    while(lo <= hi) {
        ll mid = (lo+hi)/2;
        ll cst = DMST(EDGES, 0, V, mid);

        if(cst == -1 || cst > C)
            hi = mid-1;
        else {
            ret = max(mid, ret);
            lo = mid+1;
        }
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    ll V, E, u, v, b, w, C;
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld%lld", &V, &E, &C);
        EDGES.clear();
        ll LIM = 0;
        for(int i = 0; i < E; ++i) {
            scanf("%lld%lld%lld%lld", &u, &v, &b, &w);
            EDGES.push_back(edge(u, v, w, b));
            LIM = max(LIM, b);
        }
        
        ll ans = binarySearch(0, LIM+10, V, C);

        printf("Case %d: ", Case);
        if(ans == -1)
            printf("impossible\n");
        else
            printf("%lld kbps\n", ans);

    }
    
    return 0;
}
