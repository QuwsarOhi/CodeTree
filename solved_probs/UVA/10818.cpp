// UVa
// 10818 - Dora Trip
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1759

#include <bits/stdc++.h>
using namespace std;
#define MAX                 25
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
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
typedef pair<double, double>pdd;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

string g[MAX];
int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};
char D[] = {'E', 'N', 'S', 'W'};
bool vis[MAX][MAX];
vii v;
map<pair<int, int>, int>DIR;
string dir[MAX][MAX], dp[12][1 << (12)], path[12][12];

void fill(int x, int y) {
	if(vis[x][y]) return;
	if(g[x][y] == '#' or g[x][y] == 'X') return;
	if(g[x][y] == '*') {
		DIR[{x, y}] = v.size();
		v.pb({x, y});
	}
	vis[x][y] = 1;
	for(int i = 0; i < 4; ++i)
		fill(x+dx[i], y+dy[i]);
}

string SMALL(string &a, string &b) {
	if(a.empty()) return b;
	if(a.size() < b.size()) return a;
	else if(b.size() < a.size()) return b;
	for(int i = 0; i < (int)a.size(); ++i)
		if(a[i] > b[i])
			return b;
	return a;
}

bool getPath(int x, int y, int _x, int _y, string &str) {
	if(g[x][y] == '#' or g[x][y] == 'X' or vis[x][y])
		return 0;
	if(x == _x and y == _y)
		return 1;
	string tmp, ret;
	str.clear();
	bool ok = 0;
	vis[x][y] = 1;
	for(int i = 0; i < 4; ++i) {
		tmp.clear(), ret.clear();
		tmp.pb(D[i]);
		if(getPath(x+dx[i], y+dy[i], _x, _y, ret)) {
			tmp += ret;
			if(str.empty())
				str = tmp;
			else
				str = SMALL(str, tmp);
			ok = 1;
		}
	}
	vis[x][y] = 0;
	return ok;
}


void bfsPoint(int p) {
	for(int i = 0; i < MAX; ++i)
		for(int j = 0; j < MAX; ++j)
			dir[i][j].clear();
	queue<pair<int, int> >q;
	q.push({v[p]});
	while(not q.empty()) {
		pii u = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int x = u.fi+dx[i], y = u.se+dy[i];
			if(g[x][y] == 'X' or g[x][y] == '#') continue;
			
			string tmp = dir[u.fi][u.se];
			tmp.pb(D[i]);
			if(dir[x][y].empty()) {
				dir[x][y] = tmp;
				q.push({x, y});
			}
			else if(dir[x][y].size() > tmp.size()) {
				dir[x][y] = tmp;
				q.push({x, y});
			}
			else if(dir[x][y].size() == tmp.size() and dir[x][y] > tmp) {
				dir[x][y] = tmp;
				q.push({x, y});
			}
	}}
	
	for(auto it : DIR) {
		if(it.se == p) continue;
		int x = it.fi.fi, y = it.fi.se;
		path[p][it.se] = dir[x][y];
	}	
}
		

string TSP(int pos, int mask) {
	if(__builtin_popcount(mask) == (int)v.size())
		return path[pos][0];
	if(not dp[pos][mask].empty())
		return dp[pos][mask];
	string ret, tmp;
	for(int i = 0; i < (int)v.size(); ++i)
		if(not (mask & (1<<i))) {
			tmp = path[pos][i] + TSP(i, mask | (1 << i));
			if(ret.empty())
				ret = tmp;
			else if(tmp.size() < ret.size())
				ret = tmp;
			else if(tmp.size() == ret.size() and tmp < ret)
				ret = tmp;
		}
	return dp[pos][mask] = ret;
}

int main() {
	int n, m, _x, _y;
	while(cin >> n >> m) {
		if(n == 0 and m == 0) break;
		v.clear();
		DIR.clear();
		getchar();
		
		for(int i = 0; i < n; ++i) {
			g[i].clear();
			getline(cin, g[i]);
			
			for(int j = 0; j < m; ++j)
				if(g[i][j] == 'S') {
					_x = i, _y = j;
					DIR[{i, j}] = v.size();
					v.pb({i, j});
		}}
		
		memset(vis, 0, sizeof vis);
		fill(_x, _y);
		
		if(v.size() == 1ULL) {
			cout << "Stay home!\n";
			continue;
		}
		for(int i = 0; i < (int)v.size(); ++i)
			bfsPoint(i);
		for(int i = 0; i < 12; ++i)
			for(int j = 0; j < (1 << 12); ++j)
				dp[i][j].clear();
		string ans = TSP(0, 1);
		cout << ans << endl;
	}
	return 0;
}
		
/*

5 5
#####
#  S#
# XX#
#  *#
#####
5 5
#####
#* X#
###X#
#S *#
#####
5 5
#####
#S X#
#  X#
# #*#
#####
0 0


10 12
############
##X X #S  ##
#       ## #
#  # * * X #
#   #  X   #
#  # # X # #
## XX**  # #
# *  #     #
#*      X  #
############

10 12
############
##X X #S  ##
#       ## #
#  # *   X #
#   #  X   #
#  # # X # #
## XX    # #
#    #     #
#       X  #
############

*/
