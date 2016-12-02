#include <stdio.h>


int main()
{
	unsigned int i;
	int input;
	
	while(scanf("%d", &input) != EOF)
	{
		if(input <= 0) break;
		
		for(i=1; i<=input; i++)
		{
			if(i == 1)
			    printf("1 +");
			else if(i > 1 && i <input)
			    printf(" %d +", i);
			else if(i == input)
			    printf(" %d\n", i);
		}
	}
	
	return 0;
}
