// SPOJ
// GSS3 - Can you answer these queries III
// http://www.spoj.com/problems/GSS3/
// Segment Tree (Range Maximum Sum, Query, Update)

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+16
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

struct node {
	ll sum, prefix, suffix, ans;
	
	node(ll val = 0) {
		sum = prefix = suffix = ans = val;
	}
	
	void merge(node left, node right) {
		sum = left.sum + right.sum;
		prefix = max(left.prefix, left.sum+right.prefix);
		suffix = max(right.suffix, right.sum+left.suffix);
		ans = max(left.ans, max(right.ans, left.suffix+right.prefix));
	}
};

node tree[201000];
ll v[50010];

void init(int pos, int l, int r) {
	if(l == r) {
		tree[pos] = node(v[l]);
		return;
	}
	
	int mid = (l+r)/2;
	
	init(pos*2, l, mid);
	init(pos*2+1, mid+1, r);
	
	tree[pos] = node(-INF);
	tree[pos].merge(tree[pos*2], tree[pos*2+1]);
}

void update(int pos, int l, int r, int x, int val) {
	if(l == r && l == x) {
		tree[pos] = node(val);
		return;
	}
	
	if(x < l || r < x)
		return;
	
	int mid = (l+r)/2;
	
	update(pos*2, l, mid, x, val);
	update(pos*2+1, mid+1, r, x, val);
	
	tree[pos] = node(-INF);
	tree[pos].merge(tree[pos*2], tree[pos*2+1]);
}

node query(int pos, int l, int r, int x, int y) {
	if(r < x || y < l)
		return node(-INF);
	
	if(x <= l && r <= y) {
		//pf("returning on %d %d\n", l, r);
		return tree[pos];
	}
	
	int mid = (l+r)/2;
	
	node lft = query(pos*2, l, mid, x, y);
	node rht = query(pos*2+1, mid+1, r, x, y);
	node parent = node(-INF);
	parent.merge(lft, rht);
	return parent;
}

int main() {
	int n, x, y, q, u;
	sf("%d", &n);
	fr(i, 1, n+1)
		sf("%lld", &v[i]);
	sf("%d", &q);
	init(1, 1, n);
	
	while(q--) {
		sf("%d", &u);
		if(u == 0) {
			sf("%d %d", &x, &y);
			update(1, 1, n, x, y);
		}
		else {
			sf("%d %d", &x, &y);
			pf("%lld\n", query(1, 1, n, x, y).ans);
		}
	}
	return 0;
}
	
