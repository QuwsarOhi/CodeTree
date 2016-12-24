
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
//Bridge : An edge is a bridge if and only if it is not contained in any cycle
//Articulation Point: A node is articulation point if disconnecting it creates
//more connected component (cc)
void ArticulationPointandBrdge(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for(size_t i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if(dfs_num[v] == 0) {				//tree edge (subtree) unvisited condition
			dfs_parent[v] = u;				//memorising the parent node
			if(u == dfsRoot) rootChildren++;//special case if u is root
			ArticulationPointandBrdge(v);	//visiting the next node before checking
			if(dfs_low[v] >= dfs_num[u])	//this denotes that it has sub tree or back-edge
				articulation_vertex[u] = true;	//articulation vertex found
			if(dfs_low[v] > dfs_num[u])		//this denotes that it has no back-edge
				pf("Edge (%d, %d) is a bridge\n", u, v); //bridge found
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); //dfs_low is the minimum dfs_num
		}									//of its sub tree
		else if(v != dfs_parent[u])			//a back edge (not a direct cycle)
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);	//checking the back edge dfs_num
}}

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
