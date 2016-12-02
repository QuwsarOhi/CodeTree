#include <stdio.h>

int lenofint(int i)
{
	int j = 0;
	
	if(i == 0)
	return 1;
	
	while(i != 0)
	{
		i /= 10;
		j++;
	}
	return j;
}

void inttoarray(int x[], int len, int input)
{
	len--;
	
	while(len >= 0)
	{
		x[len] = (input%10);
		input /= 10;
		len--;	
	}
}

void oct_to_bin(int x)
{
	int reminder[3], i = 2;
	if(x <= 3)
	{
		if(x == 0)
		printf("000");
		else if(x == 1)
		printf("001");
		else if(x == 2)
		printf("010");
		else
		printf("011"); 
	}
	else
	{
		while(x != 0 && i >= 0)
		{
			reminder[i] = x%2;
			x /= 2;
			i--;
		}
		
		reminder[3] = 0;
		
		for(i=0; i<3; i++)
		printf("%d", reminder[i]);
	}
}

int main()
{
	int input, len, i=0;
	int x[50];
	
	scanf("%d", &input);
	
	len = lenofint(input);
	
	inttoarray(x, len, input);
	
	while(i < len)
	{
		oct_to_bin(x[i]);
		i++;
	}
	
	return 0;
	
}
