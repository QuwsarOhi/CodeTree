// Codeforces
// A. Flipping Game
// http://codeforces.com/problemset/problem/327/A

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, v[110], ones = 0, mx_gain = 0;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
		if(v[i])
			++ones;
	}
	
	for(int i = 0; i < n; ++i) {
		int one_flip = 0, zero_flip = 0;
		for(int j = i; j < n; ++j) {
			if(v[j] == 0)
				zero_flip++;
			else
				one_flip++;

			mx_gain = max(mx_gain, zero_flip+(ones-one_flip));
			//mx_gain = max(ones, mx_gain);
		}
	}
	
	printf("%d\n", mx_gain);
	return 0;
}
