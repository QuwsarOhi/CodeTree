// LightOJ
// 1216 - Juice in the Glass 

#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;


double ConeVolume(double r, double h) {
	return (PI*r*r*h)/3.0;
}

int main() {
	int t, r1, r2, h, p;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d %d %d", &r1, &r2, &h, &p);
		double l = sqrt(h*h + (r1-r2)*(r1-r2));			// Pythagorian Formula
		double l_down = (p/(double)h) * l;				// For a triangle ABC (D intersects AB, E intersects AC) AD/DB == AE/EC
		double l_up = l-l_down;
		double Del_r = r2-r1;
		double r3 = r1 + (Del_r/l)*l_up;				// Same Ratio Calculation
		double Cone_h = (h/abs(Del_r)) * r1 - h;   		// Cone height (h) from the bottom of the class to below
		printf("Case %d: %.10lf\n", Case, ConeVolume(r3, Cone_h+p) - ConeVolume(r2, Cone_h));
	}
	
	return 0;
}
