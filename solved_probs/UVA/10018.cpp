//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=959
// Reverse and Add (10018)

#include <bits/stdc++.h>

using namespace std;

long reverse(long in)
{
	long temp = 0;
	while(in)
	{
		temp *= 10;
		temp += in%10;
		in /= 10;
	}
	
	return temp;
}

int main()
{
	register int t;
	scanf("%d", &t);
	while(t--)
	{
		long inp, counter = 0;
		scanf("%ld", &inp);
		while(inp != reverse(inp))
		{
			inp += reverse(inp);
			counter++;
		}
		printf("%ld %ld\n", counter, inp);
	}
	return 0;
}
