#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int N = 100, prime[100];
int status[100/2];

bool check(int N, int pos)
{
	return (bool)(N & (1 << pos));
}

int set(int N, int pos)
{
	return N = N | (1 << pos);
}

void sieve()
{
	int i, j, sqrtN;
	sqrtN = int(sqrt(N));
	
	for(i = 3; i <= sqrtN; i+=2)
	{
		printf("i is %d\n", i);
		if(check(status[i/32], i%32) == 0)
		{
			for(j = i * i; j <= N; j += 2 * i)
			{
				printf("%d setting to prime\n", j);
				status[j/32]=set(status[j/32], j % 32);
			}
		}
	}
		
	puts("2");
	for(i = 3; i<=N; i+= 2)
		if( check(status[i/32], i%32) == 0)
			printf("%d\n", i);
}

int main()
{
	sieve();
	
	return 0;
	
}
