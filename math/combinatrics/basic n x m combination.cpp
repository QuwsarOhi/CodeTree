//UVa
//12463 - Little Nephew
//Isnt saved yet!

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    long long a, b, c, d, e;
    while(scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e) && a && b && c && d && e)
        printf("%lld\n", a*b*c*d*d*e*e);
    return 0;
}
