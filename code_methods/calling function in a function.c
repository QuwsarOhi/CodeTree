#include <stdio.h>

int process(int (*pf)(int, int))
{
	printf("process host\n");
	
	int a = 1, b = 2, c = 3;
	
	c = (*pf)(a, b);
	
	printf("returned value of c = %d\n", c);
	
	return(c);	
}

int funct1(int a, int b)
{
	int c = 0;
	printf("guest function funct1\n value of c = %d\n", c);
	printf("Value of a = %d\n Value of b = %d\n", a, b);
	
	return(c);
}

int funct2(int x, int y)
{
	int z = 49;
	printf("guest funct2\n value of z = %d\n", z);
	printf("Value of x = %d\n Value of y = %d\n", x, y);
	
	return(z);
}


int main()
{
	int i, j;
	i = 5, j = 6;
	
	printf("value of i = %d, value of j = %d\n", i, j);
	
	i = process(funct1);
	
	printf("After passing i, i = %d", i);
	
	j = process(funct2);
	
	printf("After calling, value of i = %d, value of j = %d\n", i, j);
	
	
	return 0;
}
