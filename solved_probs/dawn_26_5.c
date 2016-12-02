#include <stdio.h>

int main()
{
	int input, i, sum;
	
	while(scanf("%d", &input) != EOF)
	{
		if(input <= 0) break;
		
		for(i = 1; i <= input; i++)
		{
			if(i == 1)
			{
				printf("1 -");
				sum = 1;
			}
			
			else if(i < input && i != 1 && (i % 2) == 0)
			{
				printf("% d +", i);
				sum -= i;
			}
			else if(i <input && i != 1 && (i % 2) != 0)
			{
				printf(" %d -", i);
				sum += i;
			}
			
			else if( i== input && (i % 2) != 0)
			{
				sum += i;
				printf(" %d = %d\n", i, sum);
			}
			
			else if( i== input && (i % 2) == 0)
			{
				sum -= i;
				printf(" %d = %d\n", i, sum);
			}
		}
		
	}
	
	return 0;
	
}
