//UVa
//10986 - Sending email

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
#define inf (2^32) - 1
using namespace std;

vec adj[20500];
vec cost[90000];
int node, edge, s, t, dis[20500];

void dijkstra()
{
	//int distance[node+10];
	memset(dis, inf, sizeof(dis));
	priority_queue<pair<int, int> >pq;
	dis[s] = 0;
	pq.push(mp(s, dis[s]));
	while(!pq.empty())
	{
		int u = pq.top().first; //d = pq.top().second;
		pq.pop();
		//printf("working\n");
		for(unsigned int v = 0; v < adj[u].size(); v++)
		{
			if(dis[u] + cost[u][v] < dis[adj[u][v]])
			{
				dis[adj[u][v]] = dis[u] + cost[u][v];
				pq.push(mp(adj[u][v], dis[adj[u][v]]));
			}
		}
		//if(u == t)
			//return;
	}
}

int main()
{
	register int test;
	scanf(" %d", &test);
	for(register int p = 1; p <= test; p++)
	{
		memset(cost, 0, sizeof(cost));
		memset(adj, 0, sizeof(adj));
		scanf(" %d %d %d %d", &node, &edge, &s, &t);
		fr(i, 0, edge)
		{
			int x, y, c;
			scanf(" %d %d %d", &x, &y, &c);
			adj[x].pb(y);
			adj[y].pb(x);
			cost[x].pb(c);
			cost[y].pb(c);
		}
		dijkstra();
		if(dis[t] < 100000)
			printf("Case #%d: %d\n", p, dis[t]);
		else
			printf("Case #%d: unreachable\n", p);
		//printf("%d\n", t);
	}
	return 0;
}
