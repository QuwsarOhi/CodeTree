#include<bits/stdc++.h>
#define MAX 1e5
using namespace std;

bitset<10000000>isPrime;
vector<long long>primes;

void sieve(unsigned long long N) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    unsigned long long lim = sqrt(N) + 5;
    for(unsigned long long i = 2; i <= lim; i++) {      // change lim to N, if all primes in range N is needed
        if(isPrime[i])
            for(unsigned long long j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
}}

void sieveGen(unsigned long long N) {
    isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for(unsigned long long i = 2; i <= N; i++) {		//Note, N isn't square rooted!
		if(isPrime[i]) {
			for(unsigned long long j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
			primes.push_back(i);
}}}

vector<pair<ull, ull> > primeFactor(ull n) {      
    vector<pair<ull, ull> >factor;
	for(long long i = 0; i < (int)primes.size() && primes[i] <= n; i++) {
        bool first = 1;
		while(n%primes[i] == 0) {
            if(first) {
                factor.push_back({primes[i], 0});
                first = 0;
            }
			factor.back().second++; 
			n/=primes[i];
	}}
	return factor;
}

vector<unsigned long long>divisor;		
void divisors(unsigned long long n) {					// Returns the divisors
    unsigned long long lim = sqrt(n);
    for(unsigned long long i = 2; i <= lim; i++) {		//deal with 1 and n manually
        if(n % i == 0) {
            unsigned long long tmp = n/i;
            divisor.push_back(tmp);
            if(i != tmp)
                divisor.push_back(i);
}}}

vector<pair<long long, long long> > factorialFactorization(long long n) {	//prime factorization of factorials (n!)
	vector<pair<long long, long long> >V;
	for(long long i = 0; i < (int)primes.size() && primes[i] <= n; i++) {
		long long tmp = n, power = 0;
		while(tmp/primes[i]) {
			power += tmp/primes[i];
			tmp /= primes[i];
		}
		if(power != 0)
			V.push_back(make_pair(primes[i], power));
	}
	return V;
}

long long numPF(long long n) {			//returns number of prime factors
	long long num = 0;
	for(long long i = 0; primes[i] * primes[i] <= n; i++) {
		while(n % primes[i] == 0) {
			n /= primes[i];
			num++;
		}
	}
	if(n > 1) num++;		//there might left a prime number which is bigger than primes[i]
	return num;
}

long long numDIFPF(long long n) {		// returns number of different prime factors
	long long diff_num = 0;
	for(long long i = 0; primes[i] * primes[i] <= n; i++) {
		bool ok = 0;
		while(n % primes[i] == 0) {
			n /= primes[i];
			ok = 1;
		}
		if(ok) diff_num++;
	}
	if(n > 1) diff_num++;
	return diff_num;
}

unsigned long long sumPF(long long n) {		// returns sum of prime factors
	unsigned long long sum = 0;
	for(long long i = 0; primes[i] * primes[i] <= n; i++)
		while(n % primes[i] == 0) {
			n /= primes[i];
			sum+=primes[i];
		}
	if(n > 1) sum+= n;
	return sum;
}

int NumberOfDivisors(long long n) {       // if n = p1^a1 * p2^a2,... then NOD = (a1+1)*(a2+1)*... 
    if(n <= MAX and isPrime[n]) return 2;
    int NOD = 1;
    for(int i = 0, a = 0; i < (int)primes.size() and primes[i] <= n; ++i, a = 0) {
        while(n % primes[i] == 0)
            ++a, n /= primes[i];
        NOD *= (a+1);
    }
    if(n != 1) NOD *= 2;
    return NOD;
}

//------Fast Factorization using Sieve-Like algorithm-------
bitset<10001000>isPrime;
int divisor[10000100];

void sieve(long long lim) {             // Prime numbers for the limit should be sieved, otherwise WA
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 0; i <= lim; ++i) {
        if(isPrime[i]) {
            for(long long j = i; j <= lim; j += i) {
                isPrime[j] = 0;
                divisor[j] = i;
}}}}

vector<int> factorize(long long x) {    // This function only iterates over the prime numbers
    int pastDiv = 0;                    // 0 : no divisor is present
    vector<int>factor;
    while(x > 1) {
        if(divisor[x] != 0) {
            factor.push_back(divisor[x]);
            x /= divisor[x];            // now x would be reduced by factor of divisor[x]
    }}
    return factor;
}
//----------------------------------------------------

// Prime Probability
// Algorithm : Miller-Rabin primality test       Complexity : k * (log n)^3
// This function is called for all k trials. It returns false if n is composite and returns false if n is probably prime.
// d is an odd number such that  d*(2^r) = n-1 for some r >= 1

bool miillerTest(int d, int n) {        
    int a = 2 + rand() % (n - 4);       // Pick a random number in [2..n-2]. 
    int x = Pow(a, d, n);               // Compute a^d % n
    if (x == 1  || x == n-1)
       return 1;
    while (d != n-1) {                      // Keep squaring x while one of the following doesn't happen
        x = (x * x) % n;                    // (i)   d does not reach n-1
        d *= 2;                             // (ii)  (x^2) % n is not 1
        if (x == 1)      return 0;          // (iii) (x^2) % n is not n-1
        if (x == n-1)    return 1;
    }
    return 0;               // Return composite
}

bool isPrime(int n, int k = 10) {               // Higher value of k gives more accuracy (Use k >= 9)
    if(n <= 1 || n == 4)  return 0;             // Corner cases
    if(n <= 3) return 1;
    int d = n - 1;                              // Find r such that n = 2^d * r + 1 for some r >= 1
    while(d % 2 == 0)  d /= 2;
    for(int i = 0; i < k; i++)                  // Iterate given nber of 'k' times
        if(miillerTest(d, n) == 0)
            return 0;
    return 1;
}
