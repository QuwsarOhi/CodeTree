// Timus
// 2012. About Grisha N.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int f;
	while(scanf("%d", &f) != EOF) {
		int n = 12 - f;
		int t = n*45;
		if(t <= 4*60)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
