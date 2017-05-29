//UVa
//12047 - Highest Paid Toll
//Dikjstra, Interesting Variant

#include <bits/stdc++.h>
#define INF 1e7
#define MAX 10010
using namespace std;

//let u - v be the maximum edge that lies in a path in which cost is <= p
//we can't assume which one is the actual edge u - v
//we'll try to find the shortest path from source to u and also find the shortest path from v to destination
//if weight/cost of (source - u) + (u - v) + (v - destination) <= p, then u - v is the answer

vector<int> G1[MAX], W1[MAX], G2[MAX], W2[MAX];
int distSource[MAX], distDestination[MAX];

void dikjstra(int start_node, int end_node, int p, int V, int dist[], vector<int> G[], vector<int> W[])
{
	for(int i = 0; i <= V; i++)
        dist[i] = INF;
	//distance, node
	priority_queue<pair<int, int> >pq;
	pq.push({0, start_node});
	dist[start_node] = 0;

	while(!pq.empty()) {
		int u = pq.top().second;
		int _cost = -pq.top().first;
		pq.pop();

        if(_cost  > dist[u])
            continue;

		for(int i = 0; i < (int)G[u].size(); i++) {
			int v = G[u][i];
			int cost = _cost + W[u][i];

			if(cost > p) {
				continue;
			}

			if(cost < dist[v]) {
				dist[v] = cost;
				pq.push({-cost, v});
			}
		}
	}
}

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	int V, E, start, end, p, t, w, u, v;

	scanf("%d", &t);
	while(t--) {
        priority_queue<pair<int, pair<int, int > > >edges;
		scanf("%d %d %d %d %d", &V, &E, &start, &end, &p);

		while(E--) {
			scanf("%d %d %d", &u, &v, &w);
			G1[u].push_back(v);
			W1[u].push_back(w);
			G2[v].push_back(u);
			W2[v].push_back(w);
			edges.push({w, {u, v}});
		}

		bool found  = 0;

		dikjstra(start, end, p, V, distSource, G1, W1);
        dikjstra(end, start, p, V, distDestination, G2, W2);

        while(!edges.empty()) {
            u = edges.top().second.first;
            v = edges.top().second.second;
            w = edges.top().first;

            edges.pop();

            if(distSource[u] + w + distDestination[v] <= p) {
                printf("%d\n", w);
                found = 1;
                break;
            }
        }

		if(!found)
            printf("-1\n");

		for(int i = 0; i <= V; i++) {
			G1[i].clear();
			W1[i].clear();
			G2[i].clear();
			W2[i].clear();
		}
	}
	return 0;
}
