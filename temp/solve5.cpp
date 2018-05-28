// UVa
// 294 - Divisors

#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

bitset<MAX+100>isPrime;
vector<long long>primes;

void sieveGen(unsigned long long N) {
    isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for(unsigned long long i = 2; i <= N; i++) {		//Note, N isn't square rooted!
		if(isPrime[i]) {
			for(unsigned long long j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
			primes.push_back(i);
}}}

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

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    sieveGen(MAX+10);
    int t;
    long long l, r, v;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%lld %lld", &l, &r);
        int ans = 0;
        for(long long i = l; i <= r; ++i) {
            int T = NumberOfDivisors(i);
            if(T > ans)
                ans = T, v = i;
        }
        printf("Between %lld and %lld, %lld has a maximum of %d divisors.\n", l, r, v, ans);
    }
}
