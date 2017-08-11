//Complexity : O(logN)
#include <bits/stdc++.h>
using namespace std;

// (2^10 % 5) = powMod(2, 10, 5)
long long powMod(long long N, long long P, long long M)
{
	if(P==0)
		return 1;
	if(P%2==0) {
		long long ret = powMod(N, P/2, M);
		return ((ret%M) * (ret%M))%M;
	}
	else
		return ((N%M) * (powMod(N, P-1, M)%M))%M;
}

// 2^100 = Pow(2, 100)
unsigned long long Pow(unsigned long long N, unsigned long long P)
{
	if(P == 0)
		return 1;
	if(P % 2 == 0)
	{
		unsigned long long ret = Pow(N, P/2);
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
