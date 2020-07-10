#include <bits/stdc++.h>
#define MAX 200010
using namespace std;
typedef long long ll;

// 0 : l->r
// 1 : r->l 
vector<ll> G[2][MAX], h, w;
ll idx, n, root[2];

void dfs_insert(int u, int p, int d) {
	cout << "AT " << u << endl;
	while(idx < n and idx > -1) {
		if(h[u] >= h[idx]) {
			cout << u << " -> " << idx << endl;
			G[p][u].push_back(idx);
			idx += d;
			dfs_insert(idx-d, p, d);
		}
		else if(u == root[p]) {
			idx += d;
		}
		else
			return;
	}
}

void dfs(int u, int p) {
	for(auto v : G[p][u]) {
		cout << u << " -> " << v << endl;
		dfs(v, p);
	}
}



int main() {
	ll q, x;
	scanf("%lld%lld", &n, &q);

	for(int i = 0; i < n; ++i) {
		scanf("%lld", &x);
		h.push_back(x);
	}

	for(int i = 0; i < n; ++i) {
		scanf("%lld", &x);
		w.push_back(x);
	}
 				
 	cout << "PUSH DONE\n";
 	idx = 1;
 	root[0] = 0;
	dfs_insert(0, 0, 1);
	cout << "Graph 0 done\n";
	idx = n-2;
	root[1] = n-1;
	dfs_insert(n-1, 1, -1);
	cout << "Graph 1 done\n";

	dfs(0, 0);
	cout << "------------------\n";
	dfs(n-1, 1);

	return 0;
}