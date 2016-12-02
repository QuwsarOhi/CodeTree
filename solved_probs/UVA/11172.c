#include <stdio.h>

int main()
{
	int x, i = 1;
	int a, b;
	
	scanf("%d", &x);
	
	while(i <= x)
	{
		scanf("%d %d", &a, &b);
		if(a > b)
		printf(">\n");
		else if(a < b)
		printf("<\n");
		else
		printf("=\n");
		
		i++;
	
	}
	
	return 0;
	
}
