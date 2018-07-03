#include <bits/stdc++.h>
using namespace std;

struct point {          // In Integer
    int x, y;
    point() { x = y = 0; }
    point(int _x, int _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if(x != other.x)
            return x < other.x;
        return y < other.y;
    }
    
    bool operator == (point other) const {
        return (x == other.x) && (y == other.y);
    }
};

struct ParaLine {       // Line in Parametric Form
    point a, point b;
    ParaLine() { a.x  = a.y = b.x = b.y = 0; }
    ParaLine(point _a, point _b) : a(_a), b(_b) {}

    point getPoint(double t) {      // Parametric Line : a + t * (b - a)    t = [-inf, +inf]
        return point(a.x + t*(b.x-a.x), a.y + t*(b.y-a.y));
}};


int hypot(point p1, point p2) {
    int x = p1.x-p2.x;
	int y = p1.y-p2.y;
    return x*x + y*y;
}

double ternarySearch(double low, double high) {
    for(int i = 0; i < 70; ++i) {
        double mid1 = low + (high - low) / 3.0;
        double mid2 = high - (high - low) / 3.0;
 
        double cost1 = hypot(getPoint(a, mid1), getPoint(b, mid1));
        double cost2 = hypot(getPoint(a, mid2), getPoint(b, mid2));
                
        if(cost1 < cost2) {
            high = mid1;
            //ret = min(cost2, ret);
        }
        else {
            low = mid2;
            //ret = min(cost1, ret);
    }}
    
    return (high+low)/2.0;
}


int main() {
    
