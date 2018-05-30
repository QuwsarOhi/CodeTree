// UVa
// 406 - Prime Cuts

#include <bits/stdc++.h>
#define MAX 1500
using namespace std;

bitset<MAX+100>isPrime;
vector<long long>primes;

void sieveGen(unsigned long long N = MAX) {
    isPrime.set();
	isPrime[0] = isPrime[1] = 0;
    primes.push_back(1);
	for(unsigned long long i = 2; i <= N; i++) {		//Note, N isn't square rooted!
		if(isPrime[i]) {
			for(unsigned long long j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
			primes.push_back(i);
}}}

// 1 2 3 4 5 6

void PRINT(int l, int r) {
    if(l > r) swap(l, r);
    --l, --r;
    if(l < 0) l = 0;
    for(int i = l; i <= r; ++i)
        printf(" %lld", primes[i]);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    sieveGen();
    int n, c;
    
    while(scanf("%d%d", &n, &c) == 2) {
        auto it = upper_bound(primes.begin(), primes.end(), n);
        int len = (it - primes.begin());
        
        printf("%d %d:", n, c);
        if(len%2) {
            if(c == 1)  PRINT(len/2+1, len/2+1);
            else if(2*c-1 >= len) PRINT(1, len);
            else        PRINT(len/2-c+2, len/2+c);
        }
        else {
            if(2*c >= len) PRINT(1, len);
            else {
                PRINT(len/2-c+1, len/2);
                PRINT(len/2+1, len/2+c);
            }   
        }
        printf("\n\n");
    }
    return 0;
}
