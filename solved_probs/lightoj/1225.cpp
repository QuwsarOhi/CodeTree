//LightOJ
//1225 	Palindromic Numbers (II)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, tmp;
    scanf("%d", &t);
    for(register int Case = 1; Case <= t; Case++) {
        scanf("%d", &n);
        tmp = n;
        int x = 0;
        while(tmp) {
            x *= 10;
            x += tmp%10;
            tmp /= 10;
        }
        if(x == n)
            printf("Case %d: Yes\n", Case);
        else
            printf("Case %d: No\n", Case);
    }
    return 0;
}
