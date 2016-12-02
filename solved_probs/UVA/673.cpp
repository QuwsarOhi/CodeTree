#include <stdio.h>
#include <string.h>

int counter = 0;

void push(char stack[], char input)
{
	stack[counter] = input;
	counter++;
}

char top(char stack[])
{
	return stack[counter-1];
}

void pop(char stack[])
{
	stack[counter-1]= '\0';
	counter--;
}

int main()
{
	int m, n, o, i;
	
	scanf("%d", &n);
	scanf("%d", &o);
	
	for(m = 0; m <n; m++)
	{
		char stack[129];
		int len, flag;
	
		char input[129], convert;

		fgets(input, 129, stdin);

		len = strlen(input) - 2;
	
		for(i = 0; i <= len; i++)
		{
			if(input[i] == '(')
			{
				convert = '(' + 1;
				push(stack, convert);
			}
			else if(input[i] == '[')
			{
				convert = '[' +2;
				push(stack, convert);
			}
			else
			{
				if(top(stack) != input[i])
				{
					flag = 0;
				}
				else
				{
					pop(stack);
				}
			}
		}
	
		if(flag == 0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	
	
	return 0;
	
	
}
