// UVa
// 11097 - Poor My Problem! :-(
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2038&mosmsg=Submission+received+with+ID+21780983

#include <bits/stdc++.h>
using namespace std;
#define MAX                 620
#define EPS                 1e-5
#define INF                 1e8
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

vi G[MAX], W[MAX];
int dist[MAX][1010];
bool inQueue[MAX][1010];

void bfs(int s, int V) {
	queue<pii>q;
	q.push({s, 0});
	
	for(int i = 0; i < V; ++i)
		for(int j = 0; j <= 1001; ++j)
			dist[i][j] = INF;
	dist[s][0] = 0;
	
	while(not q.empty()) {
		int u = q.front().fi, e = q.front().se;
		q.pop();
		inQueue[u][e] = 0;
		if(e == 1000) continue;
		//cerr << "AT " << u << " " << e << " edges " << G[u].size() << endl;
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i], w = W[u][i];
			if(dist[v][e+1] > dist[u][e] + w) {
				//cerr << "FROM " << u << " to " << v << " " << e << endl;
				dist[v][e+1] = dist[u][e] + w;
				if(not inQueue[v][e+1]) {
					inQueue[v][e+1] = 1;
					q.push({v, e+1});
}}}}}

int main() {
	//fileRead("in");
	//fileWrite("out");
	
	int V, E, s, u, v, w, q, t;
	while(cin >> V >> E >> s) {
		for(int i = 0; i < E; ++i) {
			cin >> u >> v >> w;
			G[u].pb(v);							// Graph is Reversed
			W[u].pb(w);
		}
		
		//cerr << "DONE\n";
		bfs(s, V);
		cin >> q;
		while(q--) {
			cin >> t;
			double ans = INF;
			int edge = -1;
			
			if(s == t) {
				ans = edge = 0;
				goto pass;
			}
			
			for(int i = 0; i <= 1000; ++i)
				if(dist[t][i] != INF) {
					if(dist[t][i] / (double)i < ans) {
						//cerr << dist[t][i] << " " << i << endl;
						ans = dist[t][i] / (double)i;
						edge = i;
				}}
			
			pass:
			if(edge == -1)
				cout << "No Path\n";
			else
				cout << fixed << setprecision(4) << ans << " " << edge << "\n";
		}
		
		for(int i = 0; i <= V; ++i) G[i].clear(), W[i].clear();
		cout << "\n";
	}
	return 0;
}


/*

11 10 3

1 3 10
2 4 1
3 5 15
5 6 1
6 7 1
7 5 1
4 5 20
5 9 3
9 10 3
5 4 10

4
2 
5
10
4

*/
