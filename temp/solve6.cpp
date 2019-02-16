#include <bits/stdc++.h>
#define MAX 110000
using namespace std;
typedef long long ll;

struct SegTreeRSQ {
    vector<ll>sum, prop;
    int n;
    void Resize(int N) {
        sum.resize(4*N);
        prop.resize(4*N);
        n = N;
    }
    void init(int pos, int l, int r, int val[]) {
        if(l == r) {
            sum[pos] = val[l];
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1]);
    }
    void propagate(int pos, int l, int r) {
        if(prop[pos] == 0 || l == r) return;
        int mid = (l+r)>>1; 
        sum[pos<<1] = (sum[pos<<1] + prop[pos]*(mid-l+1));
        sum[pos<<1|1] = (sum[pos<<1|1] + prop[pos]*(r-mid));
        prop[pos<<1] = (prop[pos<<1] + prop[pos]);
        prop[pos<<1|1] = (prop[pos<<1|1] + prop[pos]);
        prop[pos] = 0;
    }
    void update(int pos, int l, int r, int L, int R, ll val) {
        if(r < L || R < l) return;
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] = (sum[pos] + val*(r-l+1));
            prop[pos] = (prop[pos] + val);
            return;
        }
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1]);
    }
    ll query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        propagate(pos, l, r);
        if(L <= l && r <= R) return sum[pos];
        int mid = (l+r)>>1;
        return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R));
	}
	void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
	ll query(int l, int r) { return query(1, 1, n, l, r); }
};


SegTreeRSQ DS;

vector<int>G[MAX];
int timer, in[MAX], out[MAX], node[MAX], par[MAX][21], lvl[MAX], val[MAX];

void dfs(int u, int p) {
	node[in[u] = ++timer] = u;
	par[u][0] = p, lvl[u] = lvl[p]+1;

	for(int i = 1; i <= 20; ++i)
		par[u][i] = par[par[u][i-1]][i-1];
	
	for(auto v : G[u])
		if(v != p)
			dfs(v, u);
	out[u] = timer;
}

bool isChild(int ch, int par) {
	if(in[par] <= in[ch] and in[ch] <= out[par])
		return 1;
	return 0;
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

int LCA(int u, int v, int root) {
	if(isChild(u, root) and isChild(v, root)) {
		cerr << "LCA " << u << " " << v << " " << root << " " << LCA(u, v) << endl;
		return LCA(u, v);
	}

	if(isChild(u, root) != isChild(v, root)) {
		cerr << "LCA " << u << " " << v << " " << root << " " << root << endl;
		return root;
	}

	int x = LCA(u, v), y = LCA(u, root), z = LCA(v, root);
	int a = lvl[root] - lvl[x], b = lvl[root] - lvl[y], c = lvl[root] - lvl[z];

	cerr << "LCA " << u << " " << v << " " << root << " :: " << x << " " << y << " " << z << " " << a << " " << b << " " << c << endl;

	if(a <= b and a <= c)
		return x;
	if(b <= a and b <= c)
		return y;
	return z;
}

// return k'th node if we traverse from node u to v of a tree
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

void subTreeUpdate(int u, int val, int root) {
	int lca = LCA(u, root);

	if(root == 1) {
		cerr << "*update " << u << endl;
		DS.update(in[u], out[u], val);
	}
	else if(lca == u and u != root) {
		int lcaChild = getKthNode(root, u, lvl[u] + lvl[root] - 2*lvl[lca], lca);
		cerr << "update " << 1 << " and lcaChild " << lcaChild << " u " << u << endl; 
		DS.update(in[1], out[1], val);
		DS.update(in[lcaChild], out[lcaChild], -val);
	}
	else {
		cerr << "update " << u << endl;
		DS.update(in[u], out[u], val);
	}
}

/*ll subTreeQuery(int u, int root) {
	int lca = LCA(u, root);

	if(root == 1) {
		cerr << "*query " << u << endl;
		return DS.query(in[u], out[u]);
	}
	else if(lca == u and u != root) {
		int lcaChild = getKthNode(root, u, lvl[u] + lvl[root] - 2*lvl[lca], lca);
		cerr << "query " << 1 << " and lcaChild " << lcaChild << " u " << u << endl; 
		return DS.query(in[1], out[1]) - DS.query(in[lcaChild], out[lcaChild]);
	}
	else {
		cerr << "query " << u << endl;
		return DS.query(in[u], out[u]);
	}
}*/

ll subTreeQuery(int u, int v, int root) {
	if(isChild(root, u) and isChild(v, root))
		return DS.query(in[1], out[1]);
	else if(isChild(root, v) and isChild(u, root))
		return DS.query(in[1], out[1]);
	int lca = LCA(u, v, root);

	if(isChild(lca, root))
		return DS.query(in[lca], out[lca]);

	
}


int main() {
	int n, q, u, v, x, typ;

	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);

	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int root = 1;
	dfs(root, 0);
	DS.Resize(n);
	DS.init(1, 1, n, val);

	while(q--) {
		scanf("%d", &typ);

		if(typ == 1)
			scanf("%d", &root);
		else if(typ == 2) {
			scanf("%d%d%d", &u, &v, &x);
			subTreeUpdate(LCA(u, v, root), x, root);
		}
		else {
			scanf("%d", &v);
			printf("%lld\n", subTreeQuery(v, root));
		}
	}

	return 0;
}