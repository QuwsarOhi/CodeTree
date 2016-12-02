#include <stdio.h>

int main()
{
    int input[100], i, counter = 0, counter_memory = 0;
    int n, m = 0;
    
   scanf("%d", &n);
    
    while(m < n)
    {
		printf("input");
		scanf("%d", &input[m]);
		m++;
	}
    

    for(i = 0; i < 100; i += 1)
    {
		printf("loop");
		if(input[i] == input[i+1])
		{
			    counter += 1;
				printf("*");
				printf("%d", counter);
		}
			
		
		else
		{
			printf("-");
			
			if(counter > 0)
			{
				if(counter > counter_memory)
				counter_memory = counter;
			}
			
			counter = 0;
			
		}
		

    
    }
    if(counter > counter_memory)
		counter_memory = counter;
	if(counter_memory >= 1)
	counter_memory ++;
		
    printf("Highest: %d", counter_memory);
    
    return 0;
    
}
