#include <stdio.h>

int main()
{
	long int n, m;
	
	while(scanf("%ld %ld", &n, &m) != EOF)
	{
		if(m > n)
		    printf("%ld\n", m - n);
		else
	        printf("%ld\n", n - m);
	}
	 
	 
	    
	return(0);
}
