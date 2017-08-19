// Codeforces
// Round 429 Div.2
// A. Generous Kefa
// http://codeforces.com/contest/841/problem/A

// Simulation, Brute Force

#include <bits/stdc++.h>
using namespace std;


int main() {
	int k , n, idx = 0;
	char c;
	scanf("%d%d", &k, &n);
	
	int left[100];
	map<char, int>mp;
	
	for(int i = 0; i < 100; ++i) {
		left[i] = 0;
	}
	
	for(int i = 0; i < k; ++i) {
		scanf(" %c", &c);
		if(mp.find(c) == mp.end()) {
			mp[c] = idx++;
		}
		++left[mp[c]];
	}
	
	sort(left, left+idx);
	
	if(left[idx-1] > n) {
		printf("NO\n");
		return 0;
	}
	
	for(int i = 0; i < idx; ++i) {
		for(int j = 0; j < n; ++j) {
			if(left[i] > 0) {
				left[i]--;
			}
		}
	}
	
	for(int i = 0; i < idx; ++i) {
		if(left[i] > 0) {
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	return 0;
}
