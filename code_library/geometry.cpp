#include <bits/stdc++.h>
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


int main() {
    return 0;
}
