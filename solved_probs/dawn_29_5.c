#include <stdio.h>

int main()
{
	char input[1000];
	
	gets(input);
	
	int i = 0;
	
	while(input[i] != NULL)
	{
		i++;
	}
	
	printf("%d", i);
	
	return 0;
	
}
