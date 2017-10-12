// LightOJ
// 1043 - Triangle Partitioning

#include <bits/stdc++.h>
#define EPS 1e-7
using namespace std;

inline bool isEqual(double a, double b) {
	if(abs(a - b) <= EPS)
		return 1;
	return 0;
}

inline bool isGreater(double a, double b) {
	if(a >= b+EPS)
		return 1;
	return 0;
}

double TriangleArea(double AB, double BC, double CA) {
	double s = (AB + BC + CA)/2.0;
	return sqrt(s*(s-AB)*(s-BC)*(s-CA));
}

double AB, AC, BC, R;

double BinarySearch(double lo, double hi) {
	double AD, ans = -1;
	for(int i = 0; i < 200; ++i) {
		AD = (lo+hi)/2.0;
		double AE = (AD/AB)*AC;
		double DE = (AD/AB)*BC;
		double area1 = TriangleArea(AD, DE, AE);
		double area2 = TriangleArea(AB, BC, AC) - area1;
		if(isEqual(area2*R, area1)) {
			ans = AD;
			hi = AD;
		}
		else if(isGreater(area1, area2*R))
			hi = AD;
		else
			lo = AD;
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &R);
		printf("Case %d: %.6lf\n", Case, BinarySearch(0, AB+10));
	}
	
	return 0;
}
