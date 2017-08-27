// Codeforces
// A. Puzzles
// http://codeforces.com/problemset/problem/337/A

#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	
	vector<int>v;
	int x;
	for(int i = 0 ; i < n; ++i) {
		scanf("%d", &x);
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	
	if(n == m) {
		printf("%d\n", v[n-1]-v[0]);
		return 0;
	}
	
	int mn = v[m-1] - v[0];endl;
	for(int i = 1; i+m-1 < n; i++) {
		 mn = min(mn, v[m+i-1]-v[i]);
	}
	
	printf("%d\n", mn);
	
	return 0;
}
