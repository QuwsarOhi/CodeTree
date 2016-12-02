#include <stdio.h>

int factor(int n)
{
	if(n == 1)
	{
		return 1;
	}
	return n * factor(n-1);
	
	
}

int main()
{
	int n, x;
	
	printf("Enter a number:");
	scanf("%d", &n);
	
	x = factor(n);
	
	printf("%d! = %d", n, x);
	
	return 0;
}
