// SPOJ
// BGSHOOT - Shoot and kill
// Segment Tree + Path Compression

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e7
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
#define SIZE(a) ((int)a.size())
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
typedef vector<ll>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;

vl point, tree, prop;

void propagate(int node, int l, int r) {
	if(!prop[node])
		return;
	
	if(l!=r) {
		prop[node<<1] += prop[node];
		prop[node<<1|1] += prop[node];
		tree[node<<1] += prop[node];
		tree[node<<1|1] += prop[node];
	}
	
	prop[node] = 0;
}

void update(int node, int L, int R, int l, int r) {
	if(r < point[L] || point[R] < l)
		return;
	
	propagate(node, l, r);
	
	if(l <= point[L] && point[R] <= r) {
		tree[node] += 1;
		prop[node] += 1;
		return;
	}
	
	int mid = (L+R)>>1;
	
	update(node<<1, L, mid, l, r);
	update(node<<1|1, mid+1, R, l, r);
	tree[node] = max(tree[node<<1], tree[node<<1|1]);
}

ll query(int node, int L, int R, int l, int r) {
	if(r < point[L] || point[R] < l)
		return 0;
	
	propagate(node, l, r);
	
	if(l <= point[L] && point[R] <= r)
		return tree[node];
		
	int mid = (L+R)>>1;
	
	ll lft = query(node<<1, L, mid, l, r);
	ll rht = query(node<<1|1, mid+1, R, l, r);
	return  max(lft, rht);
}

int main() {
	//freopen("in", "r", stdin);
	
	ll n, q, l, r;
	queue<pll>segQ, queryQ;
	
	scanf("%lld", &n);
	point.pb(0);		// Dummy
	while(n--) {
		scanf("%lld %lld", &l, &r);
		point.pb(l);
		point.pb(r);
		segQ.push(mp(l, r));
	}
	
	scanf("%lld", &q);
	while(q--) {
		scanf("%lld %lld", &l, &r);
		point.pb(l);
		point.pb(r);
		queryQ.push(mp(l, r));
	}
	
	sort(point.begin(), point.end());
	point.erase(unique(point.begin()+1, point.end()), point.end());
	
	tree.resize(1001000*4, 0);
	prop.resize(1001000*4, 0);
	
	while(!segQ.empty()) {
		update(1, 1, SIZE(point)-1, segQ.front().fi, segQ.front().se);
		segQ.pop();
	}
	
	while(!queryQ.empty()) {
		ll ans = query(1, 1, SIZE(point)-1, queryQ.front().fi, queryQ.front().se);
		printf("%lld\n", ans);
		queryQ.pop();
	}
	
	return 0;
}
