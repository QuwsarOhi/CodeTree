//LightOJ
//1053 - Higher Math
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b, c;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d %d %d", &a, &b, &c);
        a *= a;
        b *= b;
        c *= c;
        printf("Case %d: ", Case);
        if(a == b+c || b == a+c || c == a+b)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
