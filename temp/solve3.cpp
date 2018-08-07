#include <bits/stdc++.h>
using namespace std;
#define MAX                 550
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
vector<float> W[MAX], R[MAX];
double tmp[MAX], dist[MAX];
int parent[MAX];
map<int, vector<pair<pair<double, double>, int> > >EDGE;

pair<double, double> Dikjstra(int s, int t) {
	queue<int>q;
	for(int i = 0; i < MAX; ++i)
		dist[i] = INF, tmp[i] = INF;
	q.push(s);
	dist[s] = 0, tmp[s] = 0;
	while(not q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			double w = W[u][i], r = R[u][i];
			if(max(r, tmp[u]) < tmp[v]) {
				//if(dist[u] + w > dist[v]) {
				//	cerr << "FROM " << u << " to " << v << "bigger distance" << endl;
				//	continue;
				//}
				parent[v] = u;
				tmp[v] = max(r, tmp[u]);
				//if(tmp[u] == INF) tmp[v] = r;
				dist[v] = dist[u] + w;
				//cerr  << "FROM " << u << " to " << v << " :: " << dist[v] << ", " << tmp[v] << endl;
				q.push(v);
				TRACK[v].pb({tmp[v], dist[v], u});
			}
			//else {
			//	cerr << "SKIP " << u << " to " << v << " :: " << max(r, tmp[u]) << " but " << tmp[v] << endl;
			//}
	}}
	//cerr << tmp[t] << " " << dist[t] << endl; 
	return mp(dist[t], tmp[t]);
}

void recur(int s, int t) {
	if(s == t) {
		pf("%d", s);
		return;
	}
	recur(s, parent[t]);
	pf(" %d", t);
}

void printer(int u, int s) {
	if(u == s) {
		pf("%d ", s);
		return;
	}
	recur()

int main() {
	fileRead("in");
	fileWrite("out");
	
	int V, E, s, t, u, v;
	double d, r;
	while(sf("%d%d", &V, &E) == 2) {
		sf("%d%d", &s, &t);
		while(E--) {
			sf("%d%d%lf%lf", &u, &v, &r, &d);
			EDGE[u].pb(mp(mp(d, r), v));
			/*G[u].pb(v), G[v].pb(u);
			W[u].pb(d), W[v].pb(d);
			R[u].pb(r), R[v].pb(r);*/
			//cerr << u << " " << v << " " << r << " " << d << endl;
		}

		for(auto vv : EDGE) {
			sort(All(vv.second));
			u = vv.first;
			for(auto it : vv.second) {
				v = it.se;
				d = it.fi.fi, r = it.fi.se;
				G[u].pb(v), G[v].pb(u);
				W[u].pb(d), W[v].pb(d);
				R[u].pb(r), R[v].pb(r);
		}}
		
		pair<double, double> ans = Dikjstra(s, t);
		recur(s, t);
		pf("\n%.1f %.1f\n", ans.fi, ans.se);
		
		EDGE.clear();
		for(int i = 0; i <= V; ++i)
			G[i].clear(), W[i].clear(), R[i].clear();
	}
	return 0;
}


/*

4 4
1 4

2 4 5 30
1 3 10 40
3 4 5 30
1 2 10 20

*/
