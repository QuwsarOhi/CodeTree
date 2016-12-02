#include <stdio.h>

int main()
{
	int array[5] = {0}, i, x, flag;
	
	for(i = 0; i < 5; i++)
	{
		printf("Enter a number:");
		scanf("%d", &array[i]);	
	}
	
	printf("Enter the number to be searched:");
	scanf("%d", &x);
	
	for(i = 0; i < 5; i++)
	{
		if(array[i] == x)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
		printf("The number %d appears in the first 5 numbers", x);
	else
		printf("The number %d does not appear in the first 5 numbers", x);
	
	return 0;
	
}
