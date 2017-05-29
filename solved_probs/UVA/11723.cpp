//UVa
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2823&mosmsg=Submission+received+with+ID+18100651
//11723 - Numbering Roads

#include <bits/stdc++.h>

using namespace std;

int main()
{
	for(register int i = 1; ; i++)
	{
		double r, k, n;
		scanf(" %lf %lf", &r, &k);
		if(r == 0 || k == 0)
			break;
		n = ceil(r/k) - 1;
		if(n <= 26)
			printf("Case %d: %d\n", i, int(n));
		else
			printf("Case %d: impossible\n", i);
	}
	return 0;
}
