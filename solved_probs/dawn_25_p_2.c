#include <stdio.h>

int star(int i, int j)
{
	
	while(j <= i)
	{
		printf("*");
		
		if(j == i)
		    printf("\n");

		j++;
		
	}
}

int dot(int i, int j)
{
	int n, m = 0;
	n = i - j;
	
	while(m < n)
	{
		printf(".");
		m++;
	}
	
}


int main()
{
	int input, i, n, star_counter;
	
	while(scanf("%d", &input) != EOF)
	{
		i = 1;
		n = input;
		star_counter = 1;
		
		while(n >= i)
		{
			dot(input, n);
			star(input, star_counter);
			n--;
			star_counter++;
		}
	}
	
	return 0;
	
}
