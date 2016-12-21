//UVa
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

bool g[110][110], tag, visited[110][110], skip, first;
int dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0}, p, q, dis, x, y, mx;
char t, c;

void dfs(int i, int j)
{
	visited[i][j] = 1;
	dis++;
	if(i == y && j == x)
		skip = 1;
	for(int k = 0; k < 4; k++) {
		if(i + dr[k] >= 0 && i + dr[k] < p && j + dc[k] >= 0 && j + dc[k] < q && g[i + dr[k]][j + dc[k]] == tag && !visited[i + dr[k]][j + dc[k]])
			dfs(i + dr[k], j + dc[k]);
		else if(i + dr[k] >= 0 && i + dr[k] < p && j + dc[k] == q && !visited[i+dr[k]][0] && g[i+dr[k]][0] == tag)
			dfs(i + dr[k], 0);
		else if(i + dr[k] >= 0 && i + dr[k] < p && j + dc[k] == -1 && !visited[i+dr[k]][q-1] && g[i+dr[k]][q-1] == tag)
			dfs(i + dr[k], q-1);
	}
}


int main()
{
	wh(sf("%d %d", &p, &q) != EOF) {
		first = 1;
		fr(i, 0, p)
			fr(j, 0, q) {
				sf(" %c", &c);
				if(first) {
					t = c;
					first = 0;
				}
				if(c == t) g[i][j] = 1;
				else g[i][j] = 0;
			}
		memset(visited, 0, sizeof(visited));
		sf("%d %d", &y, &x);
		tag = g[y][x];
		mx = 0;
		fr(i, 0, p)
			fr(j, 0, q) {
				dis = 0;
				skip = 0;
				if(!visited[i][j] && g[i][j] == tag)
					dfs(i, j);
				if(!skip)
					mx = max(dis, mx);
		}
		pf("%d\n", mx);
	}
}
