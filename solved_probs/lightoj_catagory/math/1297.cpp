// LightOJ
// 1297 - Largest Box
// Basic Math, Ternary Search

/* in this problem binary search won't work
 * because binary search only works if f(x) increases w.r.t of x
 * but in this problem, f(x) is unimodal 
 * that is, at first, increasing x, f(x) increases, after a certain value, increasing x causes f(x) to decrease
 *     |       /						|
 *     |      /							|
 *     |     /							|     ^
 *     |    /							|    / \
 *     |   /							|   /   \
 *   ^ |  /						 	 ^	|  /     \
 *   | | /							 |	| /       \
 * f(x)|-------------------			f(x)|------------------
 *      x ->						 		x ->
 * 
 *  Binary Search Works Here	     Ternary Search Works Here
 *
 */

#include <bits/stdc++.h>
#define EPS 1e-6
using namespace std;

long double l, w, maxVol;

 
inline long double volume(long double x) {
	if(l < 2*x)
		return -1;
	return (l-x-x)*(w-x-x)*x;
}

long double ternarySearch(long double lo, long double hi) {
	long double l1, l2, ans;
	for(int i = 0; i < 100; ++i) {
		l1 = lo+(hi-lo)/3.0;
		l2 = hi-(hi-lo)/3.0;
		if((volume(l1) > volume(l2))) {
			hi = l2;
			ans = l1;
		}
		else
			lo = l1;
	}
	return ans;
}


int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%Lf %Lf", &l, &w);
		long double x = ternarySearch(0, min(l, w));
		printf("Case %d: %.10Lf\n", Case, volume(x));
	}
	
	return 0;
}
