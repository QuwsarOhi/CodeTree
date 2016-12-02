#include <stdio.h>

int main()
{
	int input;
	unsigned i, j;
	
	while( scanf("%d", &input) != EOF)
	{
		
		if(input <= 0) break;
		
		for(i = 1; i <= input; i++)
		{
			if(i == 1)
			{
			    printf("1 +");
			}
			if(i < input && i > 1)
			{
				j = i;
				j *= j;
				printf(" %d +", j);
			}
			
			if(i == input)
			{
				j = i;
				j *= j;
				printf(" %d\n", j);
			}   
		}
	}
	
	return 0;
	
}
