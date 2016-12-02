#include <stdio.h>

int num(int i, int j)
{
	int x = 1;
	int upcounter = 1; /*upcounter 1 for true, 0 for false*/
	
	while(x <= j && upcounter == 1)
	{
		printf("%d", x);
		x++;
		
		if( x == j)
		    upcounter = 0;
	}
	
	while( x <= j && x!=0)
	{
		printf("%d", x);
		x--;
	}
	

	
}

int dot(int i, int j, int dot_spacer)
{
	
	while(j <= i)
	{
		printf(".");
		j++;
	}
	
	
	if((dot_spacer%2) == 0)
	    printf("\n");
	
	
}

int main()
{
	int input, i, mat_input, x;
	
	while(scanf("%d", &input) != EOF)
	{
		int dot_spacer = 1;
		i = 1;
		
		if(input % 2 == 0)
		{
			printf("Input must be odd!\n");
			continue;
		}
		
		mat_input = ((input - 1)/2) + 1;
		x = (input-1)/2;
		
		while(i <= mat_input)
		{
			dot(x, i, dot_spacer);
			dot_spacer++;
			num(input, i);
			dot(x, i, dot_spacer);
			dot_spacer--;		
			i++;
		}
			
		mat_input--;
			
		while(mat_input >= 1)
		{
			dot(x, mat_input, dot_spacer);
			dot_spacer++;
			num(input, mat_input);
			dot(x, mat_input, dot_spacer);
			dot_spacer--;
			mat_input--;
		}
	}
	
	return 0;
}
