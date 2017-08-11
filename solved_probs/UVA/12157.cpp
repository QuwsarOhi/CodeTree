//UVa
//UVa 12157 - Tariff Plan

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int t;
	scanf("%d", &t);
	for(register int test = 1; test <= t; test++)
	{
		int n, mile = 0, juice = 0;
		scanf(" %d", &n);
		while(n--)
		{
			long x, y;
			scanf(" %ld", &x);
			y = x/30;
			if(y == ceil(y))
				y++;
			mile += y*10;
			y = x/60;
			if(y == ceil(y))
				y++;
			juice += y*15;
		}
		if(mile < juice)
			printf("Case %d: Mile %d\n", test, mile);
		else if(juice < mile)
			printf("Case %d: Juice %d\n", test, juice);
		else
			printf("Case %d: Mile Juice %d\n", test, juice);
	}
	return 0;
}
