// LightOJ
// 1056 - Olympics

#include <bits/stdc++.h>
#define Target 400
#define PI acos(-1)
#define EPS 1e-8
using namespace std;

double DEG_to_RAD(double deg) {             // Converts Degree to Radian
    return (deg*PI)/180;
}

double RAD_to_DEG(double rad) {
    return (180/PI)*rad;
}

double TriangleAngle(double a, double b, double c) {    // Returns angle(IN RADIAN) between side a and b (opposite of c)
    return acos((a*a + b*b - c*c)/(2*a*b));
}

double CircleArcLength(double r, double theta) {		// Circle Radius, Center Angle(degree)
	return r * DEG_to_RAD(theta);
}

double Area(double l, int x, int y) {
    double w = (l*y)/x;
    double r = sqrt(w*w+l*l)/2;
    double theta = RAD_to_DEG(TriangleAngle(r, r, w));
    double arc = CircleArcLength(r, theta);
    return 2*l+arc*2;
}
    
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int x, y, t;
    char c;
    
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &x);
        scanf(" %c", &c);
        scanf("%d", &y);
        
        double lo = 0, hi = 500, l, A;
        for(int i = 0; i < 200; ++i) {
            l = (lo+hi)/2;
            A = Area(l, x, y);
            if(A - Target >= EPS)
                hi = l - 1;
            else
                lo = l + 1;
        }
        
        double w = (l*y)/x;
        printf("Case %d: %.6lf %.6lf\n", Case, l, w);
    }
    return 0;
}
