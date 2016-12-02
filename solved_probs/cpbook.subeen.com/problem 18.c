#include <stdio.h>
#include <math.h>

double pi = acos(-1);


int main()
{
	int n, r, a, b;
	
	scanf("%d", &n);
	
	while(n--)
	{
		scanf("%d%d%d", &r, &a, &b);
		if((pi*r*r <= a*b) && ((r + r) <= a) && ((r + r) <= b))
			printf("YES\n");
		else
			printf("NO\n");
			
	}
	
	return 0;
}

