// UVa
// 190 - Circle Through Three Points

#include <bits/stdc++.h>
#define EPS 1e-4
#define PI acos(-1)
using namespace std;

struct point {          // In Double
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct line {
    double a, b, c;
};

double dist(point p1, point p2) {
	double x = p1.x-p2.x;
	double y = p1.y-p2.y;
	return sqrt(x*x + y*y);
}

bool Equal(double a, double b) {
    return (fabs(a-b) <= EPS);
}

void pointsToLine(point p1, point p2, line &l) {    // ax + by + c = 0  [comes from y = mx + c]
    if (fabs(p1.x - p2.x) < EPS)                    // vertical line is fine
        l.a = 1.0, l.b = 0.0, l.c = -p1.x;          // default values
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;                                  // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    } 
}

bool areParallel(line l1, line l2) {            // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
    if(areParallel(l1, l2)) return 0;                                   // no intersection
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);    // solve system of 2 linear algebraic equations with 2 unknowns
    if(fabs(l1.b) > EPS)    p.y = -(l1.a * p.x + l1.c);                 // special case: test for vertical line to avoid division by zero
    else                    p.y = -(l2.a * p.x + l2.c);
    return 1;
}

line perpendicularLine(line l, point p) {
    line ret;
    ret.a = l.b, ret.b = -l.a;
    ret.c = -(ret.a*p.x + ret.b*p.y);
    if(ret.b < 0)                                   // as line must contain b = 1.0 by default
        ret.a *= -1, ret.b *= -1, ret.c *= -1;
    if(ret.b != 0) {
        ret.a /= ret.b;
        ret.c /= ret.b;
        ret.b = 1;
    }
    return ret;
}

double TriangleArea(double AB, double BC, double CA) {
	double s = (AB + BC + CA)/2.0;
	return sqrt(s*(s-AB)*(s-BC)*(s-CA));
}

double rCircumCircle(double ab, double bc, double ca) {     // ab, ac, ad are sides of triangle
    return ab * bc * ca / (4.0 * TriangleArea(ab, bc, ca));
}

point CircumCircleCenter(point a, point b, point c, double &r) {
    double ab = dist(a, b);
    double bc = dist(b, c);
    double ca = dist(c, a);
    r = rCircumCircle(ab, bc, ca);
    if(Equal(r, ab))
        return point((a.x+b.x)/2, (a.y+b.y)/2);
    else if(Equal(r, bc))
        return point((b.x+c.x)/2, (b.y+c.y)/2);
    else if(Equal(r, ca))
        return point((c.x+a.x)/2, (c.y+a.y)/2);
    line AB, BC;
    pointsToLine(a, b, AB);
    pointsToLine(b, c, BC);
    line perpenAB = perpendicularLine(AB, point((a.x+b.x)/2, (a.y+b.y)/2));
    line perpenBC = perpendicularLine(BC, point((b.x+c.x)/2, (b.y+c.y)/2));
    point center;
    areIntersect(perpenAB, perpenBC, center);
    return center;
}

void PRINT1(point p, double r) {
    if(p.x != 0) {
        printf("(x");
        p.x > 0 ? printf(" - "):printf(" + ");
        printf("%.3lf)^2", fabs(p.x));
    }
    else printf("x^2");
    printf(" + ");
    
    if(p.y != 0) {
        printf("(y");
        p.y > 0 ? printf(" - "):printf(" + ");
        printf("%.3lf)^2", fabs(p.y));
    }
    else printf("y^2");
    printf(" = %.3lf^2\n", fabs(r));
}

void PRINT2(point p, double r) {
    printf("x^2 + y^2");
    double h = -p.x*2, k = -p.y*2;
    double c = p.x*p.x + p.y*p.y - r*r;
    if(!Equal(h, 0)) {
        h > 0 ? printf(" + "):printf(" - ");
        printf("%.3lfx", fabs(h));
    }
    if(!Equal(k, 0)) {
        k > 0 ? printf(" + "):printf(" - "); 
        printf("%.3lfy", fabs(k));
    }
    c > 0 ? printf(" + "):printf(" - ");
    printf("%.3lf", fabs(c));
    printf(" = 0\n");
}
    
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    point a, b, c;
    while(scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) == 6) {
        double r;
        point ret = CircumCircleCenter(a, b, c, r);
        PRINT1(ret, r);
        PRINT2(ret, r);
        printf("\n");
    }
    return 0;
}
