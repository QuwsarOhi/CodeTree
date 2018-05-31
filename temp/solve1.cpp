// UVa
// 438 - The Circumference of the Circle

#include <bits/stdc++.h>
#define PI  3.141592653589793
using namespace std;

struct point {          // In Double
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2) {
	double x = p1.x-p2.x;
	double y = p1.y-p2.y;
	return sqrt(x*x + y*y);
}

double TriangleArea(double AB, double BC, double CA) {
	double s = (AB + BC + CA)/2.0;
	return sqrt(s*(s-AB)*(s-BC)*(s-CA));
}

// radius of Circle Outside of a Triangle
double rCircumCircle(double ab, double bc, double ca) {     // ab, ac, ad are sides of triangle
    return ab * bc * ca / (4.0 * TriangleArea(ab, bc, ca));
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    point a, b, c;
    while(scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) == 6) {
        double r = rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
        printf("%.2lf\n", 2*r*PI);
    }
    return 0;
}
