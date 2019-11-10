Math:
	Primes:
		* Prime generation [sieve]
		* Sublinear prime generation with minimum prime divisor of each value
		* Prime factorization of integers and factorials
		* Fast prime factorization in pure log(n)
		* Number of divisors using formula,    N = (p1^a1)*(p2^a2)...  NOD = (a1+1)*(a2+1)*...
		* Prime check using Miller-Rabin
	Modular Arithmetic:
		* Iterative Power Mod
		* Find A^B 			where A is a big interger of string
		* Find (N^P)%mod 	where N and P both are big integer of string
		* Modular Inverse using extended euclid
	Math Formulas:
		* Number of values in range [l, r] where dividing it by x returns mod value  [GetModVals]
		* Number of values where [b1, b2] | [a1, a2]							[FindDivisorInRange]
		* Number of values in range [l, r] which is divided by a or b               [rangeDivisor]
		* Cumulative sum of divisors in sqrt(n)								[cumulativeSumOfDiv]
		* How many x is present in pertumation of n (n!)		[FactorialCount]
		* Trailing zeroes of n^p 							[TrailingZero]
		* Number of zeroes in range [0 - n]					[CountZerosInRangeZeroTo]
		* Euler Totient single value, and precalculated value  [phi, precalPhi]
		* Combination in minimum linear time O(r) : nCr
		* Combination Precalculated
		* Combination using pascle triangle [use when mod value is not prime] 
		* Catalan Number
		* Birthday paradox [returns number of tries on a collision probability of a fixed bucket size]
		* Stars and Bars basic and with range
		* Multinomial [how many ways to select ai|a(i+1)|... items from n items where n = sum(a_i)]
		* Derangement [Rearrange values in such way that r of them are not on their initial place]



/* Limit --------- No. of Primes
   100             25
   1000            168
   10,000          1229
   100,000         9592
   1,000,000       78498
   10,000,000      664579  */ 
bitset<10000000>isPrime;
vector<long long>primes;
void sieveGen(ll N) {                   			   // Faster, will generate all primes <= N
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 3; i*i <= N; i+=2) {
        if(isPrime[i]) { for(ll j = i*i; j <= N; j += i) isPrime[j] = 0; }
	} primes.push_back(2);
    for(int i = 3; i <= N; i+=2) { if(isPrime[i]) primes.push_back(i); }
}
// Sublinear Prime Factorization
int pd[MAX];                     // Contains minimum prime factor/divisor, for primes pd[x] = x
vector<int>primes;               // Contains prime numbers
void sublinearSieve(int N) {
    for(int i = 2; i <= N; ++i) {
        if(pd[i] == 0) pd[i] = i, primes.push_back(i);        // if pd[i] == 0, then i is prime
        for(int j=0; j < primes.size() && primes[j] <= pd[i] && i*primes[j] <= N; ++j)
            pd[i*primes[j]] = primes[j];
}}
// Basic prime factor
vll primeFactor(ull n) {      
    vll factor;
	for(long long i = 0; i < (int)primes.size() && primes[i] <= n; i++) {
        bool first = 1;
		while(n%primes[i] == 0) {
            if(first) { factor.push_back({primes[i], 0}), first = 0; }
			factor.back().second++, n /= primes[i];
	}} if(n != 1) factor.push_back({n, 1});
	return factor; 
} vi fastFactorize(int x) {
    vector<int>factor;
    while(x > 1) { if(pd[x] != 0) { 
    	factor.push_back(pd[x]); 
    	x /= pd[x]; 
    }} return factor;
} vll factorialPrimeFactor(int n) {					  // prime factorization of factorials (n!)
    vll V;
    for(int i = 0; i < primes.size() && primes[i] <= n; i++) {
        ll tmp = n, power = 0;
        while(tmp/primes[i]) { 
        	power += tmp/primes[i];
        	tmp /= primes[i];
        } if(power != 0) V.push_back(make_pair(primes[i], power));
	} return V;
}
// if n = p1^a1 * p2^a2,... then NOD = (a1+1)*(a2+1)*... 
int NumberOfDivisors(long long n) {       
    if(n <= MAX and isPrime[n]) return 2;
    int NOD = 1;
    for(int i = 0, a = 0; i < (int)primes.size() and primes[i] <= n; ++i, a = 0) {
        while(n % primes[i] == 0) { ++a, n /= primes[i]; }
        NOD *= (a+1);
    } if(n != 1) NOD *= 2;
    return NOD;
}
/* Prime Probability
   Algorithm : Miller-Rabin primality test       Complexity : k * (log n)^3
   This function is called for all k trials. It returns false if n is composite and returns 
   false if n is probably prime. d is an odd number such that  d*(2^r) = n-1 for some r >= 1 */
