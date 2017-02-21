//LightOJ
//1069 - Lift
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b, c;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d %d", &a, &b);
        int total = 0;
        total += abs(a-b)*4 + a*4 + 3*3 + 5*2;
        printf("Case %d: %d\n", Case, total);
    }
    return 0;
}
