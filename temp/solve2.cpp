// LightOJ
// 1178 - Trapezium

#include <bits/stdc++.h>
using namespace std;

double TriangleArea(double AB, double BC, double CA) {
	double s = (AB + BC + CA)/2.0;
	return sqrt(s*(s-AB)*(s-BC)*(s-CA));
}

double TrapiziodArea(double a, double b, double c, double d) {      // a and c are parallel
    double BASE = fabs(a-c);
    double AREA = TriangleArea(d, b, BASE);
    double h = (AREA*2)/BASE;
    return ((a+c)/2)*h;
}

int main() {
    int t;
    double a, b, c, d;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
        printf("Case %d: %.6lf\n", Case, TrapiziodArea(a, b, c, d));
    }
    
    return 0;
}
        