bool millerTest(int d, int n) {        
    int a = 2 + rand() % (n - 4);       	// Pick a random number in [2..n-2]. 
    int x = powMod(a, d, n);               	// Compute a^d % n
    if (x == 1  || x == n-1)	return 1;
    while (d != n-1) {
        x = (x * x) % n, d *= 2;
        if (x == 1)      return 0;
        if (x == n-1)    return 1;
    }
    return 0;               		      // Return composite
} bool isPrime(int n, int k = 10) {       // Higher value of k gives more accuracy (Use k >= 9)
    if(n <= 1 || n == 4)  	return 0;     // Corner cases
    if(n <= 3) 				return 1;
    int d = n - 1;                          // Find r such that n = 2^d * r + 1 for some r >= 1
    while(d % 2 == 0)  d /= 2;
    for(int i = 0; i < k; i++) { if(miillerTest(d, n) == 0) return 0; }     // Iterate k times
    return 1;
}
ll powerMOD(ll x, ll y, ll MOD) {                   // Can find modular inverse by a^(MOD-2), 
    ll res = 1;                                     //  a and MOD must be co-prime
    x %= MOD;
    while(y > 0) {
        if(y&1) res = (res*x)%MOD;          // If y is odd, multiply x with result
        y = y >> 1, x = (x * x)%MOD;
    } return res%MOD;
}
// calculate A mod B, where A : 0<A<(10^100000) (or greater)
ll afterMod(string str, ll mod) { 
	ll ans = 0;    
	for(auto it = str.begin(); it != str.end(); it++)                    // mod from MSM to LSB
		ans = (ans*10 + (*it -'0')) % mod;
return ans; }
// Exponent of Big numbers (N^P % M)  [where N and P is bigger strings and M is 64 bit integer]
ll bigExpo(char *N, char *P, ll M) {
    ll base = 0, ans = 1;
    for(int i = 0; N[i] != '\0'; ++i) base = (base*10LL + N[i] - '0')%M;
    for(int j = 0; P[j] != '\0'; ++j) ans = (powMod(ans, 10, M) * powMod(base, P[j]-'0', M))%M;
return ans; }
/* Extended Euclid
   a*x + b*y = gcd(a, b)
   Given a and b calculate x and y so that a * x + b * y = d   (where gcd(a, b) | c)
   x_ans = x + (b/d)n, and y_ans = y − (a/d)n;  where n is an integer
   Solution only exists if d | c (i.e : c is divisible by d) */
ll gcdExtended(ll a, ll b, ll *x, ll *y) { 
    if (a == 0) {  *x = 0, *y = 1; return b; }
    ll x1, y1, gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1, *y = x1;euc
    return gcd;
} ll modInverse(ll a, ll mod) {
    ll x, y, g = gcdExtended(a, mod, &x, &y);
    if(g != 1) return -1;                   // Moduler Inverse doesnt exist!
    return (x%mod + mod) % mod;
}
/* ------------------------------------ Math Formulas ------------------------------------ */
// Counts number of values in range [l, r] for which dividing by x returns mod value modVal
ll GetModVals(ll l, ll r, ll modVal, ll x) {
    ll hi = floor((r-modVal)/(double)x), low = ceil((l-modVal)/(double)x);
    return hi-low+1;
}
// Find the number of b for which [b1, b2] | [a1, a2]
int FindDivisorInRange(int a1, int a2, int b1, int b2) { 
    return (__gcd(abs(a1 - a2), abs(b1 - b2)) + 1);
}
// Find how many integers from range m to n are divisible by a or b
int rangeDivisor(int m, int n, int a, int b) {
    int lcm = LCM(a, b), common_divisor = n / lcm - (m - 1) / lcm;
    int a_divisor = n / a - (m - 1) / a, b_divisor = n / b - (m - 1) / b;
    return a_divisor + b_divisor - common_divisor;
}
 // Cumulative Sum of Divisors in sqrt(n)
