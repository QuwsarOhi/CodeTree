//UVa
//11631 - Dark roads
//Minimum Spanning Tree (Prim's Algorithm)

#include <bits/stdc++.h>
#define MAX 200010

using namespace std;

vector<int>G[MAX], W[MAX];
bitset<MAX>taken;
priority_queue<pair<int, int> >pq;

void process(int u)
{
    taken[u] = 1;

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        int w = W[u][i];

        if(!taken[v])
            pq.push(make_pair(-w, -v));
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int V, E, u, v, w;
    while(scanf("%d %d", &V, &E) && (V || E)) {
        int total_cost = 0;
        while(E--) {
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(v);
            G[v].push_back(u);
            W[u].push_back(w);
            W[v].push_back(w);
            total_cost += w;
        }

        taken.reset();
        process(0);
        int mst_cost = 0;

        while(!pq.empty()) {
            v = -pq.top().second;
            w = -pq.top().first;
            pq.pop();

            if(!taken[v]) {
                mst_cost += w;
                process(v);
            }
        }
        printf("%d\n", total_cost - mst_cost);

        for(int i = 0; i < V; i++) {
            G[i].clear();
            W[i].clear();
        }
    }
    return 0;
}
