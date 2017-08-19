//UVa
//10219 - Find the ways !

#include<bits/stdc++.h>
using namespace std;
// Returns value of Binomial Coefficient C(n, k)
long long binomial(long long n, long long k)
{
    double res = 0;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (long long i = 0; i < k; ++i)
        res += log10(n - i) - log10(i+1);       //the number counting trick with log
    res = floor(res) + 1;
    return (long long)res;
}

/* Drier program to test above function*/
int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    long long n, k;
    while(scanf("%lld %lld", &n, &k) != EOF)
        printf("%lld\n", binomial(n, k));
    return 0;
}
