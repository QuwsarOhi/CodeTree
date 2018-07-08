// Modular Arithmatic

// (2^10 % 5) = powMod(2, 10, 5)
long long powMod(long long N, long long P, long long M) {
	if(P==0) return 1;
	if(P%2==0) {
		long long ret = powMod(N, P/2, M)%M;
		return (ret * ret)%M;
	}
    return ((N%M) * (powMod(N, P-1, M)%M))%M;
}

ll powerMOD(ll x, ll y) {                   // Can find modular inverse by a^(MOD-2),  a and MOD must be co-prime
    ll res = 1;
    x %= MOD;
    while(y > 0) {
        if(y&1) res = (res*x)%MOD;          // If y is odd, multiply x with result
        y = y >> 1, x = (x * x)%MOD;
    }
    return res%MOD;
}

// 2^100 = Pow(2, 100)
unsigned long long Pow(unsigned long long N, unsigned long long P) {
	if(P == 0) return 1;
	if(P % 2 == 0) {
		unsigned long long ret = Pow(N, P/2);
		return ret*ret;
	}
    return N * Pow(N, P-1);
}

// calculate A mod B, where A : 0<A<(10^100000) (or greater)
// take input as string and process with aftermod
// calculate A^B mod M, where B : 0<A<(10^100000) (or greater)
// take input as string and process with aftermod : afterMod(inputAsString, Mod-1)      due to fermat theorem

long long afterMod(string str, ll mod) {        // input as string, as it is big, mod is the Mod value (Mod-1 if modding an exponentiation)
	long long ans = 0;
	string :: iterator it;
    
	for(it = str.begin(); it != str.end(); it++)        // mod from first to last
		ans = (ans*10 + (*it -'0')) % mod;
    return ans;
}

// Exponent of Big numbers (N^P % M)
// where N and P is bigger strings (both having length 10^5)
long long bigExpo(char *N, char *P, long long M) {
    long long base = 0, ans = 1;
    for(int i = 0; N[i] != '\0'; ++i)
        base = (base*10LL + N[i] - '0')%M;
    
    for(int j = 0; P[j] != '\0'; ++j)
        ans = (powMod(ans, 10, M) * powMod(base, P[j]-'0', M))%M;
    return ans;
}

// Extended Euclud
// a*x + b*y = gcd(a, b)
// Given a and b calculate x and y so that a * x + b * y = d   (where gcd(a, b) | c)
// x_ans = x + (b/d)n   
// y_ans = y − (a/d)n
// where n is an integer

// Solution only exists if d | c (i.e : c is divisable by d)
ll gcdExtended(ll a, ll b, ll *x, ll *y) {          // C function for extended Euclidean Algorithm
    if (a == 0) {                                   // Base Case
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;                                     // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
ll modInverse(ll a, ll mod) {
    ll x, y;
    ll g = gcdExtended(a, mod, &x, &y);
    if(g != 1) return -1;                   // ModInverse doesnt exist
    ll res = (x%mod + mod) % mod;           // m is added to handle negative x
    return res;
}
