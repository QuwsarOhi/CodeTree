#include <stdio.h>

char arr[7];

void init()
{
	if((arr[0] == arr[3] || arr[0] == arr[4]) && (arr[1] == arr[3] || arr[1] == arr[4]))
	{
		if(arr[0] == arr[1])
		{
			printf("%c\n", arr[1]);
			return;
		}
		if(arr[0] > arr[1])
			printf("%c%c\n", arr[1], arr[0]);

		else
			printf("%c%c\n", arr[0], arr[1]);
		return;
	}
	
	if(arr[0] == arr[3] || arr[0] == arr[4])
	{
		printf("%c\n", arr[0]);
		return;
	}
	if(arr[1] == arr[3] || arr[1] == arr[4])
	{
		printf("%c\n", arr[1]);
		return;
	}	
	if((arr[0] != arr[3] && arr[0] != arr[4]) && (arr[1] != arr[3] && arr[1] != arr[4]))
	{
		printf("N\n");
		return;
	}
}

int main()
{
	int n;
	char b[2];
	
	scanf("%d", &n);
	fgets(b, 2, stdin);
	
	while(n--)
	{
		fgets(arr, 7, stdin);
		init();
	}
	
	return 0;
}

