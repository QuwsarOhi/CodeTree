//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1753
//10812 - Beat the Spread!
#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int t;
	scanf("%d", &t);
	while(t--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(y > x)
			printf("impossible\n");
		else
		{
			int a = (x+y)/2;
			int b = x-a;
			if((a+b) == x && abs(a-b) == y)
				printf("%d %d\n", max(a, b), min(a, b));
			else
				printf("impossible\n");
		}
	}
	return 0;
}
