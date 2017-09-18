// Codeforces
// D. Xenia and Bit Operations
// http://codeforces.com/contest/339/problem/D
// Segment Tree

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

int tree[400000], v[131100];

void segment_init(int pos, int l, int r, int level) {
	//cout << pos << " " << l << " " << r << " " << level << endl;
	if(l == r) {
		tree[pos] = v[l];
		//dbug(pos), dbug(v[l]);
		return;
	}
	
	int mid = (l+r)/2;
	segment_init(pos*2, l, mid, level+1);
	segment_init((pos*2) + 1, mid+1, r, level+1);
	
	if(level&1)
		tree[pos] = tree[pos*2] | tree[(pos*2) +1];
	else
		tree[pos] = tree[pos*2] ^ tree[(pos*2) +1];
}

int query(int pos, int l, int r, int val, int i, int level) {
	if(i < l || r < i)
		return tree[pos];
	if(l == i && l == r) {
		tree[pos] = val;
		return tree[pos];
	}
	
	int mid = (l+r)/2;
	
	int x = query(pos*2, l, mid, val, i, level+1);
	int y = query(pos*2+1, mid+1, r, val, i, level+1);
	
	if(level&1)
		tree[pos] = x | y;
	else
		tree[pos] = x ^ y;
	return tree[pos];
}

int main() {
	int n, m, lim, p, b, level;
	sf("%d %d", &n, &m);
	lim = 1 << n;
	
	fr(i, 1, lim+1)
		sf("%d", &v[i]);
	
	if(n&1) level = 1;
	else level = 0;
	
	segment_init(1, 1, lim, level);

	while(m--) {
		sf("%d %d", &p, &b);
		pf("%d\n", query(1, 1, lim, b, p, level));
	}
	
	return 0;
}
