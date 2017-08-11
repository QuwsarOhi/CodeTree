//LightOJ
//1045 - Digits of Factorial 
//Number Theory, Factorization, Divisors

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

bitset<1000050>isPrime;
vector<int>primes;

void sieveGen()
{
    isPrime.set();
    //0 and 1 are not prime
	isPrime[0] = isPrime[1] = 0;
	primes.push_back(2);
	int N = 1000005;
	for(long long i = 3; i <= N; i+= 2) {
		if(isPrime[i]) {
			for(long long j = i*i; j <= N; j+= i+i)
                isPrime[j] = 0;
			primes.push_back(i);
		}
	}
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	sieveGen();
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; Case++) {
		ull n;
		scanf("%llu", &n);
		//printf("Case %d: %llu\n", Case, divisor(n));
		int lim = sqrt(double(n));
		int Div = 1;
		for(int i = 0; i < (int)primes.size() && primes[i] <= lim; i++) {
			int co_eff = 0;
			if(n < primes[i])				// This avoids TLE
				break;
			while(n%primes[i] == 0) {
				co_eff++;        			//counts how many prime in the number
				n/=primes[i];               //cuts out the prime
			}
			if(co_eff)
				Div *= (co_eff+1);
		}
		if(n > 1)
			Div *= 2;
		printf("Case %d: %d\n", Case, Div-1);
	}
	return 0;
}
