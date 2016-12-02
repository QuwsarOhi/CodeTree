#include <stdio.h>
#include <math.h>




int main()
{
	int input;
	long long i, j;

	while( scanf("%d", &input) != EOF)
	{
		if(input <= 0)
		    break;

		for(i = 0; i <= input; i++)
		{
			if(i == 1)
			    printf("%.0llu +", i);

			else if(i < input && i > 1)
			{
				j = i;
				j =(long long)powl(j , j);
				printf(" %.0llu +", j);
			}

			else if(i == input)
			{
				j = i;
				j = (long long)powl(j, j);
				printf(" %.0llu", j);
			}

		}

	}

	return 0;

}
