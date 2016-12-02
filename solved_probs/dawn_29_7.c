#include <stdio.h>

int main()
{
	char x[100];
	int i;
	
	
	fgets(x, 100, stdin);
	
	
	for(i = 0; i<= 100 && x[i] != NULL; i++)
	{
		if(x[i] >= 'A' && x[i] <= 'Z')
		    continue;
		if(x[i] >= 'a' && x[i] <= 'z')
		    x[i] = x[i] - 'a' + 'A';
		else
		    continue;
	}
	
	printf("%s", x);
	
	return 0;
	
}
