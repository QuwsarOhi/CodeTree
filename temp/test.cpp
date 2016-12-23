
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

int dfs_num[110], dfsNumberCounter, dfs_low[110], dfs_parent[110], dfsRoot, rootChildren, V = 0;
bool articulation_vertex[110], visited[110];
vi AdjList[110];

void AandB(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for(size_t i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if(dfs_num[v] == 0) {
			dfs_parent[v] = u;
			visited[u] = 1;
			if(u == dfsRoot) rootChildren++;
			AandB(v);
			
			if(dfs_low[v] >= dfs_num[u])
				articulation_vertex[u] = true;
			if(dfs_low[v] > dfs_num[u])
				pf("Edge (%d, %d) is a bridge\n", u, v);
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		//pf("dfs : %d : %d : %d\n", u, dfs_num[u], dfs_low[u]);
	}
}

void mset(int x, int y)
{
	AdjList[x].pb(y);
	//AdjList[y].pb(x);
	V = max(V, max(x, y));
}

int main()
{
	memset(dfs_num, 0, sizeof(dfs_num));
	memset(dfs_low, 0, sizeof(dfs_low));
	memset(visited, 0, sizeof(visited));
	memset(dfs_parent, 0, sizeof(dfs_parent));
	dfsNumberCounter = 0;
	mset(1, 2);
	mset(1, 3);
	mset(3, 4);
	mset(4, 5);
	mset(4, 6);
	mset(6, 7);
	mset(7, 3);
	pf("Bridges: \n");
	for(int i = 1; i <= V; i++)
		if(dfs_num[i] == 0) {
			dfsRoot = i;
			rootChildren = 0;
			AandB(i);
			articulation_vertex[dfsRoot] = (rootChildren > 1);
		}
	for(int i = 1; i <= V; i++)
		if(articulation_vertex[i])
			pf(" Vertex %d\n", i);
	for(int i = 1; i <= V; i++)
		pf("dfs : %d : %d : %d\n", i, dfs_num[i], dfs_low[i]);
}
