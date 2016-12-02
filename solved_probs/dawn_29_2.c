#include <stdio.h>
#include <math.h>

int main()
{
	int input[100], x, i = 0, sum = 0;

	scanf("%d", &x);

	while(i < x)
	{
		scanf("%d", &input[i]);
		i++;
	}

	i = 0;
	x--;


    while( x >= 0 )
    {
        sum = sum + (input[i] * pow(2, x));
        i++;
        x--;

    }

    printf("%d", sum);

	return 0;



}
