#include <stdio.h>

int brace(int b)
{
	int c = 1, x = b;
	printf(" (");
	while(c <=  b)
	{
		if(c == b)
		{
			printf(" %d ", x);
			c++;
		}
		else
		{
			printf(" %d +", x);
			x++;
			c++;
		}
	}
	printf(") ");
	
	return sum;
}


int main()
{
	int input;
	unsigned sum = 0, i, j;
	
	while( scanf("%d", &input) != EOF)
	{
		if(input <= 0)
		    break;
		    
		for(i = 1; i <= input; i++)
		{
			if(i == 1)
			    printf("%d", i);
			    
			if(i < input && i != 1)
			{
				j = i;
				printf(" +");
				sum += brace(j);
			}
			
			if(i == input)
			{
				j = i;
				printf("+");
				sum += brace(j);
				printf("\n");
			}
			
		}
	}
	
	return 0;
}
			
