//Uva
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=36
// 3n+1 (100)

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	register int count1, count2;
	while(scanf("%d %d", &a, &b) != EOF)
	{
		count2 = 0;
		int mi = min(a, b);
		int mx = max(a, b);
		for(register int i = mi; i <= mx; i = ++mi)
		{
			count1 = 1;
			while(1)
			{
				if(i == 1)
					break;
				if(i % 2 == 0)
					i = i / 2;
				else
					i = (3*i)+1;
				count1++;
			}
			count2 = max(count1, count2);
		}
		printf("%d %d %d\n", a, b, count2);
	}
	return 0;
}
