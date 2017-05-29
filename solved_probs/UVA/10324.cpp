//UVa
//10324 - Zeros and Ones

#include <bits/stdc++.h>

using namespace std;

int main()
{
	char arr[1000015];
	register int c = 1; 
	while(scanf("%[^\n]s", arr) == 1)
	{
		if(strcmp(arr, "\n") == 0)
			break;
		int n, a, b;
		scanf(" %d", &n);
		printf("Case %d:\n", c);
		while(n--)
		{
			scanf(" %d %d", &a, &b);
			if(a>b)swap(a, b);
			bool ok = true;
			for(register int i = a; i < b; i++)
				if(arr[i] != arr[i+1])
				{
					ok = false;
					break;
				}
			if(ok)
				printf("Yes\n");
			else
				printf("No\n");
		}
		c++;
		cin.ignore();
	}
	return 0;
}
