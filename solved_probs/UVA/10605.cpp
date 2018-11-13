// UVa
// 10605 - Mines For Diamonds

#include <bits/stdc++.h>
using namespace std;
#define MAX                 15
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


//0x3f3f3f3f : 1061109567
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

char g[MAX][MAX];
int dist[MAX][MAX], dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}, r, c;
vii point;

int BFS(int x, int y) {
	queue<pii>q;
	q.push({x, y});
	
	memset(dist, INF, sizeof dist);
	dist[x][y] = 0;

	while(not q.empty()) {
		x = q.front().fi, y = q.front().se;
		q.pop();
		if(g[x][y] == '#')
			return dist[x][y];
		for(int i = 0; i < 4; ++i) {
			int xx = x+dx[i], yy = y+dy[i];
			if(xx < 0 or yy < 0 or xx >= r or yy >= c or dist[xx][yy] != INF) 
				continue;
			dist[xx][yy] = dist[x][y]+1;
			q.push({xx, yy});
		}
	}
	return -1;
}

int HamDist(int p, int q) {
	return abs(point[p].fi-point[q].fi) + abs(point[p].se-point[q].se);
}

int dp[1<<12][12], seg[1<<12], startDist[12], ans[1<<12];
int maskDP() {
	// dp[mask(the_position_which_i've_visited)][the_position_where_im_at_right_now]
	memset(dp, INF, sizeof dp);
	memset(seg, INF, sizeof seg);
	for(int i = 0; i < SIZE(point); ++i)
		dp[1<<i][i] = startDist[i];

	for(int mask = 1; mask < (1<< SIZE(point)); ++mask) {
		for(int from = 0; from < SIZE(point); ++from) {
			if(not (mask & (1<<from))) continue;
			for(int to = 0; to < SIZE(point); ++to) {
				if(not (mask & (1<<to))) continue;
				if(from == to) continue;
				int pastMask = mask^(1<<to);
				dp[mask][to] = min(dp[mask][to], dp[pastMask][from] + HamDist(from, to));
			}
		}

		for(int i = 0; i < SIZE(point); ++i)
			seg[mask] = min(seg[mask], dp[mask][i]);		// contains minimum of all states of mask
	}

	for(int mask1 = 1; mask1 < (1<<SIZE(point)); ++mask1) {		// slicing masked set to half and calculating the minimum
		for(int mask2 = 1; mask2 < mask1; ++mask2) {
			if(mask1 & mask2 == mask2)							// mask2 is subset of mask1
				seg[mask1] = min(seg[mask1], seg[mask1 ^ mask2] + seg[mask2]);
		}
	}
	return seg[(1<<(SIZE(point)))-1];
}


int main() {
	//fileRead("in");
	//fileWrite("out");

	int t;
	sf("%d", &t);
	while(t--) {
		sf("%d%d", &r, &c);
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j) {
				sf(" %c", &g[i][j]);
				if(g[i][j] == '*')
					point.pb({i, j});
			}
		for(int i = 0; i < SIZE(point); ++i)
			startDist[i] = BFS(point[i].fi, point[i].se);

		//for(int i = 0; i < SIZE(point); ++i)
		//	cerr << point[i].fi << " " << point[i].se << " :: " << startDist[i] << endl;

		pf("%d\n", maskDP());
		point.clear();
	}
	return 0;
}