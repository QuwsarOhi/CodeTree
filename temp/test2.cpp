
#include <bits/stdc++.h>
#define pb push_back
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

using namespace std;

int dfs_low[110], dfs_num[110], dfsNumberCounter, numSCC, V;
bool visited[110];
vector<int>AdjList[110], S;

void tarjanSCC(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for(size_t i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if(dfs_num[v] == 0)
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	
	if(dfs_low[u] == dfs_num[u]) {
		printf("SCC %d: ", ++numSCC);
		while(1) {
			int v = S.back();
			S.pop_back();
			visited[v] = 0;
			printf(" %d", v);
			if(u == v)
				break;
		}
		printf("\n");
	}
}

void mset(int x, int y)
{
	AdjList[x].pb(y);
	V = max(V, max(x, y));
}

int main()
{
	memset(dfs_num, 0, sizeof(dfs_num));
	memset(dfs_low, 0, sizeof(dfs_low));
	memset(visited, 0, sizeof(visited));
	dfsNumberCounter = numSCC = 0;
	
	mset(0, 1);
	mset(1, 3);
	mset(2, 1);
	mset(3, 2);
	mset(3, 4);
	mset(4, 5);
	mset(5, 7);
	mset(7, 6);
	mset(6, 4);
	
	for(int i = 0; i < V; i++)
		if(dfs_num[i] == 0)
			tarjanSCC(i);
}
