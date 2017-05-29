//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1311&mosmsg=Submission+received+with+ID+17979241
// Above Average (10370)

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int t;
	scanf("%d", &t);
	
	while(t--)
	{
		register int n;
		scanf("%d", &n);
		int arr[n], count = 0;
		double percent = 0, avg = 0;
		for(register int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			avg += arr[i];
		}
		
		avg /= n;
		
		for(register int i = 0; i < n; i++)
			if(arr[i] > avg)
				count++;
		percent = ((double)count/(double)n)*100;
		
		//percent = (round(percent*10000))/10000;
		
		printf("%0.3lf%%\n", percent);
	}
	return 0;
}
