//UVa
// 583 - Prime Factors

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    long long n;
    while(scanf("%lld", &n) && n) {
        bool first = 1;
        if(n < 0) {
            printf("%lld = -1", n);
            n *= -1;
            first = 0;
        }
        //else
            //printf("%lld = 1", n);
        int lim = sqrt(n)+1;
        long long tmp = n;
        while(tmp % 2 == 0) {
            if(first) {
                printf("%lld = 2", tmp);
                first = 0;
            }
            else printf(" x 2");
            tmp/=2;
        }
        for(long long i = 3; i <= lim; i+=2)
            while(tmp % i == 0) {
                if(first) {
                    printf("%lld = %lld", n, i);
                    first = 0;
                }
                else
                    printf(" x %lld", i);
                tmp/=i;
            }
        if(tmp != 1) {
            if(first) {
                printf("%lld = %lld\n", tmp, tmp);
                first = 0;
            }
            else
                printf(" x %lld\n", tmp);
        }
        else {
            if(first)
                printf("1 = 1\n");
            else
                printf("\n");
        }
    }
    return 0;
}
