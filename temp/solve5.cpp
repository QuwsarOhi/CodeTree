#include <bits/stdc++.h>
#define MAX 110000
#define LIM 101000
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;

string str;
vector<int> G[MAX];
int par[MAX][21], lvl[MAX];
pll Hash[MAX][21], Power[LIM];


void PowerGen() {
    Power[0] = {1, 1};
    for(int i = 1; i < LIM; ++i) {
        Power[i].first = (Power[i-1].first * 31LL)%mod1;
        Power[i].second = (Power[i-1].second * 51LL)%mod2;
}}

void dfs(int u, int p = 0) {
	lvl[u] = lvl[p]+1;
	cerr << u << " :: " << lvl[u] << endl;
	par[u][0] = p;
	Hash[u][0].first = Hash[u][0].second = str[u-1] - 'a' + 1;

	for(int i = 1; i <= 20; ++i) {
		par[u][i] = par[par[u][i-1]][i-1];
		Hash[u][i].first = (Hash[u][i-1].first + (Hash[par[u][i-1]][i-1].first * Power[i].first) % mod1) % mod1;
		Hash[u][i].second = (Hash[u][i-1].second + (Hash[par[u][i-1]][i-1].second * Power[i].second) % mod2) % mod2;
	}

	for(auto v : G[u])
		if(v != p)
			dfs(v, u);
}

pll getHash(int u, int v) {
	pll h = {0, 0};
	if(lvl[u] < lvl[v]) {
		for(int i = 20; i >= 0; --i)
			if(lvl[v] - (1 << i) >= lvl[u]) {
				h.first = (h.first + (Hash[v][i].first * Power[LIM].first)%mod1)%mod1;
				h.second = (h.second + (Hash[v][i].second * Power[LIM].second)%mod2)%mod2;
				v = par[v][i];
			}
	}
	else if(lvl[v] < lvl[u]) {
		for(int i = 20; i >= 0; --i)
			if(lvl[u] - (1 << i) >= lvl[v]) {
				h.first = (h.first + Hash[u][i].first)%mod1;
				h.second = (h.second + Hash[u][i].second)%mod2;
				u = par[u][i];
			}
	}

	if(u == v)
		return h;

	for(int i = 20; i >= 0; --i)
		if(par[u][i] != par[v][i]) {
			h.first = (h.first + Hash[u][i].first)%mod1;
			h.second = (h.second + Hash[u][i].second)%mod2;
			h.first = (h.first + (Hash[v][i].first * Power[LIM].first)%mod1)%mod1;
			h.second = (h.second + (Hash[v][i].second * Power[LIM].second)%mod2)%mod2;
			u = par[u][i], v = par[v][i];
		}

	h.first = (h.first + Hash[u][0].first)%mod1;
	h.second = (h.second + Hash[u][0].second)%mod2;
	return h;
}

int LCA(int u, int v) {
	if(lvl[u] < lvl[v]) swap(u, v);

	for(int i = 20; i >= 0; --i)
		if(lvl[u] - (1 << i) >= lvl[v])
			u = par[u][i];

	if(u == v) return u;

	for(int i = 20; i >= 0; --i)
		if(par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];

	return par[u][0];
}

int getKthNode(int u, int v, int k, int lca) {
	int lftChain = lvl[u] - lvl[lca] + 1;
	int rhtChain = lvl[v] - lvl[lca];

	if(k == 1) return u;

	if(k > lftChain) {
		k -= lftChain;
		k = rhtChain - k;
		for(int i = 20; i >= 0; --i)
			if(k - (1 << i) >= 1)
				v = par[v][i];
		return v;
	}

	for(int i = 20; i >= 0; --i)
		if(k - (1 << i) >= 1)
			u = par[u][i];
	return u;
}

int solve(int a, int b, int c, int d) {
	int lcaAB = LCA(a, b);
	int lcaCD = LCA(c, d);
	int lo = 1, hi = min(lvl[a] + lvl[b] - 2*lvl[lcaAB] + 1, lvl[c] + lvl[d] - 2*lvl[lcaCD] + 1), mid, ret = 0;

	cerr << "q " << a << " " << b << " " << c << " " << d << endl; //<< " " << hi << " " << lcaAB << " " << lcaCD << endl;
	//cerr << lvl[a] + lvl[b] - lvl[lcaAB] + 1 << " " <<  lvl[c] + lvl[d] - lvl[lcaCD] + 1 << endl;
	while(lo <= hi) {
		mid = (lo + hi) >> 1;

		int e = getKthNode(a, b, mid, lcaAB);
		int f = getKthNode(c, d, mid, lcaCD);

		cerr << "mid " << mid << " e " << e << " f " << f << endl;  

		if(getHash(a, e) == getHash(c, f))
			ret = mid, lo = mid + 1, cerr << "match\n";
		else
			hi = mid - 1;
	}
	return ret;
}

int main() {
	int n, a, b, c, d, q, u, v;
	cin >> n >> str;

	for(int i = 1; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	PowerGen();
	dfs(1);

	cin >> q;
	while(q--) {
		cin >> a >> b >> c >> d;
		cout << solve(a, b, c, d) << "\n";
	}

	return 0;
}