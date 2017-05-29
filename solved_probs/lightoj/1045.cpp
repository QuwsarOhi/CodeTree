//UVa
//1045 - Digits of Factorial
#include<bits/stdc++.h>
using namespace std;

double log_10[1000010];

int main()
{
    log_10[0] = 0;
    for(register int i = 1; i <= 1e6; i++)
        log_10[i] = log10(i) + log_10[i-1];
    int t, n, base;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d %d", &n, &base);
        double num = 0;
        num = log_10[n]/log10(base);
        if(n == 0)
            num = 0;
        printf("Case %d: %d\n", Case, int(floor(num)+1));
    }
    return 0;
}
