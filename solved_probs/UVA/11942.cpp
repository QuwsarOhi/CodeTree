//UVa
//UVa 11942 - Lumberjack Sequencing

#include <bits/stdc++.h>

using namespace std;

class cmp
{
	public:
	int operator() (int a, int b)
	{
		return a > b;
	}
};

int main()
{
	register int t;
	scanf("%d", &t);
	printf("Lumberjacks:\n");
	while(t--)
	{
		int arr[10];
		bool high = true, low = true;
		for(register int i = 0; i < 10; i++)
			scanf(" %d", &arr[i]);
		int arrh[10], arrl[10];
		copy(arr, arr+10, arrh);
		copy(arr, arr+10, arrl);
		sort(arrl, arrl+10);
		sort(arrh, arrh+10, cmp());
		
		for(register int i = 0; i < 10; i++)
			if(arr[i] != arrl[i])
				low = false;
		for(register int i = 0; i < 10; i++)
			if(arr[i] != arrh[i])
				high = false;
		if(high || low)
			printf("Ordered\n");
		else
			printf("Unordered\n");
	}
	return 0;
}
