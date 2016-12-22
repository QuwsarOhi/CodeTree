
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
#define vi std::vector<int>
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;
//UNVISITED -> 0
//EXPLORED -> 1
//VISITED -> 2

int dfs_num[110], dfs_parent[110];
vi AdjList[110];

void graphCheck(int u)
{
	dfs_num[u] = 1;
	for(size_t i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if(dfs_num[v] == 0) {
			dfs_parent[v] = u;
			graphCheck(v);
		}
		else if(dfs_num[v] == 1) {
			if(dfs_parent[u] == v)
				pf("Two ways (%d %d)-(%d %d)\n", u, v, v, u);
			else
				pf("Back Edge (%d %d) (Cycle)\n", u, v);
		}
		else if(dfs_num[v] == 2)
			pf("Forward/Cross Edge (%d %d)\n", u, v);
	}
	dfs_num[u] = 2;
}

void gset(int x, int y)
{
	AdjList[x].pb(y);
	AdjList[y].pb(x);
}


int main()
{
	int V = 9, cmp = 1;
	memset(dfs_num, 0, sizeof(dfs_num));
	memset(dfs_parent, 0, sizeof(dfs_parent));
	gset(0, 1);
	gset(1, 2);
	gset(1, 3);
	gset(2, 3);
	gset(3, 4);
	gset(7, 6);
	gset(6, 8);
	for(int i = 0; i < V; i++) {
		if(dfs_num[i] == 0) {
			pf("Component %d:\n", cmp++);
			graphCheck(i);
		}
	}
	return 0;
}
