#include <bits/stdc++.h>
#define MAX 101000
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll Power[LIM];
void PowerGen() {
    Power[0] = {1, 1};
    for(int i = 1; i < LIM; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
}}

pll hash[MAX];
void doubleHash(char *s, int len) {      // Returns Double Hash vector for a full string
    ll hashVal1 = 0, hashVal2 = 0;
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[idxToNode[i]-1] - 'a' + 1)* Power[i].fi)%mod1;
        hashVal2 = (hashVal2 + (s[idxToNode[i]-1] - 'a' + 1)* Power[i].se)%mod2;
        hash[i].first = hashVal1, hash[i].second = hashVal2;
}}

pll SubHash(int l, int r, int idx) {    // Produce SubString Hash
    pll H;
    l = nodeToIdx[l], r = nodeToIdx[r];
    H.fi = (Hash[r].fi - (l-1 >= 1 ? Hash[l-1].fi:0) + mod1)%mod1;
    H.se = (Hash[r].se - (l-1 >= 1 ? Hash[l-1].se:0) + mod2)%mod2;
    H.fi = (H.fi * Power[LIM-l-idx].fi)%mod1;
    H.se = (H.se * Power[LIM-l-idx].se)%mod2;
    return H;
}

void dfs(int u, int p = 0) {
	lvl[u] += lvl[p]+1;
	ChainSize[u] = 1;
	NextNode[u] = 0;
	par[u][0] = p;

	for(int i = 1; i <= 20; ++i)
		par[u][i] = par[par[u][i-1]]par[i-1];

	for(auto v : G[u]) {
		if(v == p) continue;
		dfs(v, u);
		if(NextNode[u] == 0 or ChainSize[NextNode[u]] < ChainSize[v])
			NextNode[u] = v;
	}
	ChainSize[u] += ChainSize[NextNode[u]];
}

void HLD(int u, int par) {
	if(ChainSize[ChainCnt] == 0)
		ChainTop[ChainCnt] = u;
	
	nodeToIdx[u] = ++NodeCnt;
	idxToNode[NodeCnt] = u;
	ChainNo[u] = ChainCnt;
	++ChainSize[u];

	if(NextNode[u])
		HLD(NextNode[u], u);

	for(auto v : G[u]) {
		if(v == NextNode[u]) continue;
		++ChainCnt;
		HLD(v, u);
}}

ll GetHash(int u, int v, int lca) {
	int len = lvl[u] + lvl[v] - 2*lvl[lca] + (u == v ? 1:2), idx = 1;
	pll hashCheck;

	while(ChainNo[lca] != ChainNo[u]) {
		int topNode = ChainTop[ChainNo[u]];
		pll tmp = SubHash(topNode, u, idx);
		hashCheck.first = (hashCheck.first +  tmp.first)%mod1;
		hashCheck.second = (hashCheck.second + tmp.second)%mod2;
		u = par[topNode][0];
		idx += abs(lvl[topNode] - lvl[u])+1;
	}
	if(u != lca) {
		pll tmp = SubHash(topNode, u, idx);
		hashCheck.first = (hashCheck.first +  tmp.first)%mod1;
		hashCheck.second = (hashCheck.second + tmp.second)%mod2;
		idx += abs(lvl[lca] - lvl[u])+1;
	}
	while(ChainNo[lca] != ChainNo[v]) {
		int topNode = ChainTop[ChainNo[v]];
		pll tmp = SubHash(topNode, v, idx);
		hashCheck.first = (hashCheck.first +  tmp.first)%mod1;
		hashCheck.second = (hashCheck.second + tmp.second)%mod2;
		v = par[topNode][0];
		idx += abs(lvl[topNode] - lvl[v])+1;
	}
	if(v != lca) {
		pll tmp = SubHash(topNode, v, idx);
		hashCheck.first = (hashCheck.first +  tmp.first)%mod1;
		hashCheck.second = (hashCheck.second + tmp.second)%mod2;
		idx += abs(lvl[lca] - lvl[v])+1;
	}
	return hashCheck;
}

int solve(int a, int b, int c, int d) {
	int e = LCA(a, b), f = LCA(c, d);
	int len1 = lvl[a] + lvl[b] - 2*lvl[e] + (a == b ? 1:2);
	int len2 = lvl[c] + lvl[d] - 2*lvl[f] + (c == d ? 1:2);
}

int main() {
	int n;
	cin >> n >> str;

	for(int i = 1; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1);
}