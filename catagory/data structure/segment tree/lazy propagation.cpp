// HORRIBLE - Horrible Queries
// http://www.spoj.com/problems/HORRIBLE/
// Segment Tree Lazy Propagation

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

// Segment Tree Lazy Propagation

vector<pair<ull, ull> > tree;

// (l, r) : tree segment, (x, y) : update segment

void update(ll pos, ll l, ll r, ll x, ll y, ll val) {
	if(y < l || x > r)
		return;
	
	if(x <= l && r <= y) {		// Tree segment in update segment
		tree[pos].fi += (r-l+1)*val;
		tree[pos].se += val;	// Propagate
		return;
	}
	
	ll mid = (l+r)/2LL;
	
	update(pos*2LL, l, mid, x, y, val);
	update(pos*2LL + 1, mid+1, r, x, y, val);
	
	tree[pos].fi = tree[pos*2].fi + tree[pos*2+1].fi + (r-l+1)*tree[pos].se;
}

// Pass propagate value through carry
ll query(ll pos, ll l, ll r, ll x, ll y, ll carry) {
	if(y < l || x > r)
		return 0;
	
	if(x <= l && r <= y)
		return tree[pos].fi + (carry * (r-l+1));
	
	ll mid = (l+r)/2LL;
	
	ll lft = query(pos*2LL, l, mid, x, y, carry + tree[pos].se);
	ll rht = query(pos*2LL + 1, mid+1, r, x, y, carry + tree[pos].se);
	
	return lft + rht;
}

int main() {
	int t, n, x, y, v, q, a;
	sf("%d", &t);
	
	while(t--) {
		sf("%d %d", &n, &q);
		tree.resize((4LL)*n + 10, {0, 0});
		while(q--) {
			sf("%d", &a);
			if(a) {
				sf("%d %d", &x, &y);
				pf("%lld\n", query(1, 1, n, x, y, 0));
			}
			else {
				sf("%d %d %d", &x, &y, &v);
				update(1, 1, n, x, y, (ull)v);
			}
		}
		tree.clear();
	}
	return 0;
}
