// Codeforces
// B. Vanya and Lanterns
// http://codeforces.com/problemset/problem/492/B
// Sorting, Bisection


#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<int>v;

bool lightAll(double x) {
	if(v[0] != 0 && (v[0]-x > 0))
		return 0;
	
	for(int i = 0; i < (int)v.size(); ++i) {
		if(i != 0)
			if(v[i-1] + x < v[i]-x)
				return 0;
	}
	
	if(v[v.size()-1] != l && v[v.size()-1]+x < l)
		return 0;
		
	return 1;
}

double bisect(double lo, double hi) {
	double ans = 0, mid;
	
	for(int i = 0; i < 200; ++i) {
		mid = (lo+hi)/2;
		if(lightAll(mid)) {
			ans = mid;
			hi = mid;
		}
		else
			lo = mid;
	}
	
	return ans;
}


int main() {
	int x;
	scanf("%d%d", &n, &l);
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	printf("%.10lf\n", bisect(0, l+100));
	
	return 0;
}
