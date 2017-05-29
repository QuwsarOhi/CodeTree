#include <stdio.h>
#include <time.h>

int * getRandom()
{
	static int r[10];
	
	int i;
	
	srand((unsigned)time(NULL));
	
	for (i = 0; i < 10; ++i)
	{
		r[i] = rand() % 10;
		printf("%d\n", r[i]);	
	}
	return r;
}

int main()
{
	int *p;
	int i2;
	p = getRandom();
	
	for(i2 = 0; i2 < 10; i2++)
	{
		printf("*(p + [%d]) : %d\n", i2, *(p + i2));
	}
	
	return 0;
}
