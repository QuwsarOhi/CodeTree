//UVa
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=540
//599 - The Forrest for the Trees
#include <bits/stdc++.h>

using namespace std;

int arr[28], size[28], visited[28], on[28];

int root(int x)
{
	if(arr[x] == x)
		return x;
	return arr[x] = root(arr[x]);
}

int main()
{
	register int t;
	scanf("%d", &t);
	while(t--)
	{
		unordered_map<int, int>cir;
		map<int, int>mp;
		register int tree = 0, acr = 0;
		for(register int i = 0; i < 28; i++)
		{
			arr[i] = i;
			size[i] = 0;
			visited[i] = 0;
			on[i] = 0;
		}
		char a, b, c, d, e;
		while(1)
		{
			scanf(" %c", &a);
			if(a == '*')
				break;
			scanf(" %c %c %c %c", &b, &c, &d, &e);
			int root_a = root(int(b) - 64), root_b = root(int(d) - 64);
			if(root_a == root_b)
				cir[root_a] = 1;;
			if(size[root_a] > size[root_b])
			{
				arr[root_b] = arr[root_a];
				size[root_a] += size[root_b];
				if(cir.find(root_b) != cir.end())
				{
					cir.erase(root_b);
					cir[root_a] = 1;
				}
			}
			else
			{
				arr[root_a] = arr[root_b];
				size[root_b] += size[root_a];
				if(cir.find(root_a) != cir.end())
				{
					cir.erase(root_a);
					cir[root_b] = 1;
				}
			}

		}
		char x;
		do{
			x = getchar();
		}while(x == '*');
		do{
			x = getchar();
			if(isalpha(x))
				on[int(x) - 64] = 1;
		}while(isalpha(x) || x == ',');
		for(register int i = 1; i < 27; i++)
		{
			if(on[i])
				mp[root(i)] += 1;
		}
		for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if(cir.find(it->first) == cir.end())
			{
				if(it->second > 1)
					tree++;
				else
					acr++;
			}
				
		}
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acr);
	}
	return 0;
}
