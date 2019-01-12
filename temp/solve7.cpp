#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, x, y, xx = 0, yy = 0;
	scanf("%lld", &n);
	char q;

	while(n--) {
		scanf(" %c%lld%lld", &q, &x, &y);
		if(x > y) swap(x, y);

		if(q == '+')
			xx = max(x, xx), yy = max(yy, y);
		else {
			if(xx <= x and yy <= y)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}