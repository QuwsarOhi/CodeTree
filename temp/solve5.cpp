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


bool DikjstraDist(int s, int t, double distLim, double &ret) {
	queue<int>q;
	for(int i = 0; i < MAX; ++i) dist[i] = INF;
	dist[s] = 0;
	q.push(s);
	while(not q.empty()) {
		int u = q.front();
		q.pop();
		if(u == t) {
			ret = dist[t];
			return 1;
		}
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			double w = W[u][i] + dist[u];
			if(w < dist[v] and w <= distLim and R[u][i] <= tt) {
				dist[v] = w;
				parent[v] = u;
				q.push(v);
	}}}
	return 0;
}

int lastPar[MAX];
double binarySearch(double low, double hi, int s, int t) {
	double mid, ret, bs;
	for(int i = 0; i < 35; ++i) {
		mid = (low+hi)/2;
		if(DikjstraDist(s, t, mid, bs)) {
			for(int i = 0; i < MAX; ++i)
				lastPar[i] = parent[i];
			ret = bs;
			hi = mid;
		}
		else low = mid;
	}
	return ret;
}

void pathPrint(int s, int t) {
	if(s == t) {
		pf("%d", s);
		return;
	}
	pathPrint(s, lastPar[t]);
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
			//cerr << u << " " << v << " " << r << " " << d << endl;
		}

		
		tt = DikjstraTemp(s, t);
		double dd = binarySearch(0, tot, s, t);
		
		//cerr << "TEMP : " << tt  << " DIST : " << dd << endl;
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

*/
