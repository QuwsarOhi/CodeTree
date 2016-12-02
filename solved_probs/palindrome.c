#include <stdio.h>

int main()
{
	long int n, i, tmp, hex, rem;

	scanf("%ld", &n);

	tmp = 0;
	i = 1;
	hex = i;

	while(i <= n)
	{
		while( n!=0 )
		{
			rem = i%10;
			tmp = tmp*10 + rem;
			i/= 10;
		}
		if(tmp == hex)
		{
			printf("%ld ", hex);
		}
		i++;
	}
	return(0);
}