ll cumulativeSumOfDiv(ll n) {                         
    ll ans = 0;
    for(ll i = 2; i * i <= n; ++i) {
        ll j = n / i;
     	ans += (i + j) * (j - i + 1) / 2, ans += i * (j - i);
    } return ans;
}
// Returns how many times a value P is present in n factorial (n!)
int FactorialCount(int n, int p = 5) {        // Returns number of trailing zero of n! if p = 5
    int ret = 0, r = p;                       
    while(n/r != 0) { ret += n/r; r *= p; }
    return ret;
}
int TrailingZero(int n, int p = 1) {        				    // Returns Trailing Zero of n^p
    int cnt = 0;                            // Trailing Zero for any number : min(cnt_2, cnt_5)
    while(n%5 == 0 && n%2 == 0) n /= 5, n /= 2, ++cnt;
    return cnt*p;
} 
ll CountZerosInRangeZeroTo(string n) {              // Returns number of zeros from 0 to n
    ll x = 0, fx = 0, gx = 0;
    for(int i = 0; i < (int)n.size(); ++i){
        ll y = n[i] - '0';
        fx = 10LL * fx + x - gx * (9LL - y);        // Our formula
        x = 10LL * x + y;                           // Now calculate the new x and g(x)
        if(y == 0LL) gx++;
    } return fx+1;
}
/* Euler’s Totient function Φ(n) for an input n is count of numbers in {1, 2, 3, …, n} that are 
   relatively prime to n, i.e., GCD(i, x) = 1. Phi(4): GCD(1,4)=1, GCD(3,4)=1. so, Phi(4)=2 */
