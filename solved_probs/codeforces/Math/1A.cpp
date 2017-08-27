// CodeForces
// A. Theatre Square
// http://codeforces.com/problemset/problem/1/A
// Math

#include <bits/stdc++.h>
using namespace std;


int main() {
	double n, m, a;
	
	scanf("%lf %lf %lf", &n, &m, &a);
	
	printf("%.0lf\n", (ceil(n/a) * ceil(m/a)));
	
	return 0;
}
