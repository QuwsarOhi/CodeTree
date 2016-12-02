//UVa
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1048&mosmsg=Submission+received+with+ID+18095917
//10107 - What is the Median?

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int len = 1;
	int arr[10010];
	while(scanf(" %d", &arr[len]) != EOF)
	{
		sort(arr+1, arr+(len+1));
		//cout << "cout :  " << len << endl;
		if(len == 1)
		{
			printf("%d\n", arr[1]);
		}
		else if(len % 2 == 0)
		{
			int a = (len)/2;
			int b = a++;
			printf("%d\n", (arr[a]+arr[b])/2);
		}
		else
			printf("%d\n", arr[(len/2)+1]);
		len++;
	}
	return 0;
}
