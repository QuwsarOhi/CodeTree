#include <stdio.h>

int main()
{
	int input;
	
	while(scanf("%d", &input) != EOF)
	{
		int output[100], i = 0;
		
		while(input >= 1)
		{
			output[i] = input%2;
		    input = input/2;
			i++;
		}
		
		i--;
	
		while(i >= 0)
		{
			printf("%d", output[i]);
			i--;
		}
		
		if(i == -1)
		printf("\n");
	
	}
	
	return 0;
	
	
	
	
}
