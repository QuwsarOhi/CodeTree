// LightOJ
// 1120 - Rectangle Union

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

struct Node {
	ll yMin, yMax, x, val;
	
	Node(ll a, ll b, ll c, ll d) {
		this->yMin = a;
		this->yMax = b;
		this->x = c;
		this->val = d;
	}
};

bool cmp(Node a, Node b) {
	return a.x < b.x;
}

vl yAxis;
vector<Node>yLine;

// Segment tree functions
ll tree[4*100010], prop[4*100010];

ll calculate(int node, int l, int r) {
	if(prop[node] > 0)
		return yAxis[r]-yAxis[l];
	else
		return tree[node<<1] + tree[node<<1|1];
}

void update(ll node, ll l, ll r, ll yMin, ll yMax, ll val) {
	if(yMax < yAxis[l] || yAxis[r] < yMin)
		return;
	
	//printf("node : %d,  l : %d, r : %d, yMin : %d, yMax : %d, val : %d\n", node, l, r, yMin, yMax, val);
	//printf("boundary %d : %d\n", yAxis[l], yAxis[r]);
	
	if(yMin <= yAxis[l] && yAxis[r] <= yMax) {
		prop[node] += val;
		
		tree[node] = calculate(node, l, r);
		//printf("value set & return\n");
		return;
	}
	
	if(l+1 == r) return;		// The leaf node must be double node
	
	ll mid = (l+r)>>1;
	update(node<<1, l, mid, yMin, yMax, val);
	update(node<<1|1, mid, r, yMin, yMax, val);
	tree[node] = calculate(node, l, r);
}
	
int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, x1, y1, x2, y2, n;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		yAxis.pb(0);
		for(int i = 0; i < n; ++i) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			yAxis.pb(y1);
			yAxis.pb(y2);
			yLine.pb(Node(y1, y2, x1, 1));
			yLine.pb(Node(y1, y2, x2, -1));
		}
		
		// Taking only unique y values (will be used as segment tree nodes)
		sort(yAxis.begin(), yAxis.end());
		yAxis.erase(unique(yAxis.begin()+1, yAxis.end()), yAxis.end());
		
		//for(int i = 0; i < yAxis.size(); ++i)
		//	printf("%d ", yAxis[i]);
		//printf("\n");
		
		// Sorting y axis lines according to x axis (left to right)
		sort(yLine.begin(), yLine.end(), cmp);
		
		memset(tree, 0, sizeof tree);
		memset(prop, 0, sizeof prop);
		
		update(1, 1, (int)yAxis.size()-1, yLine[0].yMin, yLine[0].yMax, yLine[0].val);
		
		ll area = 0;
		for(int i = 1; i < (int)yLine.size(); ++i) {
			area += tree[1] * (yLine[i].x - yLine[i-1].x);
			//printf("--------------------\narea : %d, tree : %d\n--------------------\n", area, tree[1]);
			update(1, 1, (int)yAxis.size()-1, yLine[i].yMin, yLine[i].yMax, yLine[i].val);
		}
		
		printf("Case %d: %lld\n", Case, area);
		yAxis.clear();
		yLine.clear();
	}
	return 0;
}
