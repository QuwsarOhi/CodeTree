//LightOJ
//1116 - Ekka Dokka
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        long long num, x;
        scanf("%lld", &num);
        x = sqrt(num) + 1;
        //bool found = 0;
        printf("Case %d: ", Case);
        long long n, m;
        if(!(num & 1)) {
            for(long long i = 2; i < num; i+=2)
                if(num % i == 0) {
                    n = i;
                    m = num/i;
                    if(!(n & 1))
                        swap(n, m);
                    if((n & 1) && !(m & 1)) {
                        printf("%lld %lld\n", n, m);
                        break;
                    }
                }
        }
        else
            printf("Impossible\n");
    }
    return 0;
}
