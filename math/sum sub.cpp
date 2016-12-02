#include <iostream>
#include <cstdio>

using namespace std;

int sum(register int a, register int b)
{
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	
	while(b != 0)
	{
		register int carry = a & b;
		a ^= b;
		b = carry << 1;
	}
	
	return a;
}

int sub(int a, int b)
{
	return sum(a, sum(~b, 1));
}

int main()
{
	int a = 4, b = 5;
	
	printf("%d\n", sum(a, b));
	
	printf("%d\n", sub(a, b));
	
	return 0;
}
