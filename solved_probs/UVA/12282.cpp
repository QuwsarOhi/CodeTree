// UVa
// 12282 - OmniGravity
    
#include <bits/stdc++.h>
using namespace std;
#define MAX                 20000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define x                  first
#define y                  second
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


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

int dx[] = {0, 0, 1, 1}, dy[] = {0, 1, 0, 1};
int gx[] = {-1, 0, 0, 1}, gy[] = {0, -1, 1, 0}; 	// up left right down
char g[10][10];

struct state {
	pii p[4];
	bool pos[8][8];
	
	// a, b, c, d
	state(pii pp[]) {
		for(int i = 0; i < 4; ++i) p[i] = pp[i];
	}
	state(ll v) {
		for(int i = 0; i < 4; ++i) {
			p[3-i].y = v%10;
			v /= 10;
			p[3-i].x = v%10;
			v /= 10;
		}
	}
	
	ll compress() {
		ll v = 0;
		for(int i = 0; i < 4; ++i) {
			v *= 10;
			v += p[i].x;
			v *= 10;
			v += p[i].y;
		}
		return v;
	}
	
	void place(pii a) {
		for(int i = 0; i < 4; ++i)
			pos[a.x+dx[i]][a.y+dy[i]] = 1;
	}
	
	void disPlace(pii a) {
		for(int i = 0; i < 4; ++i)
			pos[a.x+dx[i]][a.y+dy[i]] = 0;
	}
	
	bool canPlace(pii a) {
		for(int i = 0; i < 4; ++i) {
			int _x = a.x+dx[i], _y = a.y+dy[i];
			if(_x < 0 or _y < 0 or _x >= 8 or _y >= 8 or g[_x][_y] == '#' or pos[_x][_y])
				return 0;
		}
		return 1;
	}
	
	ll Gravity(int dir) {
		bool ok;
		memset(pos, 0, sizeof pos);
		for(int i = 0; i < 4; ++i) place(p[i]);
		
		do {
			ok = 0;
			for(int box = 0; box < 4; ++box) {		// try to move the boxes towards gravity
				int _x = p[box].x+gx[dir], _y = p[box].y+gy[dir];
				disPlace(p[box]);
				if(canPlace(mp(_x, _y))) {
					ok = 1;
					p[box].x = _x, p[box].y = _y;
				}
				place(p[box]);
			}
		} while(ok);
		return compress();
	}
};

void PRINT(pii p[]) {
	char gg[8][8];
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			gg[i][j] = (g[i][j] == '#' ? '#':'.');
	
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j) {
			int x = p[i].x+dx[j], y = p[i].y+dy[j];
			gg[x][y] = i+'A';
		}
	
	for(int i = 0; i < 8; ++i, pf("\n"))
		for(int j = 0; j < 8; ++j)
			pf("%c", gg[i][j]);
	pf("\n");
}
			

unordered_set<ll>vis;

int bfs(pii p[]) {
	state u = state(p);
	queue<state>q;
	q.push(u);
	int ans = 0;
	
	while(not q.empty()) {
		u = q.front();
		q.pop();
		++ans;
		
		//cerr << "AT---------\n";
		//PRINT(u.p);
		//getchar();	
		
		for(int i = 0; i < 4; ++i) {
			state v = u;
			ll vv = v.Gravity(i);
			if(vis.count(vv)) continue;
			vis.insert(vv);
			//cerr << i << endl;
			//PRINT(v.p);
			q.push(v);
		}
	}
	return ans;
}
			

int main() {
	int t;
	pii p[4];
	bool found[10];
	sf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		memset(found, 0, sizeof found);
		for(int i = 0; i < 8; ++i)
			for(int j = 0; j < 8; ++j) {
				sf(" %c", &g[i][j]);
				if(isalpha(g[i][j]) and not found[g[i][j]-'A']) {
					p[g[i][j]-'A'] = {i, j}, found[g[i][j]-'A'] = 1;
					//cerr << g[i][j] << " at " << i << ", " << j << endl;
				} 
			}
		
		pf("Case %d: %d\n", Case, bfs(p)-1);
		vis.clear();
	}
	
	return 0;
}

/*
1
....AA..
....AA..
........
CC....BB
CC....BB
........
..DD....
..DD....
28

1
....AA..
....AA..
........
CC...BB.
CC...BB.
........
..DD....
..DD....
40
*/
