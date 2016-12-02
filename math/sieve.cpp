#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int status[60000];

void siv()
{
	int N = 100;
	int sq = sqrt(N);
	for(int i = 4; i <= N; i+=2)
	{
		printf("setting %d to non-prime \n", i);
		status[i] = 1;
	}
	for(int i= 3; i<=sq; i+=2)
	{
		printf("%d\n", i);
		if(status[i] == 0)
		{
			for(int j = i*i; j <= N; j+=(i*2))
			{
			printf("setting %d to non-prime \n", j);
				status[j]=1;
			}
		}
	}
	status[1] = 1;
}

int main()
{
	siv();
	printf("23 is %d\n", status[23]);
	printf("2 is %d\n", status[2]);
	printf("4 is %d\n", status[4]);
	printf("17 is %d\n", status[17]);
	printf("18 is %d\n", status[18]);
	
	
	
	return 0;
	
	
}
