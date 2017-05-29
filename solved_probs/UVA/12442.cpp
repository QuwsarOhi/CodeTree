//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3873
//12442 - Forwarding Emails

#include <bits/stdc++.h>

using namespace std;

//int sum[50002];

int dfs(int at, bool visited[], int node[], int sum[])
{
	//cout << "traversing : " << at << endl;
	if(visited[at] == true)
	{
		//cout << "ending in " << at << endl;
		return 0;
	}
	
	visited[at] = true;
	int counter = 0;
	counter++;
	
	if(visited[node[at]] == false)
	{
		//if(sum[node[at]] != -1)
			//counter += sum[node[at]];
		//else
			counter += dfs(node[at], visited, node, sum);
	}	
	visited[at] = false;
	
	return sum[at] = counter;
}


int main()
{
	int p;
	scanf("%d", &p);
	for(register int t = 1; t <= p; t++)
	{
		int n;
		scanf("%d", &n);
		bool visited[n+1];
		int sum[n+1];
		for(register int i = 0; i <=n; i++)
		{
			visited[i] = false;
			sum[i] = -1; // added line
		}
		int node[n+1];
		for(register int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			node[x] = y;
		}
		
		int max_val = 0, ind;
		
		for(register int i = 1; i <=n; i++)
		{
			int x;
			if(sum[i] == -1)
			{
				//cout << "going in " << i << endl;
				x = dfs(i, visited, node, sum);
			}
			//else
				//cout << "skipping " << i << " value set to " << sum[i] << endl;

			if(x > max_val)
			{
				max_val = x;
				ind = i;
			}
		}
		
		printf("Case %d: %d\n", t, ind);
	}
	return 0;
}
