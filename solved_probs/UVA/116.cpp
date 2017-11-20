// UVa
// 116 - Unidirectional TSP

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e7
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define Equal(a, b) (abs(a-b) < EPS)
#define Greater(a, b) (a >= (b+EPS))
#define GreaterEqual(a, b) (a > (b-EPS)) 
#define fr(i, a, b) for(register int i = (a); i < (int)(b); i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari) cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;

int n, m, G[12][105], path[105];
ll dp[12][105];

vector<pii> canGo(int x, int y) {
	vii v;
	if(y+1 >= m)
		return v;
	v.pb(mp(x, y+1));
	if(x == 0)
		v.pb(mp(n-1, y+1));
	else
		v.pb(mp(x-1, y+1));
	if(x == n-1)
		v.pb(mp(0, y+1));
	else
		v.pb(mp(x+1, y+1));
	return v;
}

ll recur(int x, int y) {
	if(y >= m-1)
		return dp[x][y] = G[x][y];
	
	if(dp[x][y] != INF)
		return dp[x][y];
	
	vii v = canGo(x, y);
	ll ans = INF;
	
	for(int i = 0; i < (int)v.size(); ++i) {
		ll dist = recur(v[i].fi, v[i].se)+G[x][y];
		ans = min(dist, ans);
	}
	
	return dp[x][y] = ans;
}

void pathFinder(int x, int y) {
	if(y >= m-1) {
		path[y+1] = x;
		return;
	}
	
	vii v = canGo(x, y);
	if(v.size() == 0) return;
	
	vi dist;
	for(int i = 0; i < (int)v.size(); ++i)
		dist.pb(dp[v[i].fi][v[i].se]);
	
	sort(v.begin(), v.end());	
	sort(dist.begin(), dist.end());
	
	int Min = dist[0];
	for(int i = 0; i < (int)v.size(); ++i) {
		if(dp[v[i].fi][v[i].se] == Min) {
			path[y+1] = v[i].fi;
			pathFinder(v[i].fi, v[i].se);
			return;
		}
	}
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	while(scanf("%d %d", &n, &m) == 2) {
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%d", &G[i][j]);
		
		ll ans = INF;
		
		for(int k = 0; k < n; ++k) {
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < m; ++j)
					dp[i][j] = INF;
			ll dist = recur(k, 0);
			if(ans > dist) {
				path[0] = k;
				ans = dist;
				pathFinder(k, 0);
			}
				
		}
		
		printf("%d", path[0]+1);
		for(int i = 1; i < m; ++i)
			printf(" %d", path[i]+1);
		printf("\n%lld\n", ans);
	}
	return 0;
}
		
		
