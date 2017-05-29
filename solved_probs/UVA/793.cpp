//UVa
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=734&mosmsg=Submission+received+with+ID+18094653
//793 - Network Connections
#include <bits/stdc++.h>

using namespace std;

int root(int arr[], int x)
{
	if(arr[x] == x)
		return x;
	else
		return arr[x] = root(arr, arr[x]);
}

int main()
{
	register int t;
	scanf(" %d", &t);
	bool frst = false;
	while(t--)
	{
		int len;
		scanf(" %d", &len);
		getchar_unlocked();
		int arr[len+1], size[len+1];
		register int r = 0, w = 0;
		for(register int i = 0; i < len+1; i++)
		{
			arr[i] = i;
			size[i] = 1;
		}
		while(1)
		{
			char x = getchar_unlocked();
			int a, b;
			if(!isalpha(x))
				break;
			scanf(" %d %d", &a, &b);
			getchar_unlocked();
			if(x == 'c')
			{
				int r1 = root(arr, a), r2 = root(arr, b);
				if(size[r1] < size[r2])
				{
					arr[r1] = arr[r2];
					size[r2] += size[r1];
				}
				else
				{
					arr[r2] = arr[r1];
					size[r1] += size[r2];
				}
			}
			else
			{
				if(root(arr, a) == root(arr, b))
					r++;
				else
					w++;
			}
		}
		if(frst)
			printf("\n");
		frst = true;
		printf("%d,%d\n", r, w);
	}
	return 0;
}
