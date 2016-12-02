#include <stdio.h>

int main()
{
	int i, sum = 1, n;
	
	printf("Enter a number:");
	scanf("%d", &n);
	
	
	for(i = 1; i <= n; i++)
		sum *= i;
		
	printf("%d! = %d", n, sum);
	
	return 0;
}
