//UVa
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=82
//146 - ID Codes 

#include <bits/stdc++.h>

using namespace std;

int main()
{
	while(1)
	{
		char res[60], arr[60];
		fgets_unlocked(arr, 55, stdin);
		int len = strlen(arr);
		if(arr[0] == '#')
			break;
		copy(arr, arr+(len-1), res);
		next_permutation(res, res+(len-1));
		if(lexicographical_compare(arr, arr+(len-1), res, res+(len-1)))
		{
			for(register int i = 0; i < len-1; i++)
				printf("%c", res[i]);
			printf("\n");
		}
		else
			printf("No Successor\n");
	}
	return 0;
}
