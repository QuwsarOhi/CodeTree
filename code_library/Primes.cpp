// Limit --------- No. of Primes
// 100             25
// 1000            168
// 10,000          1229
// 100,000         9592
// 1,000,000       78498
// 10,000,000      664579         

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

void sieveGen(ll N) {                   // Faster, Will generate all primes <= N
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 3; i*i <= N; i+=2) {
        if(isPrime[i]) {
            for(ll j = i*i; j <= N; j += i)
                isPrime[j] = 0;
    }}
    primes.push_back(2);
    for(int i = 3; i <= N; i+=2)
        if(isPrime[i])
            primes.push_back(i);
}

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

int pd[MAX];                        // Contains minimum prime factor/divisor, for primes pd[x] = x
vector<int>primes;                  // Contains prime numbers
void SieveLinear(int N) {
    for(int i = 2; i <= N; ++i) {
        if(pd[i] == 0) pd[i] = i, primes.push_back(i);                  // if pd[i] == 0, then i is prime
        for(int j=0; j < (int)primes.size() && primes[j] <= pd[i] && i*primes[j] <= N; ++j)
            pd[i*primes[j]] = primes[j];
}}

int pd[MAX];                        // Contains minimum prime factor/divisor, for primes pd[x] = x
vector<int>primes;                  // Contains prime numbers
vector<int>PF[MAX];
void SieveLinearRangePF(int N, ll low, ll hi) {             // also returns unique prime factors in range [low, hi]
    for(int i = 2; i <= N; ++i) {
        if(pd[i] == 0) {
            pd[i] = i, primes.push_back(i);                  // if pd[i] == 0, then i is prime
            for(ll x = (low-1)-(low-1)%i+i; x <= hi; x += i)        // inserting all prime factors [prime will be inserted only once]
                PF[x-low].push_back(i);                             // just to be sure, used low-1, instead of low
        }
        for(int j=0; j < (int)primes.size() && primes[j] <= pd[i] && i*primes[j] <= N; ++j)
            pd[i*primes[j]] = primes[j];
}}

vector<ll> Divisors(ll n) {					// Returns the divisors
    ll lim = sqrt(n);
    vector<ll>divisor;
    for(ll i = 2; i <= lim; i++) {		    // deal with 1 and n manually
        if(n % i == 0) {
            ll tmp = n/i;
            divisor.push_back(tmp);
            if(i != tmp)
                divisor.push_back(i);
    }}
    return divisor;
}

vector<pair<long long, long long> > factorialFactorization(long long n) {	// prime factorization of factorials (n!)
    vector<pair<long long, long long> >V;
    for(long long i = 0; i < (int)primes.size() && primes[i] <= n; i++) {
        long long tmp = n, power = 0;
        while(tmp/primes[i]) {
            power += tmp/primes[i];
            tmp /= primes[i];
        }
        if(power != 0) V.push_back(make_pair(primes[i], power));
	}
    return V;
}

long long numPF(long long n) {			//returns number of prime factors
    long long num = 0;
    for(long long i = 0; primes[i] * primes[i] <= n; i++) {
        while(n % primes[i] == 0) {
            n /= primes[i];
            num++;
    }}
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
bitset<MAX>isPrime;
int divisor[MAX];

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

bool millerTest(int d, int n) {        
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

bool isPrime(int n) {               // Prime Check in log(n)
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for(int i=5; i*i<=n; i+=6)
        if(n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
}
