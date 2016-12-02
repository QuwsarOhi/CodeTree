#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	register int x;
	register char arr[4];
	arr[4] = 0;
	
	scanf("%d", &x);
	
	fgets(arr, 2, stdin);
	
	while(x--)
	{
		fgets(arr, 4, stdin);
		printf("%d\n", arr[0] + arr[1] + arr[2]);
		fgets(arr, 4, stdin);
	}
	return 0;
	
}

