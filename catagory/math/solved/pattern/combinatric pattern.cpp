//UVa
//11401 - Triangle Counting
#include<bits/stdc++.h>
using namespace std;

long long n[1000010], two_sum = 0, inc = 1;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    n[3] = 0;
    n[4] = 1;
    bool odd = 1;
    int p = 0;
    for(long long i = 5, j = 1; i <= 1000000; i++, j++) {
        n[i] = n[i-1] + i-3 + two_sum;
        if(j & 1) {
            two_sum += inc;
            p++;
        }
        else {
            two_sum += inc;
            p++;
        }
        if(p == 2 && odd) {
            odd != odd;
            p = 0;
            inc += 1;
        }
        if(p == 2 && !odd) {
            odd != odd;
            p = 0;
            inc += 2;
        }
    }
    long long i;
    while(scanf("%lld", &i) && (i >= 3)) {
        printf("%lld\n", n[i]);
    }
    return 0;
}
