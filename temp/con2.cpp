//unsolved
//11094 - Continents
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define N 500000
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

bool g[25][25], vis[25][25], skip, first;
int p, q, mx, cnt, r1, r2, l, w;
char c, x;

void dfs(int x, int y)
{
	cnt++;
	vis[x][y] = 1;
	//if(cnt > 1) pf("%d %d : %d\n", x, y, cnt);
	if(x == r1 && y == r2)
		skip = 1;
	if(x-1 >= 0 && y-1 >= 0 && g[x-1][y-1] && !vis[x-1][y-1])
		dfs(x-1, y-1);
	if(x-1 >= 0 && g[x-1][y] && g[x-1][y] && !vis[x-1][y])
		dfs(x-1, y);
	if(x-1 >= 0 && y+1 < q && g[x-1][y+1] && !vis[x-1][y+1])
		dfs(x-1, y+1);
	if(y-1 >= 0 && g[x][y-1] && !vis[x][y-1])
		dfs(x, y-1);
	if(y+1 < q && g[x][y+1] && !vis[x][y+1])
		dfs(x, y+1);
	if(x+1 < p && y-1 >= 0 && g[x+1][y-1] && !vis[x+1][y-1])
		dfs(x+1, y-1);
	if(x+1 < p &&  g[x+1][y] && !vis[x+1][y])
		dfs(x+1, y);
	if(x+1 < p && y+1 < q && g[x+1][y+1] && !vis[x+1][y+1])
		dfs(x+1, y+1);
}


int main()
{
	wh(sf("%d %d", &p, &q) != EOF) {
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));
		l = w = 0;
		first = 1;
		fr(i, 0, p)
			fr(j, 0, q) {
				sf(" %c", &c);
				if(first) { 
					x = c;
					first = 0;
				}
				if(c == x) {
					g[i][j] = 1;
					l++;
				}
				else
					w++;
			}
		if(l > w) {
			fr(i, 0, p)
				fr(j, 0, q)
					g[i][j] = !g[i][j];
		}
		sf(" %d %d", &r1, &r2);
		mx = 0;
		//fr(i, 0, p) { fr(j, 0, q) pf("%d", g[i][j]); pf("\n"); }
		fr(i, 0, p)
			fr(j, 0, q) {
				cnt = 0;
				skip = 0;
				if(!vis[i][j] && g[i][j])
					dfs(i, j);
				if(!skip)
					mx = max(mx, cnt);
			}
		pf("%d\n", mx);
	}
	return 0;
}
