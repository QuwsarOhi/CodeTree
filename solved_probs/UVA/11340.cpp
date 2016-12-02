//UVa
//11340 - Newspaper

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int t;
	scanf(" %d", &t);
	getchar();
	while(t--)
	{
		register int w;
		register double sum = 0;
		map<char, double>mp;
		char arr[1000000];
		scanf(" %d", &w);
		getchar_unlocked();
		while(w--)
		{
			char x;
			int p;
			scanf(" %c %d", &x, &p);
			//printf("%c %d\n", x, p);
			mp[x] = (((double)p)/100.0);
			//printf("%c set to %lf\n", x, mp[x]);
		}
		register int l;
		scanf(" %d", &l);
		getchar_unlocked();
		while(l--)
		{
			register int len = 0;
			register char x;
			while(1)
			{
				x = getchar_unlocked();
				if(x == '\n')
					break;
				else
					arr[len++] = x;
			}
			for(register int i = 0; i < len; i++)
				if(mp.find(arr[i]) != mp.end())
					sum += mp[arr[i]];
		}
		/*if(t == 0)
			printf("%.2lf$.", sum);
		else*/
		printf("%.2lf$\n", sum);
	}
	return 0;
}
