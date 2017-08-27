// CodeForces
// C. Modified GCD
// http://codeforces.com/problemset/problem/75/C
// Number Theory, GCD (Basics)

#include <bits/stdc++.h>
using namespace std;

vector<int>fa, fb, f, divisor;
unordered_map<int, bool>taken;
int divSize;

void divisors(int i, long long m) {
	if(i == divSize)
		return ;
	long long t = m * f[i];
	if(!taken[t]) { 
		taken[t] = 1;
		divisor.push_back(t);
		divisors(i+1, t);
	}
	divisors(i+1, m);
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int l = sqrt(a);
	for(int i = 2; i <= l; ++i) {
		while(a%i == 0) {
			fa.push_back(i);
			a/=i;
		}
	}
	if(a > 0)
		fa.push_back(a);
	l = sqrt(b);
	for(int i = 2; i <= l; ++i) {
		while(b%i == 0) {
			fb.push_back(i);
			b/=i;
		}
	}
	if(b > 0)
		fb.push_back(b);
	for(int i = 0, j = 0; i < (int)fa.size() && j < (int)fb.size(); ) {
		if(fa[i] == fb[j]) {
			f.push_back(fa[i]);
			++i, ++j;
		}
		else if(fa[i] < fb[j])
			++i;
		else
			++j;
	}
	divSize = f.size();
	divisors(0, 1);
	divisor.push_back(1);
	int n, x, y, ans;
	scanf("%d", &n);
	
	while(n--) {
		scanf("%d%d", &x, &y);
		ans = -1;
		for(auto i : divisor) {
			if(i >= x && i <= y)
				ans = max(ans, i);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
		
