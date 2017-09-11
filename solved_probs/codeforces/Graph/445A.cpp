// Codeforces
// A. DZY Loves Chessboard
// http://codeforces.com/problemset/problem/445/A
// Graph, BFS

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

int n, m, r[] = {-1, 0, 0, 1}, c[] = {0, -1, 1, 0};
char g[110][110];


void fill(int X, int Y) {
	queue<pii>q;
	q.push({X, Y});
    g[X][Y] = 'B';
	while(!q.empty()) {
		int _x = q.front().fi;
		int _y = q.front().se;
		
        q.pop();
        
		fr(i, 0, 4) {
			int x = _x+r[i];
			int y = _y+c[i];
			
			if(x < 0 || x >= n || y < 0 || y >= m)
				continue;
			
			if(g[x][y] != '.') continue;
			
			if(g[_x][_y] == 'B') g[x][y] = 'W';
			else g[x][y] = 'B';
            
			q.push({x, y});
		}
	}
}


int main() {
	sf("%d %d", &n, &m);
	
	fr(i, 0, n)
		fr(j, 0, m)
			sf(" %c", &g[i][j]);

	fr(i, 0, n)
		fr(j, 0, m)
			if(g[i][j] == '.')
				fill(i, j);
	
	fr(i, 0, n) {
		fr(j, 0, m) 
			pf("%c", g[i][j]);
		pf("\n");
	}
	
	return 0;
}
