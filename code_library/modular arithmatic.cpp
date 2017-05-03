//Complexity : O(logN)
#include <bits/stdc++.h>
using namespace std;

// (2^10 % 5) = powMod(2, 10, 5)
long long powMod(long long N, long long P, long long M)
{
	if(P==0)
		return 1;
	if(P%2==0) {
		long long ret = powMod(N, P/2, M)%M;
		return (ret * ret)%M;
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
    return 0;
}
