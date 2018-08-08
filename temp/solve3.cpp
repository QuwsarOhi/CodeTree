// UVa
// 10816 - Travel in Desert
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1757&mosmsg=Submission+received+with+ID+21762892

#include <bits/stdc++.h>
using namespace std;
#define MAX                 120
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
vector<double> R[MAX], W[MAX];
double tt;
double temp[MAX], dist[MAX];
int parent[MAX];

double DikjstraTemp(int s, int t) {
	queue<int>q;
	for(int i = 0; i < MAX; ++i) temp[i] = INF;
	q.push(s);
	temp[s] = 0;
	while(not q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			double r = R[u][i];
			if(temp[v] > max(r, temp[u])) {
				temp[v] = max(r, temp[u]);
				q.push(v);
	}}}
	return temp[t];
}


double DikjstraDist(int s, int t, double distLim) {
	double ret = distLim;
	queue<int>q;
	for(int i = 0; i < MAX; ++i) dist[i] = INF;
	dist[s] = 0;
	q.push(s);
	while(not q.empty()) {
		int u = q.front();
		q.pop();
		//cerr << "AT " << u << endl;
		if(u == t) {
			ret = min(ret, dist[t]);
			continue;
		}
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			double w = W[u][i] + dist[u];
			if(w < dist[v] and w <= distLim and R[u][i] <= tt) {
				//cerr << "FROM " << u << " to " << v << endl;
				dist[v] = w;
				parent[v] = u;
				q.push(v);
	}}}
	return ret;
}

int lastPar[MAX];

void pathPrint(int s, int t) {
	if(s == t) {
		pf("%d", s);
		return;
	}
	pathPrint(s, parent[t]);
	printf(" %d", t);
}

int main() {
	//fileRead("in");
	//fileWrite("out");
	
	int V, E, s, t, u, v;
	double d, r, tot;
	while(sf("%d%d", &V, &E) == 2) {
		sf("%d%d", &s, &t);
		tot = 0;
		while(E--) {
			sf("%d%d%lf%lf", &u, &v, &r, &d);
			G[u].pb(v), G[v].pb(u);
			W[u].pb(d), W[v].pb(d);
			R[u].pb(r), R[v].pb(r);
			tot += d;
		}

		double dd;
		tt = DikjstraTemp(s, t);
		dd = DikjstraDist(s, t, tot);
		pathPrint(s, t);
		pf("\n%.1f %.1f\n", dd, tt);
		
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

8 12
1 4
1 2 10 1
1 5 10 3
1 7 10 3
2 3 20 2
5 6 10 2
7 8 10 1
3 4 10 3
6 4 10 2
8 4 10 2
3 4 10 1
5 6 10 2
8 4 10 1

5 5
1 3
1 2 10 5
2 3 10 1
1 4 10 3
4 5 10 1
5 3 10 1

*/
