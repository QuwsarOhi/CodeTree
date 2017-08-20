// Codeforces
// C. Leha and Function (429C)
// Math, Greedy
// http://codeforces.com/contest/841/problem/C

#include <bits/stdc++.h>
using namespace std;


int main() {
	int m, x;
	vector<int>a,ai;
	vector<pair<int, int> >b;
	
	scanf("%d", &m);
	
	for(int i = 0; i < m; ++i) {
		scanf("%d", &x);
		a.push_back(x);
	}
	
	for(int i = 0; i < m; ++i) {
		scanf("%d", &x);
		b.push_back(make_pair(x, i));
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	ai.resize(m+10);
	
	for(int i = 0, j = m-1; i < m; ++i, --j) {
		ai[b[i].second] = a[j];
	}
	
	for(int i = 0; i < m-1; ++i) {
		printf("%d ", ai[i]);
	}
	printf("%d\n", ai[m-1]);
	
	return 0;
}
