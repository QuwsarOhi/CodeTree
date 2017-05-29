// Program to calculate C(n ,k)
#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
//Space and Time efficient
//Complexity : O(k)
long long binomialCoeff(long long n, long long k)
{
    long long res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (long long i = 0; i < k; ++i)
    {
	//note: devide first then multiply to avoid overflow, decimal can be taken
	//after every calcualation round up the value
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main()
{

}
