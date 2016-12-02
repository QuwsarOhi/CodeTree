//Codechef Biggener
//Url: https://www.codechef.com/problems/REMISS

#include <cstdio>

int main()
{
	register int t, a, b;
	for(scanf("%d", &t); t--;)
	{
		scanf("%d %d", &a, &b);
		printf("%d %d\n",a>b? a:b, a+b);
	}
	return 0;
}
