#include <stdio.h>

int main()
{
	printf("File : %s\n", __FILE__);
	printf("Date : %s\n", __DATE__);
	printf("Time : %s\n", __TIME__);
	printf("ANSI : %d\n", __STDC__);
	printf("Line : %d\n", __LINE__);
	
	return 0;
	
}
