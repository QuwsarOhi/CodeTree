// LightOJ
// 1240 - Point Segment Distance (3D)

#include <bits/stdc++.h>
using namespace std;


struct point {          // In Integer
    int x, y, z;
    point() { x = y = z = 0; }
    point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

    bool operator == (point other) const {
        return (x == other.x) && (y == other.y) && (z == other.z);
}};

struct point3D {
    double x, y, z;
};

struct ParaLine {                                       // Line in Parametric Form
    point a, b;                                         // points must be in DOUBLE
    ParaLine() { a.x  = a.y = b.x = b.y = 0; }
    ParaLine(point _a, point _b) : a(_a), b(_b) {}      // {Start, Finish} or {from, to}

    point3D getPoint(double t) {                          // Parametric Line : a + t * (b - a)    t = [-inf, +inf]
        point3D p;
        p.x = a.x + t*(b.x-a.x);
        p.y = a.y + t*(b.y-a.y);
        p.z = a.z + t*(b.z-a.z);
        return p;
}};


double dist(point3D p1, point p2) {
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    double z = p1.z - p2.z;
    return sqrt(x*x + y*y + z*z);
}


double ternarySearch(double low, double high, ParaLine L, point P) {
    double ret = 1e12;
    for(int i = 0; i < 100; ++i) {
        double mid1 = low + (high - low) / 3.0;
        double mid2 = high - (high - low) / 3.0;
 
        double cost1 = dist(L.getPoint(mid1), P);
        double cost2 = dist(L.getPoint(mid2), P);
                
        if(cost1 > cost2) {
            low = mid1;
            ret = min(cost2, ret);
        }
        else {
            high = mid2;
            ret = min(cost1, ret);
    }}
    
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        point A, B, P;
        scanf("%d%d%d%d%d%d%d%d%d", &A.x, &A.y, &A.z, &B.x, &B.y, &B.z, &P.x, &P.y, &P.z);
        ParaLine L(A, B);
        printf("Case %d: %.6lf\n", Case, ternarySearch(0, 1, L, P));
    }
    
    return 0;
}
