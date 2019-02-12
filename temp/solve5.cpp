#include <bits/stdc++.h>
#define MAX 310000
//#define LIM 101000
#define LIM 1
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;

const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;
const ll p1 = 31;

char str[MAX];
vector<int> G[MAX];
int par[MAX][21], lvl[MAX];
ll Power[MAX], rPower[MAX], up[MAX], down[MAX];


void PowerGen() {
    Power[0] = rPower[0] = 1;

    //ll p1 = 31, p2 = 51;
    // mod inv : 129032259, 686274516
    
    ll rp1 = 129032259;
    for(int i = 1; i < MAX; ++i) {
        Power[i] = (Power[i-1] * p1) % mod1;
        rPower[i] = (rPower[i-1] * rp1) % mod1;
    }
}

/*
up[u] 	: hash from u to root node
down[u] : hash from root node to u (according to level) 

**hash power starts from 1

*/

void dfs(int u, int p = 0) {
	int h = str[u-1]-'a'+1;
	lvl[u] = lvl[p]+1;
	par[u][0] = p;

	up[u] = (h*p1 + (up[p] * p1)%mod1)%mod1;
	down[u] = (down[p] + (h*Power[lvl[u]])%mod1)%mod1;

	for(int i = 1; i <= 20; ++i)
		par[u][i] = par[par[u][i-1]][i-1];

	for(auto v : G[u])
		if(v != p)
			dfs(v, u);
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

    if(lca == v) {
        for(int i = 20; i >= 0; --i)
            if(k - (1 << i) >= 1)
                u = par[u][i], k -= (1 << i);
        return u;
    }

    if(lca == u) {
        k = rhtChain+1-k;
        for(int i = 20; i >= 0; --i)
            if(k - (1 << i) >= 0)
                v = par[v][i], k -= (1 << i);
        return v;
    }

	if(k > lftChain) {
		k -= lftChain;
		k = rhtChain - k;
		for(int i = 20; i >= 0; --i)
			if(k - (1 << i) >= 0)
				v = par[v][i], k -= (1 << i);
		return v;
	}

	for(int i = 20; i >= 0; --i)
		if(k - (1 << i) >= 1)
			u = par[u][i], k -= (1 << i);
	return u;
}

ll getPathHash(int u, int v, int lca, int k) {
	//cerr << "pathHash " << u << " " << v << " " << lca << " " << k << endl;
	if(k == 1)
		return str[u-1];

	if(v == lca) {
		v = getKthNode(u, v, k, lca);
		return (up[u] - (up[par[v][0]] * Power[lvl[u]-lvl[par[v][0]]])%mod1 + mod1)%mod1;
	}
	if(u == lca) {
		v = getKthNode(u, v, k, lca);
		ll h = (down[v] - down[lvl[lca]-1] + mod1)%mod1;
		h = (h * rPower[par[lca][0]])%mod1;
		return h;
	}

	int d = lvl[u] - lvl[lca] + 1;
	
	if(d >= k) {
		v = getKthNode(u, v, k, lca);
		return (up[u] - (up[par[v][0]] * Power[lvl[u]-lvl[par[v][0]]])%mod1 + mod1)%mod1;
	}

	// v is on right side
	v = getKthNode(u, v, k, lca);
	ll lft = (up[u] - (up[par[lca][0]] * Power[lvl[u]-lvl[par[lca][0]]])%mod1 + mod1)%mod1;
	ll rht = (down[v] - down[lca] + mod1)%mod1;
	int l = lvl[lca]+1;

	if(l > d+1)
		rht = (rht * rPower[l-d-1])%mod1;
	else if(l < d+1)
		rht = (rht * Power[d-l+1])%mod1;

	return (lft + rht)%mod1;
}


int solve(int a, int b, int c, int d) {
	int lcaAB = LCA(a, b);
	int lcaCD = LCA(c, d);
	int lo = 1, hi = min(lvl[a] + lvl[b] - 2*lvl[lcaAB] + 1, lvl[c] + lvl[d] - 2*lvl[lcaCD] + 1), mid, ret = 0;

	while(lo <= hi) {
		mid = (lo + hi) >> 1;

		//cerr << "mid " << mid << endl;
		if(getPathHash(a, b, lcaAB, mid) == getPathHash(c, d, lcaCD, mid))
			ret = mid, lo = mid + 1;//, cerr << "match\n";
		else
			hi = mid - 1;
	}
	return ret;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	int n, a, b, c, d, q, u, v;
	scanf("%d%s", &n, str);

	for(int i = 1; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	PowerGen();
	dfs(1);

	cin >> q;
	while(q--) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", solve(a, b, c, d));
	}

	return 0;
}