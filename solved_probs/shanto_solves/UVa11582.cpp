// UVa
// 11582 - Colossal Fibonacci Numbers!

#include <bits/stdc++.h>
using namespace std;

int f[1020], check[1020];
vector<int>fib[1003];

void GeneratePattern(int n) {
	memset(check, 0, sizeof check);
	int a = 0, b = 1;
	fib[n].push_back(0);
	for(int i = 0; i <= 3000; ++i) {
		if(a == 0 && b == 1 && i != 0)
			break;
		swap(a, b);
		b = (a + b)%n;
		fib[n].push_back(a);
	}
	fib[n].pop_back();
}

unsigned long long powMod(unsigned long long x, unsigned long long y, unsigned long long p) {
	unsigned long long res = 1;
	x = x % p;
	while(y > 0) {
		if(y & 1)
			res = (res*x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}


int main() {
	int t;
	unsigned long long a, b, n, pos;
	scanf("%d", &t);

	for(int i = 2; i <= 1000; ++i)
		GeneratePattern(i);
	
	while(t--) {
		scanf("%llu %llu %llu", &a, &b, &n);
		
		if(n == 1) {
			printf("0\n");
			continue;
		}
	
		pos = powMod(a, b, fib[n].size());
		printf("%d\n", fib[n][pos]);
	}
	
	return 0;
}