int phi(int n) {                        								   // Computes phi of n
    int result = n;
    for(int p=2; p*p<=n; ++p) {         
        if(n % p == 0) { 				
            while (n % p == 0) n /= p;		  // Eleminate all prime factors and their multiple 
            result -= result / p;
    }}
    if(n > 1) result -= result / n;	   				       // If n > 1, then it is also a prime
    return result;
} 
int phi[MAX];
void precalPhi(int n) { 									     // Precalculated Euler Totient 
    for(int i = 1; i <= n; i++) phi[i] = i;
    for(int p = 2; p <= n; p++) {	        
        if(phi[p] == p) {		       
            phi[p] = p-1;		        
            for(int i = 2*p; i <= n; i += p) { phi[i] = (phi[i]/p) * (p-1); }
}}}
// Combination : Complexity O(k)
ll C(int n, int k) { 
    ll c = 1;
    if(k > n - k) k = n-k;       		// As n_C_k = n_C_(n-k)
    for(int i = 0; i < k; i++) { c *= (n-i); c /= (i+1); }   // take 1 from n-i in c*(n-i) ways          
    return c;			   // due to combination rule, we devide with the number of taken value
}													 // otherwise it will remain as permutation
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
// Building Pascle C(n, r)
ll p[MAX][MAX];
void buildPascle() {                                   // This Contains values of nCr : p[n][r] 
    p[0][0] = 1, p[1][0] = p[1][1] = 1;
    for(int i = 2; i <= MAX; i++)
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) 		p[i][j] = 1;
            else 						p[i][j] = p[i-1][j-1] + p[i-1][j];
}} ll C(int n, int r) {
    if (r<0 || r>n) return 0;
    return p[n][r];
} ll Catalan(int n) {    										// Catalan(n) = C(2*n, n)/(n+1)
    return C(2*n, n)/(n+1);
}
// Birthday Paradox : returns Number of people required so that probability is >= target
int BirthdayParadox(int days, int targetPercent = 50) {         
    int people = 0;                                             
    double percent = targetPercent/100.0, gotPercent = 1;
    for( ; gotPercent > percent; ++people)  gotPercent *= (days-people-1)/(double)days;
    return people;				     // Formula : 1 - (365/365) * (364/365) * (363/365) * .....
}
/* STARS AND BARS THEOREM / Ball and Urn theorem
If We have to Make x1+x2+x3+x4 = 12. Then, the solution can be expressed as : {*|*****|****|**}
= {1+5+4+2}, {|*****|***|****} = {0+5+3+4}. The summation is presented as total value, and the 
stars represanted as 1, we use bars to seperate values. Number of ways we can produce the 
summation n, with k unknowns : C(n+k-1, n) = C(n+k-1, k-1). If numbers have lower limits, like 
x1 >= 3, x2 >= 2, x3 >= 1, x4 >= 1   (Let, the lower limits be l[i]). Then the solution is : 
C(n-l1-l2-l3-l4+k-1, k-1) . Ball & Urn : how many ways you can put 1 to n number in k sized 
array so that ther are non decreasing?
*/
ll StarsAndBars(vector<int> &l, int n, int k) {
    if(!l.empty()) for(int i = 0; i < k; ++i) n -= l[i];           // If l is empty, then there 
    return C(n+k-1, k-1);										   // is no lower limit
}
/* If numbers have both boudaries l1 <= x1 <= r1, l2 <= x2 <= r2, and x1+x2 = N. Then we can 
 reduce the form to x1+x2 = N-l1-l2 and then x only gets upper limit x1 <= r1-l1+1, 
 x2 <= r2-l2+1. Let r1-l1+1 be new l1, and r2-l2+1 be new l2, so x1 <= l1 and x2 <= l2, this 
 limit is the opposite of basic theorem, using Principle of Inclusion Exclution, this answer 
 can be found as, Ans = C(n+k-1, k-1)-C(n-l1+k-1, k-1)-C(n-l2-k-1, k-1)+C(n-l1-l2+k-1, k-1)+...
*/
ll StarsAndBarsInRange(ll l[], ll r[], ll n, ll k) {
    ll d[k+10], p[(1<<k) + 10];
    for(int i = 0; i < k; ++i) { d[i] = r[i] - l[i] + 1, n -= l[i]; }
    ll ret = C(n+k-1, k-1); p[0] = 0;
    for(int i = 0; i < k; ++i)                                    // Optimized Complexity : 2^n
        for(int mask = (1<<i); mask < (1 << (i+1)); ++mask) {
            p[mask] = p[mask ^ (1<<i)] + d[i];
            ret += C(n-p[mask]+k-1, k-1) * (__builtin_popcount(mask)&1 ? -1:1);
        } return ret;
}
/* Multinomial : nC(k1,k2,k3,..km) is such that k1+k2+k3+....km = n and ki == kj and ki != kj 
 both are possible. Here, multinomial can be described as : nC(k1,k2,..,km) = nCk1 * (n-k1)Ck2 
 * (n-k1-k2)Ck3 * ... * (n-k1-k2-...)Ckm.
 Let, (a+b+c)^3 = a^3 + b^3 + c^3 + 3a^2b + 3b^c + 3b^2a + 3b^2c + 3c^2a + 3c^2b + 6abc
 The coefficient can be retrieved as : 6abc = 3C(1, 1, 1) = 6     3b^2c = 3C(0, 2, 1) = 3
 It tells how many ways we can place k1, k2, k3 people in 3 unique teams such that k1+k2+k3=n
 NOTE: if k1=k2=k3 = 2 and n = 6, and players numberd from 1 to 6, then 1,2|3,4|5,6 and 
 3,4|1,2|5,6 are considered to be different */
ll fa[MAX] = {0};                           				  // fa and fainv must be in global
ll Multinomial(ll N, vector<ll>& K) {       				      // K contains all k1, k2, k3, 
    if(fa[0] == 0) {                        	         // if k1=k2=k3, then just push k1 once
        fa[0] = 1;
        for(int i = 1; i < MAX; ++i)  fa[i] = (fa[i-1]*i) % MOD;
 	} ll k = 1;
    if((int)K.size() == 1)  k = powerMOD(fa[K[0]], N/K[0]);                // k occurs N/K time
    else 					for(auto it : K) k = (k*fa[it])%MOD;
    return (fa[N]*powerMOD(k, MOD-2))%MOD;                          		     // Inverse mod
}
// Number of ways to make N/K teams from N people so that each team contais K people
ll NumOfWaysToPlace(ll N, ll K) {       // If N = 6, then 1,2|3,4|5,6  and  3,4|1,2|5,6 is same
    vector<ll>v;                             
    v.push_back(K);											// Divide by k!, as 1,2|3,4|5,6 and 
    return (Multinomial(N, v)*powerMOD(fa[N/K], MOD-2))%MOD;  // 3,4|1,2|5,6 is considered same
}
// Finds how many ways we can place n numbers where r of them are not in their initial place
// Formula: n! - C(n, 1)*(n-1)! + C(n, 2)*(n-2)! ..... + (-1)^r * C(n,r)*(n-r)!
ull partial_derangement(int n, int r) {        
    ull ans = f[n];															 // Factorial of n!
    for(int i = 1; i <= r; ++i) {     			
        if(i & 1) ans = (ans%MOD - (C(r, i) * f[n-i])%MOD)%MOD;	// Here C(r, i) is because we  
        else 	  ans = (ans%MOD + (C(r, i) *f[n-i])%MOD)%MOD;  // only have to choose from r
        ans = (ans + MOD)%MOD;									// elements, not n elements.
    } return ans%MOD;   
}

