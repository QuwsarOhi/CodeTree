// CodeForces
// http://codeforces.com/contest/839/problem/B
// B. Game of the Rows
// Greedy, Implementation

// Pure Greedy approach
// First Fill up all the seats from 3-6 if there is people more than 3
// Filling 3 people in two double seats is same as filling in one 4 chaired seat (Because in both cases one seat remains empty)
// If there remains any four chaired seat, devide them into two parts, one two paired seat and one single seat
// Now, Start from the bigger value, and elinimate all the positive values (this way, it is sure that most of the double seats are filled properly)

// o = one seated
// t = two seated
// f = four seated

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, v[110];
	scanf("%d%d", &n, &k);
	
	int t = n*2, f = n;
	
	for(int i = 0; i < k; ++i) {
		scanf("%d", &v[i]);
		
		while(v[i] >= 3 && f > 0) {
			v[i] -= 4;
			--f;
		}
	}
	
	int o = f;
	t += f;
	f = 0;
	sort(v, v+k);
	
	for(int i = k-1; i >= 0; --i) {
		while(v[i] > 0 && t > 0) {
			v[i] -= 2;
			--t;
		}
		while(v[i] > 0) {
			o -= v[i];
			v[i] = 0;
		}
		if(o < 0)
			break;
	}
	
	if(o >= 0 && t >= 0 && f >= 0)
		printf("YES\n");
	else
		printf("NO\n");
		
	return 0;
}
