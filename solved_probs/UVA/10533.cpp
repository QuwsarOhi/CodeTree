// UVa
// 10533 - Digit Primes

#include <bits/stdc++.h>
using namespace std;

bitset<1000100>isPrime;
int dp[1000100] = {0};

//Only generates a number is prime or not
void sieve(unsigned long long N) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;

    unsigned long long lim = sqrt(N) + 5;

    for(unsigned long long i = 2; i <= lim; i++) {
        if(isPrime[i]) {
            for(unsigned long long j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
        }
    }
}

bool sumPrime(int n) {
	int sum = 0;
	while(n) {
		sum += n%10;
		n/=10;
	}
	return isPrime[sum];
}

void generate() {
	for(int i = 1; i <= 1000000; ++i) {
		if(isPrime[i] && sumPrime(i))
			dp[i]++;
		dp[i] += dp[i-1];
	}
}


int main() {
	//freopen("in", "r", stdin);
	
	int t, a, b;
	scanf("%d", &t);
	sieve(1000010);
	generate();
	while(t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[b]-dp[a-1]);
	}
	return 0;
}