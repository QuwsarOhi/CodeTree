// Codeforces
// B. Bakery
// http://codeforces.com/contest/707/problem/B

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define ull unsigned long long
#define ll long long
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define msi map<string, int>
#define mii map<int, int>
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pair<int, int> >
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int>G[100010], W[100010];
bitset<100010>flour;

int main() {
	int n, m, k, u, v, w, ans = INF;
	
	sf("%d%d%d", &n, &m, &k);
	
	fr(i, 0, m) {
		sf("%d%d%d", &u, &v, &w);
		G[u].pb(v);
		G[v].pb(u);
		W[v].pb(w);
		W[u].pb(w);
	}
	
	flour.reset();
	fr(i, 0, k) {
		sf("%d", &u);
		flour[u] = 1;
	}
	
	fr(u, 1, n+1) {
		fr(j, 0, (int)G[u].size()) {
			v = G[u][j];
			if(flour[u] && !flour[v]) {
				ans = min(ans, W[u][j]);
			}
		}
	}
	
	
	if(ans == INF)
		ans = -1;
	
	pf("%d\n", ans);
	
	return 0;
}
