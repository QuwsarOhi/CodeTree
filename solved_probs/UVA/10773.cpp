//UVa
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1714
//10773 - Back to Intermediate Math

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for(register int i = 1; i <= t; i++)
	{
		double u, v, d, t1, t2;
		scanf(" %lf %lf %lf", &d, &v, &u);
		if((u < v) || (u == v) || (u == 0) || (v == 0))
		{
			printf("Case %d: can't determine\n", i);
			continue;
		}
		t1 = d/u;
		t2 = d/sqrt((u*u) - (v*v));
		printf("Case %d: %.3lf\n", i, t2-t1);
	}
	return 0;
}
