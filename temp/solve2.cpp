// UVa
// 10806 - Dijkstra, Dijkstra.
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=1747&mosmsg=Submission+received+with+ID+21754582

#include <bits/stdc++.h>
using namespace std;
#define MAX                 110
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

vi G[MAX];
int cost[MAX][MAX], cap[MAX][MAX], dist[MAX], parent[MAX];
bitset<MAX>vis;

bool Dikjstra(int src, int sink) {
	queue<int>q;
	for(int i = 0; i < MAX; ++i) 
		dist[i] = INT_MAX;
	vis.reset();
	q.push(src);
	vis[src] = 1, dist[src] = 0;					// dist[u] : contains minimum cost
	while(!q.empty()) {
		int u = q.front();
		q.pop(), vis[u] = 0;						// node u is processed and poped out, so set vis = 0
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i], w = dist[u] + cost[u][v];
			if(cap[u][v] > 0 and dist[v] > w) {		// if capacity exists and can minimize cost
				dist[v] = w;
				parent[v] = u;
				if(not vis[v])						// check if node v is not inserted in queue
					q.push(v), vis[v] = 1;			// this check is because we might insert same node twice
	}}}
	return dist[sink] != INT_MAX;
}

int MinCostFlow(int src, int sink, int &max_flow) {		// Returns min cost and max flow
	int flow, min_cost = 0;
	max_flow = 0;
	while(Dikjstra(src, sink)) {						// Max flow does bfs
		flow = INT_MAX;
		for(int v = sink; v != src; v = parent[v]) {
			int u = parent[v];
			flow = min(flow, cap[u][v]);
		}
		for(int v = sink; v != src; v = parent[v]) {
			int u = parent[v];
			cap[u][v] -= flow, cap[v][u] += flow;
			cost[v][u] = -cost[v][u];					// Extra part of MaxFlow
		}
		min_cost += dist[sink]*flow, max_flow += flow;	// cost of this flow = total_cost * actual_flow
	}
	return min_cost;
}

void AddEdge(int u, int v, int _capacity, int _cost) {		// Assuming undirected graph
	G[u].push_back(v), G[v].push_back(u);					//
	cost[u][v] = cost[v][u] = _cost;						// Cost of edge u-v
	cap[u][v] = cap[v][u] = _capacity;						// Capacity of edfe u-v
}
	
int main() {
	int n, u, v, cst, flow, E;
	while(sf("%d", &n) and n) {
		sf("%d", &E);
		int src = 0, sink = n+1;
		while(E--) {
			sf("%d%d%d", &u, &v, &cst);
			AddEdge(u, v, 1, cst);
		}
		AddEdge(src, 1, 2, 0);
		AddEdge(n, sink, 2, 0);
		cst = MinCostFlow(src, sink, flow);
		
		if(cap[1][src] != 4)
			pf("Back to jail\n");
		else
			pf("%d\n", cst);
		//cout << cst << " " << flow << " " << cap[1][0] << endl;
		
		for(int i = 0; i <= n; ++i) G[i].clear();
		memset(cost, 0, sizeof cost);
		memset(cap, 0, sizeof cap);
	}
	return 0;
}


/*

4
6
1 2 1
1 3 10
1 4 100
2 4 10
2 3 1
3 4 1

*/
