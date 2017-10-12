// LightOJ
// 1118 - Incredible Molecules

#include <bits/stdc++.h>
#define PI acos(-1)
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

int Distance(int x1, int y1, int x2, int y2) {			// Without Sqrt
	int x = x1-x2;
	int y = y1-y2;
	return x*x + y*y;
}

// Reference: https://www.mathsisfun.com/geometry/circle-sector-segment.html
double CircleSegmentArea(double r, double angle) {		// Circle Radius, Center Angle(Rad)
	return r * r * 0.5 * (angle - sin(angle));
}

double getAngle(double AB, double BC, double CA) {		// Returns Angle(Rad)
	return acos((AB*AB + BC*BC - CA*CA)/(2*AB*BC));
}

bool doIntersectCircle(circle c1, circle c2) {
	int dis = Distance(c1.x, c1.y, c2.x, c2.y);
	if(sqrt(dis) < c1.r+c2.r)
		return 1;
	return 0;
}

int main() {
	int t, x1, y1, x2, y2, r1, r2;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		printf("Case %d: ", Case);
		circle c1(x1, y1, r1), c2(x2, y2, r2);
		if(doIntersectCircle(c1, c2)) {
			double d = sqrt(Distance(c1.x, c1.y, c2.x, c2.y));
			if(d + c1.r <= c2.r)
				printf("%.10lf\n", c1.Area());
			else if(d + c2.r <= c1.r)
				printf("%.10lf\n", c2.Area());
			else {
				double intersection = CircleSegmentArea(c1.r, 2*getAngle(d, c1.r, c2.r));
				intersection += CircleSegmentArea(c2.r, 2*getAngle(d, c2.r, c1.r));
				printf("%.10lf\n", intersection);
			}
		}
		else
			printf("0\n");
	}
	return 0;
}
