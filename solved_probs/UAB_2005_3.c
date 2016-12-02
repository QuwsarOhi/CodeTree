#include <stdio.h>
#include <math.h>

int len(int input)
{
	int len_flag = 0;

	while(input != 0)
	{
		input /= 10;
		len_flag++;
	}

	return len_flag;
}

void breaker(int input, int len, int array[])
{
	int i = 0;
	int array_mem[20];

	while(input != 0)
	{
		array_mem[i] = input%10;
		input /= 10;
		array[len] = array_mem[i];
		len--;
		i++;
	}
}


int main()
{
	int i=0, length, input;
	int array[20] = {0};
	scanf("%d", &input);

	length = len(input);
	breaker(input, length, array);
	while(length > 0)
	{
		length--;
		array[i] = pow(array[i], length);
		i++;
	}
	printf("%d", array);
	return 0;
}
