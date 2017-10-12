// Timus
// 1005 Stone Pile

#include <bits/stdc++.h>
using namespace std;

int v[25] = {0}, n;

int recur(int i, int x, int y) {
	if(i == n)
		return abs(x-y);
	
	return min(recur(i+1, x+v[i], y), recur(i+1, x, y+v[i]));
}

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	
	printf("%d\n", recur(0, 0, 0));
	
	return 0;
}
	
	
