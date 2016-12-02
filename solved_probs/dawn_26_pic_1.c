#include <stdio.h>

int star(int i)
{
	int n = 1;
	
	while(n <= i)
	{
		printf("*");
		n++;	
	}
}

int dot(int i, int x)
{
	int n, m = 0;
	
	n = i - x;
	
	while(m < n)
	{
		printf(".");
		if( m == (n-1))
		    printf("\n");
		m++;
	}
}

int main()
{
	int n, i;
	
	
	while(scanf("%d", &n) != EOF)
	{
		i = 1;
		
		while(i <= n)
		{
			star(i);
			dot(n , i);
			
			if(i == n)
			    printf("\n");
			i++;
		}
	}
	
	return 0;

}
