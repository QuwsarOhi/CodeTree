//UVa
//991 - Safe Salutations
//Producing Catalan number in O(n) time

#include<bits/stdc++.h>
using namespace std;

long long C(int n, int k)
{
    //Complexity O(k)

    long long c = 1;
    if(k > n - k)
        k = n-k;
    for(int i = 0; i < k; i++) {
        c *= (n-i);
        c /= (i+1);
    }
    return c;
}

long long catalan(int n)
{
    //Cat(n) = C(2*n, n)/(n+1);

    long long c = C(2*n, n);
    return c/(n+1);
}

int main()
{
    int n;
    bool first = 1;
    while(scanf("%d", &n) != EOF) {
        if(!first)
            printf("\n");
        first = 0;
        printf("%lld\n", catalan(n));
    }
    return 0;
}