/* 1. Basic Recurrence:
--------------------
f(n) = x*f(n-1) + y*f(n-2) + z*c
-------------------------------------
| x  y  z |   | f(n-1) |   |  f(n)  |
| 1  0  0 | x | f(n-2) | = | f(n-1) |
| 0  0  1 |   |    c   |   |    c   |
-------------------------------------
    T       x      f     =    ans

  2. Even/Odd Seperate Function:
  ------------------------------
f(n) = if n is even: f(n) = x*f(n-1) -y*f(n-2) + c
               else: f(n) = z*f(n-2)
f(1) = f(2) = 1
Build  :
        |x  y  z|            |0  z  0|          |1|
T_even :|1  0  0|     T_odd :|1  0  0|    f(2) :|1|
        |0  0  1|            |0  0  1|          |c|
T : T_even * T_odd
if n is odd then, f(n) :
    n = n-2
    ans = (T^(n/2)) * f(2)
else if n is odd, f(n):
    n = n-2
    ans = T_odd * (T^(n-1)/2) * f(2)
Why this works:
matrix T contains same number of even and odd function calculations
so from start point (here start point is 2 of f(2)), if there exists same number of
even and odd function calculation then calculating power of T is enough.
else we need to multiply the extra T_even or T_odd with T according to the problem
REF: http://fusharblog.com/solving-linear-recurrence-for-programming-contest/

  3. Cumulative Sum:
  ------------------
To calculate cumulative sum, just add another extra row in base matrix T
and carry the previous sum with new function value as well
Example -> Cumulative sum of:
           f(n) = x*f(n-1) + y*f(n-2) + c
           where, f(1) = f(2) = 1;
Let, S(n) = is the sum of first n values

|1 x y 1|   |S(n-1)|   | S(n) |
|0 x y 1|   |f(n-1)|   | f(n) |
|0 1 0 0| X |f(n-2)| = |f(n-1)|
|0 0 0 1|   |  c   |   |   c  |
-------------------------------
    T     X  f(n-1)  =   f(n)
*/
struct matrix {
    matrix() { memset(mat, 0, sizeof(mat)); }
    long long mat[MAXN][MAXN];
};
matrix mul(matrix a, matrix b, int p, int q, int r) {		 // O(n^3) :: r1, c1, c2  [c1 = r2]
    matrix ans;
    for(int i = 0; i < p; ++i)
      for(int j = 0; j < r; ++j) {
          ans.mat[i][j] = 0;
          for(int k = 0; k < q; ++k)
            ans.mat[i][j] = (ans.mat[i][j]%MOD + (a.mat[i][k]%MOD * b.mat[k][j]%MOD)%MOD)%MOD;
    } return ans;
} matrix matPow(matrix base, ll p, int s) {               // O(logN), s : size of square matrix
    if(p == 1) return base;
    if(p & 1)  return mul(base, matPow(base, p-1, s), s, s, s);
    matrix tmp = matPow(base, p/2, s);
    return mul(tmp, tmp, s, s, s);
} MAT pow(MAT x, ll p, int sz) {                      		// Power using loop
    if(p == 1) return x;
    MAT ret;
    for(int i = 0; i < sz; ++i) ret.m[i][i] = 1;    		// Diagonal Matrix
    while(p > 0) {
        if(p&1) ret = mul(ret, x, sz, sz, sz);
        p = p >> 1, x = mul(x, x, sz, sz, sz);
} return ret; }