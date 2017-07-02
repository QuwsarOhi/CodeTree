#include <bits/stdc++.h>
using namespace std;

vector<int>divisors[1000];
void Divisors(int n) {					// Finding Divisors without calculating prime numbers
	for(int i = 1; i <= n; ++i)			// We can avoid 1 and 2 if we want
		for(int j = i; j <= n; j+= i)	// Also, we can start from j = i+i
			divisors[j].push_back(i);	// As it is known every number is divisible by itself
}										// divisors[i] contains a list of numbers

int main() {
	
	return 0;
}

