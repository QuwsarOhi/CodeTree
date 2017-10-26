// LightOJ
// 1023 - Discovering Permutations 

#include <bits/stdc++.h>
using namespace std;


int main() {
	int t, n, k;
	char s[30];
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &n, &k);
		
		for(int i = 0; i < n; ++i)
			s[i] = 'A'+i;
		
		printf("Case %d:\n", Case);
		
		do {
			for(int i = 0; i < n; ++i)
				putchar_unlocked(s[i]);
			putchar_unlocked('\n');
		}while(next_permutation(s, s+n) && --k);
		
	}
	
	return 0;
}
