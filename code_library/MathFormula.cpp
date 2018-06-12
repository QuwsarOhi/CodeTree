// Math Formulas

// Find the number of b for which [b1, b2] | [a1, a2]
int FindDivisorInRange(int a1, int a2, int b1, int b2) {
    int a = abs(a1 - a2);
    int b = abs(b1 - b2);
    int gcd = __gcd(a, b);
    return 1 + gcd;
}

// Find how many integers from range m to n are divisible by a or b
int rangeDivisor(int m, int n, int a, int b) {
    int lcm = LCM(a, b);
    int a_divisor = n / a - (m - 1) / a;
    int b_divisor = n / b - (m - 1) / b;
    int common_divisor = n / lcm - (m - 1) / lcm;
    int ans = a_divisor + b_divisor - common_divisor;
    return ans;
}

ll CSOD(ll n) {                             // Cumulative Sum of Divisors in sqrt(n)
    ll ans = 0;
    for(ll i = 2; i * i <= n; ++i) {
        ll j = n / i;
        ans += (i + j) * (j - i + 1) / 2;
        ans += i * (j - i);
    }
    return ans;
}

int CountDivisible(int a, int b, int n) {   // Returns the number of divisible value in range [a, b] by n (NOT TESTED)
    if(a > b) swap(a, b);
    a += n - a%n;
    b -= b%n;
    if(a > b) return 0;
    return ceil((b-a+1)/(double)n);
}

int FactorialCount(int n, int p = 5) {      // Returns how many value of p is present in n!
    int ret = 0, r = p;                     // returns number of trailing zero of n! if p = 5
    while(n/r != 0) {
        ret += n/r;
        r *= p;
    }
    return ret;
}

int TrailingZero(int n, int p = 1) {        // Returns Trailing Zero of n^p
    int cnt = 0;                            // Trailing Zero for any number : min(count_2_as_prime_factor, count_5_as_prime_factor)
    while(n%5 == 0 && n%2 == 0)
        n /= 5, n /= 2, ++cnt;
    return cnt*p;
}

int BirthdayParadox(int days, int targetPercent = 50) {         // Returns Number of people required so that probability is >= target
    int people = 0;                                             // Formula : 1 - (365/365) * (364/365) * (363/365) * .....
    double percent = targetPercent/100.0, gotPercent = 1;
    for( ; gotPercent > percent; ++people)
        gotPercent *= (days-people-1)/(double)days;
    return people;
}

//Building Pascle of 50 rows
long long p[55][54];
void buildPascle() {                                // This Contains values of nCr : p[n][r] 
    p[0][0] = 1;
    p[1][0] = p[1][1] = 1;
    for(int i = 2; i <= 50; i++)
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i)
                p[i][j] = 1;
            else
                p[i][j] = p[i-1][j-1] + p[i-1][j];
        }
    /*for(int i = 0; i <= 50; i++) {                // Uncomment this if you want to see the full triangle
        for(int j = 0; j <=i; j++)
            printf("%lld ", p[i][j]);
        printf("\n");
    }
    */
    return;
}


/* Euler’s Totient function Φ(n) for an input n is count of numbers in {1, 2, 3, …, n} 
 * that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.
 * Phi(4) :  GCD(1, 4) = 1,  GCD(3, 4)
 * so, Phi(4) = 2
 */

int Phi(int n) {                        // Computes phi of n
    int result = n;
    for(int p=2; p*p<=n; ++p) {         // Consider all prime factors of n and subtract their multiples from result
        if(n % p == 0) { 				// p is a prime factor of n
            while (n % p == 0)			// eleminate all p factors from n 
                n /= p;
            result -= result / p;
        }
    }
    if(n > 1)							// if n is still greater than 1, then it is also a prime
        result -= result / n;
    return result;
}

long long phi[MAX];
void computeTotient(int n) {            // Computes phi or Euler Phi 1 to n
    for (int i=1; i<=n; i++)	        // Initialize
        phi[i] = i;
    for (int p=2; p<=n; p++) {	        // Computation
        if (phi[p] == p) {		        // if phi is not computed
            phi[p] = p-1;		        // p is prime and phi(prime) = prime-1;
 
            for (int i = 2*p; i<=n; i += p) { 	    // Sieve like implementation
               phi[i] = (phi[i]/p) * (p-1);         // Add contribution of p to its multiple i by multiplying with (1 - 1/p)
}}}}

// Combination
// Complexity O(k)
long long C(int n, int k) { 
    long long c = 1;
    if(k > n - k)
        k = n-k;
    for(int i = 0; i < k; i++) {
        c *= (n-i);
        c /= (i+1);
    }
    return c;
}

long long catalan(int n) {    // Cat(n) = C(2*n, n)/(n+1);
    long long c = C(2*n, n);
    return c/(n+1);
}
