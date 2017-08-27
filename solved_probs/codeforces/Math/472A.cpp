// CodeForces
// A. Design Tutorial: Learn from Math
// http://codeforces.com/problemset/problem/472/A
// Primes, NumberTheory

#include <bits/stdc++.h>
using namespace std;

bitset<1000010>prime;

void primeGen() {
	prime.set();
	for(int i = 2; i <= 1000000; ++i) {
		if(prime[i]) {
			for(int j = i+i; j <= 1000000; j+=i)
				prime[j] = 0;
		}
	}
}
		


int main() {
	primeGen();
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i < n; ++i) {
		if(!prime[i] && !prime[n-i]) {
			printf("%d %d\n", i, n-i);
			break;
		}
	}
	return 0;
}
