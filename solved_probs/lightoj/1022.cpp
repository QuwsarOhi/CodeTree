//UVa
//1022 	Circle in Square
#include<bits/stdc++.h>
#define PI 2*acos(0.0)
using namespace std;

int main()
{
    int t;
    double r, circle, square;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%lf", &r);
        circle = PI * r * r;
        square = 2*r*2*r;
        printf("Case %d: %.2lf\n", Case, square - circle);
    }
    return 0;
}
