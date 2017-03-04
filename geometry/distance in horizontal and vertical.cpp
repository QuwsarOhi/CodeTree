//UVa
//11130 - Billiard bounces

#include<bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    double a, b, A, v, s;
    while(scanf("%lf %lf %lf %lf %lf", &a, &b, &v, &A, &s) && (a || b || v || A || s)) {
        double d = (v*s)/2.0;     //s = ((v + u) * t)/2
        double h = d * cos(A/180 * PI);     //total distance * segment of horizontal axis
        double v = d * sin(A/180 * PI);     //total distance * segment of vertical axis
        printf("%.0lf %.0lf\n", h/a, v/b);  //this also rounds up the values
    }
    return 0;
}
