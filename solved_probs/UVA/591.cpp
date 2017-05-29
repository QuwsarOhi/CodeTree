//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=532
// Box of Bricks (591)

#include <bits/stdc++.h>

using namespace std;

bool com(int i, int j)
{
	return (i > j);
}

int main()
{
	register int set = 1;
	while(1)
	{
		int arr[52];
		register int t, sum = 0, swap = 0;
		scanf("%d", &t);
		if(t == 0)
			break;
		for(register int i = 0; i < t; i++)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		sum /= t;
		sort(arr, arr+t, com);
		for(register int i = 0; i < t; i++)
		{
			if(arr[i] > sum)
				swap += arr[i] - sum;
		}
		printf("Set #%d\n", set++);
		printf("The minimum number of moves is %d.\n\n", swap);
	}
	return 0;
}
