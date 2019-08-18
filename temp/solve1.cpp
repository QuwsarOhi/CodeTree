#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

ll dist[1002], G[1002][1002], V, E, e;
set<ll> par[1002];

bool dikjstra(ll s, ll t) {
	queue<pair<ll, ll>> pq;
	for(int i = 1; i <= V; ++i)
		dist[i] = INF;
	pq.push({0, -s});
	dist[s] = 0;

	while(not pq.empty()) {
		ll u = -pq.front().second;
		ll c = -pq.front().first;
		pq.pop();
		cerr << "AT " << u << " " << c << endl;

		if(u == t)
			return 1;
		if(c > dist[u])
			continue;

		for(int v = 1; v <= V; ++v) {
			if(G[u][v] == INF)
				continue;
			ll nc = c + G[u][v];			
			if(nc <= dist[v]) {
				cerr << "TO " << v << " " << nc << endl;
				dist[v] = nc;
				pq.push({-nc, -v});
				par[v].insert(u);
			}
		}
	}
	return 0;
}

bool path(int at, int ed) {
	if(at == ed) {
		cout << ed;
		return 1;
	}

	for(auto v : par[at]) {
		if(path(v, at)) {
			cout << " " << v;
			return 1;
		}
	}
	return 0;
}

int main() {
	ll t, u, v, w, typ, q;
	cin >> t;

	for(int Case = 1; Case <= t; ++Case) {
		cin >> V >> E >> e;

		memset(G, INF, sizeof G);
		for(int i = 0; i < E; ++i) {
			cin >> u >> v >> w;
			G[u][v] = G[v][u] = w;
		}

		cin >> q;
		cout << "Case " << Case << ":\n";
		while(q--) {
			cin >> typ >> u;

			if(typ == 0) {
				cin >> v;
				G[u][v] = G[v][u] = INF;
			}
			else {
				cerr << "START\n";
				if(not dikjstra(u, e)) {
					cout << "Bad Luck, Mr. Parker.\n";
				}
				else {
					path(e, u);
					cout << "\n";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}


/*

1
6 7 6
1 2 1
2 3 1
3 4 1
1 4 3
4 6 2
3 6 2
1 6 5


9
1 1
0 3 6
1 1
0 1 6
1 1
0 2 3
1 1
0 1 4
1 1

*/