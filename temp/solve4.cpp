#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
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
typedef pair<double, double>pdd;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

vi G[MAX];
vector<double> R[MAX], W[MAX];
double dp[101][550];
const int offset = 20;
pii trans[101][550];
int target;
bool vis[MAX];

double recur(int u, double r, double d) {
	int rr = r*10.0;
	if(rr < 0) rr = 0;
	double &ret = dp[u][rr];
	vis[u] = 1;
	
	cerr << u << " " << r << " " << d << " " << rr << " " << endl;
	getchar();
	// ADD BASIS
	if(u == target) {
		cerr << "GOT " << r << " " << d << endl;
		if(ret == 0) ret = d;
		else ret = min(ret, d);
		vis[u] = 0;
		return ret;
	}
	
	if(ret != 0) {
		cerr << "HIT at " << u << endl;
		vis[u] = 0;
		return ret;
	}
	
	ret = INF;
	for(int i = 0; i < (int)G[u].size(); ++i) {
		if(vis[G[u][i]]) continue;
		double tmp = recur(G[u][i], max(r, R[u][i]), d) + W[u][i];
		if(tmp < ret) {
			ret = tmp;
			int RR = max(r, R[u][i])*10.0;
			trans[G[u][i]][RR] = {u, rr};
	}}
	vis[u] = 0;
	return ret;
}


int main() {
	fileRead("in");
	fileWrite("out");
	
	int V, E, s, t, u, v;
	double d, r;
	while(sf("%d%d", &V, &E) == 2) {
		sf("%d%d", &s, &t);
		target = t;
		while(E--) {
			sf("%d%d%lf%lf", &u, &v, &r, &d);
			G[u].pb(v), G[v].pb(u);
			W[u].pb(d), W[v].pb(d);
			R[u].pb(r), R[v].pb(r);
			//cerr << u << " " << v << " " << r << " " << d << endl;
		}

		/*for(auto vv : EDGE) {
			sort(All(vv.second));
			u = vv.first;
			for(auto it : vv.second) {
				v = it.se;
				d = it.fi.fi, r = it.fi.se;
				G[u].pb(v), G[v].pb(u);
				W[u].pb(d), W[v].pb(d);
				R[u].pb(r), R[v].pb(r);
		}}*/
		
		//for(int i = 0; i < 101; ++i)
		//	for(int j = 0; j < 33; ++j)
		//		for(int k = 0; k < 43; ++k)
		//			dp[i][j][k] = {INF, INF};
		
		memset(dp, 0, sizeof dp);
		
		cerr << "DONB\n";
		double dist = recur(s, 0, 0), temp;
		for(int i = 0; i < 550; ++i)
			if(dp[t][i] == dist)
				temp = i/10.0;
		
		pf("\n%.1f %.1f\n", dist, temp);
		
		//EDGE.clear();
		for(int i = 0; i <= V; ++i)
			G[i].clear(), W[i].clear(), R[i].clear();
	}
	return 0;
}
