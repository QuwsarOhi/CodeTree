// Codeforces
// A.Game
// http://codeforces.com/problemset/problem/513/A

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n1, n2, k1, k2;
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	if(n1 == n2)
		printf("Second\n");
	else if(n1 > n2)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}
