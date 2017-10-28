// LightOJ
// 1030 - Discovering Gold 

// Starting from 0 index
// Ex[i] = 1/6(G[i]+Ex[i+1]) + 1/6(G[i]+Ex[i+2]) + 1/6(G[i]+Ex[i+3]) + 1/6(G[i]+Ex[i+4]) + 1/6(G[i]+Ex[i+5]) + 1/6(G[i]+Ex[i+6])
// Ex[n-1] = G[i]/6 + (Ex[n-1]/6)*5

#include <bits/stdc++.h>
using namespace std;

double G[120], E[120];
int n;

double recur(int i) {
	if(i == n-1)
		return G[i];
	
	if(E[i] != 0)
		return E[i];
	
	for(int j = i+1; j < n && j <= i+6; ++j) 
		E[i] += G[i] + recur(j);
	
	if(n-i-1 < 6)
		E[i] /= n-i-1;
	else
		E[i] /= 6;

	return E[i];
}

int main() {
	int t;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		
		for(int i = 0; i < n; ++i)
			scanf("%lf", &G[i]);

		memset(E, 0, sizeof E);

		printf("Case %d: %.9lf\n", Case, recur(0));
	}
	return 0;
}
			
			
