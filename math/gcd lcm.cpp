#include <iostream>
#include <cstdio>

using namespace std;

//gcd can be used by this for multiple values;
// gcd(a, gcd(b, c))
// lcm of a, b = (a*b)/gcd

int gcd(register int a, register int b)
{
	register int temp;
	
	while(b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	
	return a;
}

int main()
{
	int i = gcd(12, 16);
	
	printf("gcd = %d\n", i);
	printf("lcm = %d\n", (12*16)/i);
		
	return 0;
	
}
