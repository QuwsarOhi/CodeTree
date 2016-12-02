#include <stdio.h>
#include <string.h>

int arrsrch(int i, int j, char find[], char input[])
{
	int n = 0;
	int value=1;
	char mem[50];
	while(n <= j)
	{
		if(n == j)
		{    
			mem[n] = 0;
			n++;
		}
		else
		{
			mem[n] = input[i];
			n++;
			i++;
		}
	}
	
	value = strcmp(mem, find);
	
	if(value == 0)
	return 1;
	
	else
	return 0;
}
	
int main()
{
	
	char input[100];
	char find[50];
	int len, i, counter=0;
	
	fgets(input, 100, stdin);
	fgets(find, 50, stdin);
	
	len = strlen(find);
	
	find[len-1] = 0;
	
	
	for(i = 0; i<strlen(input)-1; i++)
	{		
		if(input[i] == find[0])
		{
			if(arrsrch(i, len-1, find, input) == 1)
			{
				counter++;
			}
			
		}
	}
	
	if(counter == 0)
	printf("Not Found");
	
	else
	printf("Found %d times!", counter);
	
	return 0;
	
}
	
	
