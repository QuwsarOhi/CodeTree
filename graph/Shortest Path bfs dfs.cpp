//UVa
//10653 - Bombs! NO they are Mines!!
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
#define vi vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define inf std::numeric_limits<int>::max()
#define pf printf
#define wh while
#define ll long long

using namespace std;

bool g[1010][1010], vis[1010][1010];
int level[1010][1010], n, m, b, r, c, q, s1, s2, e1, e2;

/*void dfs(int x, int y, int dis)
{
	//vis[x][y] = 1;
	++dis;
	//pf("%d %d : %d\n", x, y, dis+1);
	//if(dis < level[x][y])
		level[x][y] = dis;
		if(x-1 >= 0 && g[x-1][y] && level[x][y]+1 < level[x-1][y])
			dfs(x-1, y, level[x][y]);
		if(y-1 >= 0 && g[x][y-1] && level[x][y]+1 < level[x][y-1])
			dfs(x, y-1, level[x][y]);
		if(y+1 < m && g[x][y+1] && level[x][y]+1 < level[x][y+1])
			dfs(x, y+1, level[x][y]);
		if(x+1 < n && g[x+1][y] && level[x][y]+1 < level[x+1][y])
			dfs(x+1, y, level[x][y]);
}*/

void bfs(int _x, int _y)
{
	queue<pair<int, int> >que;
	register int x, y;
	vis[_x][_y] = 1;
	level[_x][_y] = 0;
	que.push(mp(_x, _y));
	wh(!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		//pf("%d %d : %d %d\n", x, y, level[x][y], (int)que.size());
		que.pop();
		if(x-1 >= 0 && g[x-1][y] && vis[x-1][y] == 0) {
			level[x-1][y] = level[x][y]+1;
			vis[x-1][y] = 1;
			que.push(mp(x-1, y));
		}
		if(y-1 >= 0 && g[x][y-1] && vis[x][y-1] == 0) {
			level[x][y-1] = level[x][y]+1;
			vis[x][y-1] = 1;
			que.push(mp(x, y-1));
		}
		if(y+1 < m && g[x][y+1] && vis[x][y+1] == 0) {
			level[x][y+1] = level[x][y]+1;
			vis[x][y+1] = 1;
			que.push(mp(x, y+1));
		}
		if(x+1 < n && g[x+1][y] && vis[x+1][y] == 0) {
			level[x+1][y] = level[x][y]+1;
			vis[x+1][y] = 1;
			que.push(mp(x+1, y));
		}
	}
}

int main()
{
	wh(sf("%d %d", &n, &m) && n && m) {
		memset(g, 1, sizeof(g));
		memset(vis, 0, sizeof(vis));
		sf("%d", &b);
		wh(b--) {
			sf("%d %d", &r, &q);
			wh(q--) {
				sf("%d", &c);
				g[r][c] = 0;
			}
		}
		sf("%d %d %d %d", &s1, &s2, &e1, &e2);
		bfs(s1, s2);
		pf("%d\n", level[e1][e2]);
	}
	return 0;
}

