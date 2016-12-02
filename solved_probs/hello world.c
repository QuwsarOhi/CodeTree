#include <stdio.h>


int main()
{
	signed int t1, t2, counter, sum, cse = 1;
	int input;
	
	while(scanf("%d", &input) != EOF)
	{
		t1 = 0;
		t2 = 1;
		sum = 0;
		counter = -1;
		
		if(input < 0)
		    break;
		
		else if(input == 1 || input == 0)
		    printf("0\n");
		
		else if(input > 1)
		{
			sum = t1 + t2;
			
			while(sum <= input)
			{
				t1 = t2;
				t2 = sum;
				sum = t1+ t2;
				counter ++;

			}
			
			printf("Case %d: %d\n", cse, counter);
			cse ++;
		}
	}
	
	return 0;
}
				
