//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1241&mosmsg=Submission+received+with+ID+17983873
// Ecological Premium (10300)

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int t;
	scanf("%d", &t);
	while(t--)
	{
		register int f;
		register int sum = 0;
		scanf("%d", &f);
		while(f--)
		{
			register int s, a, e;
			scanf("%d %d %d", &s, &a, &e);
			sum += (s*e);
		}	
		printf("%d\n", (int)sum);
	}
	return 0;
}
