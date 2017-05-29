//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=235&mosmsg=Submission+received+with+ID+17983972
//299 - Train Swapping

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int t;
	scanf("%d", &t);
	while(t--)
	{
		register int l, count = 0;
		scanf("%d", &l);
		int x[l];
		for(register int i = 0; i < l; i++)
			scanf("%d", &x[i]);
		for(register int i = 0; i < l; i++)
			for(register int j = i+1; j < l; j++)
			{
				if(x[i] > x[j])
				{
					count++;
					//printf("swapped %d %d\n", i, j);
					swap(x[i], x[j]);
					//for(register int k = 0; k < l; k++)
						//printf("%d ", x[k]);
					//printf("\n");
				}
			}
		printf("Optimal train swapping takes %d swaps.\n", count);
	}
	return 0;
}
