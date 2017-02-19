//LightOJ
//1354 - IP Checking
#include<bits/stdc++.h>
using namespace std;

int ex(int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 10;
    if(n == 2)
        return 100;
    if(n == 3)
        return 1000;
    if(n == 4)
        return 10000;
    if(n == 5)
        return 100000;
    if(n== 6)
        return 1000000;
    if(n == 7)
        return 10000000;
    if(n == 8)
        return 100000000;
}

int binary(int x)
{
    int bin = 0;
    for(register int i = 7; i >= 0; i--)
        if(x & (1 << i))
            bin += ex(i);
    return bin;
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(register int Case=1; Case <=t; Case++) {
        int num[5], bin[5];
        char p;
        scanf("%d %c %d %c %d %c %d", &num[0], &p, &num[1], &p,  &num[2], &p, &num[3]);
        scanf("%d %c %d %c %d %c %d", &bin[0], &p, &bin[1], &p, &bin[2], &p, &bin[3]);
        bool ok = 1;
        for(register int i = 0; i < 4 && ok; i++) {
            //printf("cal : %d in : %d\n", binary(num[i]), bin[i]);
            if(bin[i] != binary(num[i]))
                ok = 0;
        }
        if(ok)
            printf("Case %d: Yes\n", Case);
        else
            printf("Case %d: No\n", Case);
    }
    return 0;
}
