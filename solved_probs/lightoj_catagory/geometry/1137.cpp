// LightOJ
// 1137 - Expanding Rods
// Geometry

#include <bits/stdc++.h>
using namespace std;
 
int l, n;
double s, c;
 
double CHECK(double r) {
    double d = 2*r;
    if(l/d > 1)
        return -1e8;
    double arc = d * asin(l/d);
    if(arc > s)
        return 1e8;
    return -1e8;
}
 
double BS1(double lo, double hi) {
    double mid;
    for(int i = 0; i < 200; ++i) {
        mid = (lo+hi)/2;
        if(CHECK(mid) > 0)
            lo = mid;
        else
            hi = mid;
    }
    return mid;
}
 
double getVal(double r) {
    double theta = s/r;
    return cos(theta/2)*r;
}
 
int main() {
    int t;
    scanf("%d", &t);
   
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%lf", &l, &n, &c);
        s = (1 + n*c)*l;
       
        double r = BS1(0, 101000);
       
        if(n > 0 && c > 0)
            printf("Case %d: %.6lf\n",Case,r-getVal(r));
        else
             printf("Case %d: %.6lf\n",Case,0.0);
    }
    return 0;
}