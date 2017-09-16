// LightOJ
// 1012 - Guilty Prince
// http://lightoj.com/volume_showproblem.php?problem=1012

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

int r[] = {-1, 0, 0, 1}, c[] = {0, -1, 1, 0}, cnt, n, m;
bool visited[30][30];
char G[30][30];

void floodFill(int _x, int _y) {
	++cnt;
	visited[_x][_y] = 1;
	fr(i, 0, 4) {
		int x = _x+r[i];
		int y = _y+c[i];
		
		if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y])
			continue;

		if(G[x][y] == '.')
			floodFill(x, y);
	}
}


int main() {
	int t, markI, markJ;
	sf("%d", &t);
	fr(Case, 1, t+1) {
		sf("%d %d", &m, &n);
		fr(i, 0, n)
			fr(j,0, m) {
				sf(" %c", &G[i][j]);
				if(G[i][j] == '@') {
					markI = i;
					markJ = j;
				}
			}
		
		cnt = 0;
		memset(visited, 0, sizeof visited);
		floodFill(markI, markJ);
		
		pf("Case %d: %d\n", Case, cnt);
	}
	return 0;
}
