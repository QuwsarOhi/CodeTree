//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1637&mosmsg=Submission+received+with+ID+17979086
// f91 (10696)
#include <bits/stdc++.h>

using namespace std;

long f91(int x)
{
	if(x >= 101)
		return (x-10);
	else
		return f91(f91(x+11));
}

int main()
{
	int x;
	while(1)
	{
		scanf("%d", &x);
		if(x == 0)
			break;
		printf("f91(%d) = %ld\n", x, f91(x));
	}
	return 0;
}
