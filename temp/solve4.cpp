#include <bits/stdc++.h>
#define MAX 1000010
using namespace std;

typedef long long ll;
typedef unsigned int ui;

bitset<MAX>isPrime;
vector<int>primes;

int Power(int x, int y) {                   // Can find modular inverse by a^(MOD-2),  a and MOD must be co-prime
    int res = 1;
    while(y > 0) {
        if(y&1) res = (res*x);          // If y is odd, multiply x with result
        y = y >> 1, x = (x * x);
    }
    return res;
}

void sieveGen(ll N) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2; i <= N; i++) {        //Note, N isn't square rooted!
        if(isPrime[i]) {
            for(ll j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
            primes.push_back(i);
}}}

ui BS(int val, int lim) {
    int lo = 1, hi = 27, mid = 1, p = 1;

    while(lo <= hi) {
        mid = (lo+hi)/2;
        int tmp = Power(val, mid);

        if(tmp < 0 or tmp >= lim)
            hi = mid-1;
        else {
            p = mid;
            lo = mid+1;
        }
    }
    //cerr << val << " P " << p << endl;
    return Power(val, p);
}

ui PF(int n) {
    ui ans = 1;
    ll t = n;

    for(int i = 0; i < primes.size() and primes[i] <= n; ++i)
        ans *= BS(primes[i], t);

    for(int i = 0; i < primes.size() and primes[i] <= n; ++i)
        while(n % primes[i] == 0)
            n /= primes[i];
    if(n != 1)
        ans *= (unsigned int)n;
    return ans;
}

int main() {
    int t, n;
    sieveGen(1000000);

    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        printf("Case %d: %u\n", Case, PF(n));
    }

    return 0;
}