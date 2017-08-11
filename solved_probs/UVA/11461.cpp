//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2456&mosmsg=Submission+received+with+ID+17984034
// 11461 - Square Numbers

#include <bits/stdc++.h>

using namespace std;

int main()
{
	while(1)
	{
		double a, b;
		scanf("%lf %lf", &a, &b);
		if(a == 0 && b == 0)
			break;
		register int count = 0;
		for(register int i = a; i <= b; i++)
		{
			double x = sqrt(i);
			if((x - ((int)x)) == 0)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
