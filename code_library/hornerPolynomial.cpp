#include <bits/stdc++.h>
using namespace std;

int co_efficient[1000];

//finds first solution for polynomial equations
//co_efficients contains the co_effecients (power) of i'th term
//crytical case : if co_effecients are 5 4 3 1 0
//then convert it to 5 4 3 0 1 0

long long horner(long long x, long long n)
{
    long long ans = co_efficient[0];
    for(int i = 1; i < n; i++) {
        ans = ans*x + co_efficient[i];
    }
    return ans;
}

int main()
{
    int n, x;
    while(scanf("%d", &x) && x) {
        for(int i = 0; i <= x; i++)
            scanf("%d", &co_efficient[i]);
        n = x+1;
        printf("%d\n", horner(x, n));
    }
    return 0;
}
