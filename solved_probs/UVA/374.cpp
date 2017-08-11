//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=310&mosmsg=Submission+received+with+ID+17990968
// 374 - Big Mod

#include <bits/stdc++.h>

using namespace std;

unsigned long long pow(unsigned int n, unsigned int p, unsigned int d)
{
	if(p == 0)
		return 1;
	if(p % 2 == 0)
	{
		unsigned long long x = pow(n, p/2, d);
		return ((x%d) * (x%d))%d;
	}
	else
	{
		unsigned long long x = pow(n, (p-1), d);
		return ((n%d) * (x%d))%d;
	}
}

int main()
{
	long long x, p, d;
	
	while(scanf("%lld %lld %lld", &x, &p, &d) != EOF)
	{
		printf("%lld\n", pow(x, p, d));
	}
	
	return 0;
}
