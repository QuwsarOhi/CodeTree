//UVa
//10004 - Bicoloring

#include <bits/stdc++.h>
#define pb push_back
#define sp(b) if(!b)printf("\n"); b = false;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b);
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

vector<int>mat[500];
int visited[500];

bool bipatite(int n)
{
	queue<int>q;
	q.push(n);
	visited[n] = 1;
	while(!q.empty())
	{
		int u = q.front();
		for(unsigned int i = 0; i < mat[u].size(); i++)
		{
			if(visited[mat[u][i]] == -1)
			{
				if(visited[u] == 1)
					visited[mat[u][i]] = 2;
				else
					visited[mat[u][i]] = 1;
				q.push(mat[u][i]);
			}
			if(visited[u] == visited[mat[u][i]])
				return false;
		}
		q.pop();
	}
	return true;
}

int main()
{
	int node, edge;
	while(scanf(" %d", &node) && node)
	{

		scanf(" %d", &edge);
		for(register int i = 0; i < 500; i++)
		{
			mat[i].clear();
			visited[i] = -1;
		}
		int x, y;
		fr(i, 0, edge)
		{
			scanf(" %d %d", &x, &y);
			mat[x].pb(y);
			mat[y].pb(x);
		}
		if(bipatite(0))
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
		fr(i, 1, edge+1) printf("%d : %d\n", i, visited[i]);
	}
	return 0;
}
