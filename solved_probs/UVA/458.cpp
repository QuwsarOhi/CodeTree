//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=399
// The Decoder (458)

#include <bits/stdc++.h>

using namespace std;

int main()
{
	char x[500];
	char y;
	while(fgets(x, 498, stdin))
	{
		int len = strlen(x);
		for(register int i = 0; i < len-1; i++)
		{
			y = x[i] - 7;
			printf("%c", y);
		}
		printf("\n");
	}
	return 0;
}
