#include <stdio.h>
#include <string.h>

int perm(int i)
{
	int j = 1, mul = 1;
	
	while(j <= i)
	{
		mul *= j;
		j++;
	}
	
	return mul;
	
	
}

void swap(char input[], int i, int j)
{
	char temp;
	
	temp = input[i];
	input[i] = input [j];
	input[j] = temp;
	
}



int main()
{
	char input[50];
	int len, permo, i, place;
	i = 0;
	place = 0;
	
	fgets(input, 50, stdin);
	
	len = strlen(input) - 1;
	input[len] = 0;
	
	permo = perm(len);
	
	while(i < permo)
	{
		if(place+1 > len-1)
			place = 0;
		
		swap(input, place, place+1);
		printf("%d: %s\n", i+1, input);
		i++;
		place++;

	}
	
	return 0;
}
