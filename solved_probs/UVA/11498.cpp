//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2493
//11498 - Division of Nlogonia

#include <bits/stdc++.h>

using namespace std;

int main()
{
	while(1)
	{
		register int t;
		scanf("%d", &t);
		if(t == 0)
			break;
		int x, y;
		scanf("%d %d", &x, &y);
		while(t--)
		{
			int i, j;
			scanf("%d %d", &i, &j);
			if(i > x && j > y)
				printf("NE");
			else if(i < x && j > y)
				printf("NO");
			else if(i < x && j < y)
				printf("SO");
			else if(i > x && j < y)
				printf("SE");
			else
				printf("divisa");
			if(t > 0)
				printf("\n");
		}
		printf("\n");
	}
	return 0;
}
