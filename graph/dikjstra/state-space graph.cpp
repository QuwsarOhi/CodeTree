//UVa
//11367 - Full Tank?
//Shortest Path (Dikjstra) State-Space graph

#include <bits/stdc++.h>
#define INF 1e6
using namespace std;

int cost[1005][105], V, E, price[1005];
vector<int>G[1005], W[1005];

int dikjstra(int start_node, int end_node, int gas_capacity)
{
    for(int i = 0; i <= V; i++)
        for(int j = 0; j <= 100; j++)
            cost[i][j] = INF;

    //total_cost, gas, node
    priority_queue<pair<int, pair<int, int> > >pq;
    //node, gas
    cost[start_node][0] = 0;
    //at starting city, cost and gas is zero
    pq.push(make_pair(0, make_pair(0, -start_node)));

    while(!pq.empty()) {
        int cost_u = -pq.top().first;
        int gas = -pq.top().second.first;
        int u = -pq.top().second.second;
        pq.pop();

        if(u == end_node)
            return cost_u;

        if(cost[u][gas] < cost_u)
            continue;

        //taking 1 gallon of gas if possible
        if(gas < gas_capacity) {
            int new_cost = cost_u + price[u];
            if(new_cost < cost[u][gas+1]) {
                cost[u][gas+1] = new_cost;
                pq.push(make_pair(-new_cost, make_pair(-(gas+1), -u)));
            }
        }

        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            int w = W[u][i];

            if(w <= gas) {
                int gas_left = gas - w;
                if(cost_u < cost[v][gas_left]) {
                    cost[v][gas_left] = cost_u;
                    pq.push(make_pair(-cost_u, make_pair(-gas_left, -v)));
                }
            }
        }
    }
    return -1;
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int u, v, w, q, container_capacity, start_city, end_city;
    while(scanf("%d %d", &V, &E) != EOF) {
        for(int i = 0; i < V; i++)
            scanf("%d", &price[i]);
        for(int i = 0; i < E; i++) {
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(v);
            G[v].push_back(u);
            W[u].push_back(w);
            W[v].push_back(w);
        }
        scanf("%d", &q);
        while(q--) {
            scanf("%d %d %d", &container_capacity, &start_city, &end_city);
            int ans = dikjstra(start_city, end_city, container_capacity);
            if(ans == -1)
                printf("impossible\n");
            else
                printf("%d\n", ans);
        }

        for(int i = 0; i < V; i++) {
            G[i].clear();
            W[i].clear();
        }
    }
    return 0;
}
