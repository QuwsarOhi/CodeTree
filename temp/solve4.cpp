#include <bits/stdc++.h>
#define MAX 100000000
using namespace std;

typedef long long ll;
typedef unsigned int ui;

bitset<MAX+5>isPrime;
ui primes[5761499], cum[5761499], pLen;

void sieveGen(ll N) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 3; i*i <= N; i+=2) {        // Note, N isn't square rooted!
        if(isPrime[i]) {
            for(ll j = i*i; j <= N; j += i)
                isPrime[j] = 0;
    }}
    pLen = 1;
    cum[0] = primes[0] = 2;
    for(int i = 3; i <= N; i += 2)
        if(isPrime[i]) {
            cum[pLen] = cum[pLen-1]*((ui)i);
            primes[pLen++] = i;
        }
}

ui getPow(ll v, ll lim) {
    ll ret = v;
    while(ret * v <= lim)
        ret *= v;

    //cerr << v << " :: " << ret << endl; 
    return (unsigned int)ret;
}

ui PF(int n) {
    ui ans = 1;

    for(int i = 0; i < pLen and primes[i]*primes[i] <= n; ++i)
        ans *= getPow(primes[i], n)/primes[i];

    int pos = (upper_bound(primes, primes+pLen, n)-primes)-1;
    
    //cerr << "pos " << pos << " :: " << cum[pos] << endl;
    ans *= cum[pos];
    return ans;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, n;
    sieveGen(MAX);

    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        printf("Case %d: %u\n", Case, PF(n));
    }

    return 0;
}