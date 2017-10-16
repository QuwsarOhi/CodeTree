// LightOJ
// 1331 - Agent J 

#include <bits/stdc++.h>
#define PI acos(-1)
#define EPS 1e-9
using namespace std;
 
 
struct circle {
    int x, y, r;
    circle(int _x, int _y, int _r) {
        x = _x;
        y = _y;
        r = _r;
    }
    double Area() {
        return PI*r*r;
    }
};
 
int Distance(int x1, int y1, int x2, int y2) {          // Without Sqrt
    int x = x1-x2;
    int y = y1-y2;
    return x*x + y*y;
}
 
 
double getAngle(double AB, double BC, double CA) {      // Returns Angle(Rad)
    return acos((AB*AB + BC*BC - CA*CA)/(2*AB*BC));
}
 
// Reference: https://www.mathsisfun.com/geometry/circle-sector-segment.html
double CircleSegmentArea(double r, double angle) {      // Circle Radius, Center Angle(Rad)
    return r * r * 0.5 * (angle - sin(angle));
}
 
double CircleSectorArea(double r, double angle) {       // Circle Radius, Center Angle(Rad)
    return r * r * 0.5 * angle;
}
 
 
double CircleArcLength(double r, double angle) {        // Circle Radius, Center Angle(Rad)
    return r * angle;
}
 
double TriangleArea(double AB, double BC, double CA) {
    double s = (AB + BC + CA)/2.0;
    return sqrt(s*(s-AB)*(s-BC)*(s-CA));
}
 
int main() {
    int t;
    double r1, r2, r3, a1, a2, a3, triangle;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lf %lf %lf", &r1, &r2, &r3);
        a1 = CircleSectorArea(r1, getAngle(r1+r2, r1+r3, r2+r3));
        a2 = CircleSectorArea(r2, getAngle(r1+r2, r2+r3, r1+r3));
        a3 = CircleSectorArea(r3, getAngle(r3+r1, r3+r2, r1+r2));
       
        triangle = TriangleArea(r1+r2, r2+r3, r1+r3);
       
        printf("Case %d: %.9lf\n", Case, triangle-a1-a2-a3);
    }
    return 0;
}
