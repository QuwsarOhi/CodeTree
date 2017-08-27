// Codeforces
// B. BerSU Ball
// http://codeforces.com/contest/489/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x;
	map<int, int>b,g;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		b[x]++;
	}
	
	scanf("%d", &m);
	
	for(int i = 0; i < m; ++i) {
		scanf("%d", &x);
		g[x]++;
	}
	int cnt = 0;
	for(auto i : b) {
		int tmp = i.second;
		while(tmp) {
			if(g[i.first-1] > 0) {
				--g[i.first-1];
				--tmp, ++cnt;
			}
			else if(g[i.first] > 0) {
				--g[i.first];
				--tmp, ++cnt;
			}
			else if(g[i.first+1] > 0) {
 				--g[i.first+1];
 				--tmp, ++cnt;
			}
			else
				break;
		}
	}
	
	printf("%d\n", cnt);
	return 0;
}
