//Codechef Beginner
//Url : https://www.codechef.com/problems/FLOW004

#include <cstdio>

int main()
{
	register int t, x, y, z;
	for(scanf("%d", &t); t--; )
	{
		scanf("%d", &x);
		y = 0;
		y += x%10;
		do{
			z = x;
			x /= 10;
		}while(x);
		y += z;
		printf("%d\n", y);
	}
	return 0;
}
