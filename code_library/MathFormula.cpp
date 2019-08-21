// Math Formulas

// Counts number of values in range [l, r] for which dividing by x returns mod value modVal
ll GetModVals(ll l, ll r, ll modVal, ll x) {
    ll low = ceil((l-modVal)/(double)x);
    ll hi = floor((r-modVal)/(double)x);

    return hi-low+1;
}

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
    }}
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
    if(k > n - k)       // as nCk = nC(n-k)
        k = n-k;
    for(int i = 0; i < k; i++) {
        c *= (n-i);     // we can take 1 element from n-i element in c*(n-i) ways
        c /= (i+1);     // due to combination rule, we devide with the number of taken value
    }                   // otherwise it will remain as permutation
    return c;
}

ll fa[MAX], fainv[MAX];                             // fa and fainv must be in global
ll C(ll n, ll r) {                                  // Usable if MOD value is present
    if(fa[0] == 0) {                                // Auto initialize
        fa[0] = 1, fainv[0] = powerMOD(1, MOD-2);
        for(int i = 1; i < MAX; ++i) {
            fa[i] = (fa[i-1]*i) % MOD;              // Constant MOD
            fainv[i] = powerMOD(fa[i], MOD-2);
    }}
    if(n < 0 || r < 0 || n-r < 0) return 0;         // Exceptional Cases
    return ((fa[n] * fainv[r])%MOD * fainv[n-r])%MOD;
}

ll Catalan(int n) {    // Cat(n) = C(2*n, n)/(n+1);
    ll c = C(2*n, n);
    return c/(n+1);
}

// Building Pascle C(n, r)
ll p[MAX][MAX];
void buildPascle() {                                // This Contains values of nCr : p[n][r] 
    p[0][0] = 1;
    p[1][0] = p[1][1] = 1;
    for(int i = 2; i <= 50; i++)
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i)
                p[i][j] = 1;
            else
                p[i][j] = p[i-1][j-1] + p[i-1][j];
}}

ll C(int n, int r) {
    if (r<0 || r>n) return 0;
    return p[n][r];
}

// STARS AND BARS THEOREM / Ball and Urn theorem
// If We have to Make x1+x2+x3+x4 = 12
// Then, the solution can be expressed as : {*|*****|****|**} = {1+5+4+2}, {|*****|***|****} = {0+5+3+4}
// The summation is presented as total value, and the stars represanted as 1, we use bars to seperate values
// Number of ways we can produce the summation n, with k unknowns : C(n+k-1, n) = C(n+k-1, k-1)

// If numbers have lower limits, like x1 >= 3, x2 >= 2, x3 >= 1, x4 >= 1   (Let, the lower limits be l[i])
// Then the solution is : C(n-l1-l2-l3-l4+k-1, k-1) 

// Ball & Urn : how many ways you can put 1 to n number in k sized array so that ther are non decreasing?

ll StarsAndBars(vector<int> &l, int n, int k) {
    if(!l.empty()) for(int i = 0; i < k; ++i) n -= l[i];        // If l is empty, then there is no lower limit
    return C(n+k-1, k-1);
}

// If numbers have both boudaries l1 <= x1 <= r1, l2 <= x2 <= r2, and x1+x2 = N
// then we can reduce the form to x1+x2 = N-l1-l2 and then x only gets upper limit x1 <= r1-l1+1, x2 <= r2-l2+1
// let r1-l1+1 be new l1, and r2-l2+1 be new l2, so x1 <= l1 and x2 <= l2, this limit is the opposite of basic Stars
// and Bars theorem, according to Principle of Inclusion Exclution, this answer can be found as 
// Answer = C(n+k-1, k-1) - C(n-l1+k-1, k-1) - C(n-l2-k-1, k-1) + C(n-l1-l2+k-1, k-1) ......

ll StarsAndBarsInRange(ll l[], ll r[], ll n, ll k) {
    ll d[k+10], p[(1<<k) + 10];
    for(int i = 0; i < k; ++i) {
        d[i] = r[i] - l[i] + 1;
        n -= l[i];
    }
    ll ret = C(n+k-1, k-1); p[0] = 0;
    for(int i = 0; i < k; ++i)                                  // Optimized Complexity : 2^n
        for(int mask = (1<<i); mask < (1 << (i+1)); ++mask) {
            p[mask] = p[mask ^ (1<<i)] + d[i];
            ret += C(n-p[mask]+k-1, k-1) * (__builtin_popcount(mask)&1 ? -1:1);
            ret %= MOD;
        }
    return (ret+MOD)%MOD;
}

vll GetSameMOD(vector<ll>&v) {      // Given an array v, find values k (k > 1), for which v[0]%k = v[1]%k ... = v[n]%k
    ll gcd;                         // If a number K, leaves the same remainder with 2 numbers, then it must divide their difference.
    sort(v.begin(), v.end());       // Find all numbers K which divide all the consecutive differences of all elements in the array.       
    
    for(int i = 0; i+1 < (int)v.size(); ++i) {      // And it we will take the GCD of all consecutive differences
        if(i == 0)  gcd = v[i+1] - v[i];
        else        gcd = __gcd(gcd, v[i+1] - v[i]);
    }
    vector<ll> ret = Divisors(gcd);         // GCD is the maximum value of k
    ret.push_back(gcd);                     // All other values are the divisors of k
    sort(ret.begin(), ret.end());           // NOTE : 1 is not added in the answer
    return ret;
}

