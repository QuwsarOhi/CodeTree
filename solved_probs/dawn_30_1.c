#include <stdio.h>
#include <string.h>


int main()
{
	char x[100];
	char y[100];
	
	while(1)
	{
		scanf("%s", x);
		scanf("%s", y);
		
		strcat(x, y);
		
		printf("%s", x);
		
		return 0;
	}
}
