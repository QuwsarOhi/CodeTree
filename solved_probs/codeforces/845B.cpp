// CodeForces
// B. Luba And The Ticket
// http://codeforces.com/contest/845/problem/B
// BruteForce, Greedy

#include <bits/stdc++.h>

using namespace std;

inline int cal(int x) {
	int sum = 0;
	while(x) {
		sum += x%10;
		x/=10;
	}
	return sum;
}

int main() {
	register int n, r, l, t1, t2, L, R, mn = 12, cnt = 0;
	
	scanf("%d", &n);
	R = cal(n%1000), L = cal(n/1000);
	
	if(R == L) {
		printf("0\n");
		return 0;
	}
	
	for(register int i = 1; i < 1000000; ++i) {
		r = i%1000, l = i/1000;
		l = cal(l), r = cal(r);
		
		if(l == r) {
			t1 = i;
			t2 = n;
			cnt = 0;
			while(t1 || t2) {
				if(t1%10 != t2%10)
					++cnt;
				t1/=10, t2/=10;
			}
			mn = min(cnt, mn);
		}
		if(mn == 1)
			break;
	}
	
	printf("%d\n", mn);
	return 0;
}
