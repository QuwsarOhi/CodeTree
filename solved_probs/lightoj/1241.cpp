//LightOJ
//1241 - Pinocchio
//Math

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; Case++) {
		int n, cnt = 0, x, p;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &x);
			p = x - p;
			if(i == 0)
				p = x - 2;
			if(p > 5)
				cnt += ceil(p/5.0);
			else if(p)
				cnt++;
			p = x;
		}
		printf("Case %d: %d\n", Case, cnt);
	}
	return 0;
}
			
			
