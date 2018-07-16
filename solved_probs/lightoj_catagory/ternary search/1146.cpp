// LightOJ
// 1146 - Closest Distance

#include <bits/stdc++.h>
#define EPS 1e-7
using namespace std;

struct point {          // In Double
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};

struct ParaLine {                                       // Line in Parametric Form
    point a, b;                                         // points must be in DOUBLE
    ParaLine() { a.x  = a.y = b.x = b.y = 0; }
    ParaLine(point _a, point _b) : a(_a), b(_b) {}      // {Start, Finish} or {from, to}

    point getPoint(double t) {                          // Parametric Line : a + t * (b - a)    t = [-inf, +inf]
        return point(a.x + t*(b.x-a.x), a.y + t*(b.y-a.y));
}};


double dist(point p1, point p2) {
	double x = p1.x-p2.x;
	double y = p1.y-p2.y;
	return sqrt(x*x + y*y);
}

double ternarySearch(double low, double high, ParaLine a, ParaLine b) {
    for(int i = 0; i < 70; ++i) {
        double mid1 = low + (high - low) / 3.0;
        double mid2 = high - (high - low) / 3.0;
 
        double cost1 = dist(a.getPoint(mid1), b.getPoint(mid1));
        double cost2 = dist(a.getPoint(mid2), b.getPoint(mid2));

        if(cost1 > cost2)   low = mid1;
        else                high = mid2;
    }
    
    double T = (high+low)/2.0;
    return dist(a.getPoint(T), b.getPoint(T));
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        point a1, b1, a2, b2;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &a1.x, &a1.y, &b1.x, &b1.y, &a2.x, &a2.y, &b2.x, &b2.y);
        ParaLine a(a1, b1), b(a2, b2);
        printf("Case %d: %lf\n", Case, ternarySearch(0, 1, a, b));
    }
    return 0;
}
