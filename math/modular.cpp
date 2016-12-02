#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
//for problem (N^P)%M, comlexity: O(log(base)2n)
long long M;

long long F(long long N, long long P)
{
		if(P==0)
			return 1;
		if(P%2==0)
		{
			long long ret = F(N, P/2);
			return ((ret%M) * (ret%M))%M;
		}
		else
			return ((N%M) * (F(N, P-1)%M))%M;
}

long long Q;
long long Pow(long long N, long long P)
{
	if(P == 0)
		return 1;
	if(P % 2 == 0)
	{
		long long ret = Pow(N, P/2);
		return ret*ret;
	}
	else
		return N * Pow(N, P-1);
	
}

int main()
{
	//problem : 100!%7 comlexity: O(log(base)2n)
	int fact = 1;
	
	for(int i = 1; i <= 100; i++)
	{
		printf("fact before %d for i = %d\n", fact, i);
		fact = ((fact%7)*(i%7))%7;
		printf("fact after %d\n", fact);
	}
	
	printf("%d\n", fact);
	printf("second problem\n\n\n\n");
	
	//problem : (a^b), complexity: O(log(base)2n)
	long long y = Pow(2, 50);
	printf("2^50 = %lld\n", y);

	//problem : (N^P)%M, comlexity: O(log(base)2n)
	
	M = 7;
	long long x = F(2, 100);
	
	printf("(2^100)mod7 = %lld\n", x);
	
	return 0;
	
}
