// SPOJ
// GSS1 - Can you answer these queries I
// http://www.spoj.com/problems/GSS1/
// Segment Tree (Range Maximum Sum, Query)

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

struct node {
	ll ans, prefix, suffix, sum;
	
	node(int val = 0) {
		ans = prefix = suffix = sum = val;
	}
	
	void merge(node left, node right) {
		prefix = max(left.prefix, left.sum+right.prefix);
		suffix = max(right.suffix, right.sum+left.suffix);
		sum = left.sum + right.sum;
		ans = max(left.ans, max(right.ans, left.suffix+right.prefix));
	}
};

node tree[200100];
ll val[50100];

void init(int pos, int l, int r) {
	if(l == r) {
		tree[pos] = node(val[l]);
		return;
	}
	
	int mid = (l+r)/2;
	
	init(pos*2, l, mid);
	init(pos*2+1, mid+1, r);
	
	tree[pos] = node(-INF);
	tree[pos].merge(tree[pos*2], tree[pos*2+1]);
}


node query(int pos, int l, int r, int x, int y) {
	if(y < l || x > r)
		return node(-INF);
	
	if(x <= l && r <= y)
		return tree[pos];
	
	int mid = (l+r)/2;
	
	node lft = query(pos*2, l, mid, x, y);
	node rht = query(pos*2+1, mid+1, r, x, y);
	
	node parent = node(-INF);
	parent.merge(lft, rht);
	return parent;
}

int main() {
	int n, q, x, y;
	sf("%d", &n);
	fr(i, 1, n+1)
		sf("%lld", &val[i]);
	init(1, 1, n);
	sf("%d", &q);
	while(q--) {
		sf("%d %d", &x, &y);
		pf("%lld\n", query(1, 1, n, x, y).ans);
	}
	return 0;
}