ll CountZerosInRangeZeroTo(string n) {              // Returns number of zeros from 0 to n
    ll x = 0, fx = 0, gx = 0;
    for(int i = 0; i < (int)n.size(); ++i){
        ll y = n[i] - '0';
        fx = 10LL * fx + x - gx * (9LL - y);        // Our formula
        //fx += MOD;                                // If ans is to be returned in moded value
        //fx %= MOD;
        x = 10LL * x + y;                           // Now calculate the new x and g(x)
        //x %= MOD;
        if(y == 0LL) gx++;
    }
    return fx+1;
}

ll NumOfSameValueInCombination(int n, int r) {          // Returns number of same value in a set of nCr combination
    if(n < r) return 0;
    return C(n-1, r-1);
}

int cnt[MAX];                                           // cnt[x] : how many times x occures in input
vector<int> genGCD(int mx) {                            // Counts how many number are there of gcd x
    vector<int>sameGCD(mx+1);                           // input the MAXIMUM value        
    for(int gcd = mx; gcd >= 2; --gcd) {                // Complexity : mx log_mx
        int gcdCNT = cnt[gcd];    
        for(int mul = gcd+gcd; mul <= mx; mul += gcd)
            gcdCNT += cnt[mul];
        sameGCD[gcd] = gcdCNT;
    }
    return sameGCD;
}

// Multinomial : nC(k1,k2,k3,..km)    is such that k1+k2+k3+....km = n and ki == kj and ki != kj both can be possible.
// Here Multinomial can be described as : nC(k1, k2, .. km) = nCk1 * (n-k1)Ck2 * (n-k1-k2)Ck3 * ..... (n-k1-k2-...)Ckm
// Let (a+b+c)^3 = a^3 + b^3 + c^3 + 3a^2b + 3b^c + 3b^2a + 3b^2c + 3c^2a + 3c^2b + 6abc
// The coefficient can be retrieved as : 6abc = 3C(1, 1, 1) = 6     3b^2c = 3C(0, 2, 1) = 3
// In general terms it tells how many ways we can place k1, k2, k3, k4 people in 3 unique teams such that k1+k2+k3
// NOTE: if k1=k2=k3 = 2 and n = 6, and players numberd from 1 to 6, then 1,2|3,4|5,6 and 3,4|1,2|5,6 are considered to be different

ll fa[MAX] = {0};                           // fa and fainv must be in global
ll Multinomial(ll N, vector<ll>& K) {       // K contains all k1, k2, k3,  if k1=k2=k3, then just push k1 once!!
    if(fa[0] == 0) {                        // Auto initialize
        fa[0] = 1; //fainv[0] = powerMOD(1, MOD-2);
        for(int i = 1; i < MAX; ++i) {
            fa[i] = (fa[i-1]*i) % MOD;                  // Constant MOD
            //fainv[i] = powerMOD(fa[i], MOD-2);        // Use factorial inverse if required
    }}
    ll k = 1;
    if((int)K.size() == 1)  k = powerMOD(fa[K[0]], N/K[0]);         // k1 = k2 = .. = km, so k occurs N/K time
    else for(auto it : K)   k = (k*fa[it])%MOD;
    return (fa[N]*powerMOD(k, MOD-2))%MOD;                          // Inverse mod
}

ll NumOfWaysToPlace(ll N, ll K) {            // Number of ways to make N/K teams from N people so that each team contais K people
    vector<ll>v;                             // If N = 6, then 1,2|3,4|5,6  and  3,4|1,2|5,6 is considered same
    v.push_back(K);
    return (Multinomial(N, v)*powerMOD(fa[N/K], MOD-2))%MOD;    // divide by k!, as 1,2|3,4|5,6  and  3,4|1,2|5,6 is considered same
}

ull partial_derangement(int n, int r) {        // Finds out how many ways we can place n numbers where r of them are not in their initial place
    ull ans = f[n];								// Factorial of n!
    for(int i = 1; i <= r; ++i) {     // Formula: n! - C(n, 1)*(n-1)! + C(n, 2)*(n-2)! ..... + (-1)^r * C(n,r)*(n-r)!			
        if(i & 1) ans = (ans%MOD - (C(r, i) * f[n-i])%MOD)%MOD;	// Here C(r, i) is because we only have to choose from r elements, not n elements
        else 	  ans = (ans%MOD + (C(r, i) *f[n-i])%MOD)%MOD;
        ans = (ans + MOD)%MOD;
    }
    return ans%MOD;
}

// brent returns a divisor not guaranteed to be prime, returns n if n prime (PYTHON)
from fractions import gcd
from random import randint
def brent(N):
   if N%2==0: return 2
   y,c,m = randint(1, N-1),randint(1, N-1),randint(1, N-1)
   g,r,q = 1,1,1
   while g==1:             
       x = y
       for i in range(r):
          y = ((y*y)%N+c)%N
       k = 0
       while (k<r and g==1):
          ys = y
          for i in range(min(m,r-k)):
             y = ((y*y)%N+c)%N
             q = q*(abs(x-y))%N
          g = gcd(q,N)
          k = k + m
       r = r*2
   if g==N:
       while True:
          ys = ((ys*ys)%N+c)%N
          g = gcd(abs(x-ys),N)
          if g>1:  break
   return g
