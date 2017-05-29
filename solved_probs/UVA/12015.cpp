//UVa
//12015 - Google is Feeling Lucky

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int t;
	scanf(" %d", &t);
	for(register int p = 1; p <= t; p++)
	{
		int node[10];
		map<int, string> mp;
		int mx = 0;
		for(register int i = 0; i < 10; i++)
		{
			char arr[150];
			int val;
			scanf(" %s %d", arr, &val);
			mp[i] = string(arr);
			node[i] = val;
			mx = max(val, mx);
		}
		
		printf("Case #%d:\n", p);
		for(register int i = 0; i < 10; i++)
		{
			if(mx == node[i])
			{
				string x = mp[i];
				printf("%s\n", &(x[0]));
			}
		}
	}
	return 0;
}
