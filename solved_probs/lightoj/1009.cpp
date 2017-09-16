// LightOJ
// 1009 - Back to Underworld
// DFS, BFS

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
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

vi G[20010], nodes;
bitset<20000>visited;
int cnt[2];

void dfs(int u, bool k) {
	visited[u] = 1;
	++cnt[(int)k];
	fr(i, 0, G[u].size()) {
		int v = G[u][i];
		if(!visited[v])
			dfs(v, !k);
	}
}

int main() {
	
	int t, V, u, v, ans = 0;
	sf("%d", &t);
	
	fr(Case, 1, t+1) {
		ans = 0;
		sf("%d", &V);
		fr(i, 0, V) {
			sf("%d %d", &u, &v);
			G[u].pb(v);
			G[v].pb(u);
			nodes.pb(u);
			nodes.pb(v);
		}
		
		visited.reset();
		
		fr(i, 0, nodes.size()) { 
			if(!visited[nodes[i]]) {
				cnt[0] = cnt[1] = 0;
				dfs(nodes[i], 0);
				ans += max(cnt[0], cnt[1]);
			}
		}
		
		pf("Case %d: %d\n", Case, ans);
		fr(i, 0, nodes.size()) G[nodes[i]].clear();
		nodes.clear();
	}
	
	return 0;
}
