//Managing subsets the easiest way
//Complexity: 2^n
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int len;
	scanf(" %d", &len);
	int arr[len+1];
	for(register int i = 0; i < len; i++)
		scanf(" %d", &arr[i]);
	for(register int i = 0; i < (1 << len); i++)
	{
		for(register int j = 0; j < len; j++)
			if(i & (1 << j))
				printf("%d ", arr[j]);
		printf("*\n");
	}
	return 0;
}
