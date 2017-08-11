//UVa
//1210 - Sum of Consecutive Prime Numbers
#include<bits/stdc++.h>
using namespace std;

bitset<10010>isPrime;

void sieve()
{
    isPrime.set();
    for(int i = 2; i <= 10000; i++) {
        if(isPrime[i]) {
            for(int j = i*i; j <= 10000; j+=i)
                isPrime[j] = 0;
        }
    }
}

int main()
{
    sieve();
    int n;
    while(scanf("%d", &n) && n) {
        register int cnt = 0;
        for(int i = n; i >= 0; i--) {
            register int num = n;
            if(isPrime[i])
                for(int j = i; j >= 2; j--) {
                    if(isPrime[j] && n >= j)
                        num -= j;
                    if(num == 0) {
                        cnt++;
                        break;
                    }
                    if(num < 0)
                        break;
                }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
