// LightOJ
// 1289 - LCM from 1 to n

#include <bits/stdc++.h>
#define MAX 100000000
using namespace std;
 
typedef long long ll;
typedef unsigned int ui;
 
bitset<MAX+5>isPrime;
vector<int>primes;
vector<ui>mul;

void sieveGen(ll N) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 3; i*i <= N; i+=2) {        //Note, N isn't square rooted!
        if(isPrime[i]) {
            for(ll j = i*i; j <= N; j += i)
                isPrime[j] = 0;
    }}
    
    primes.push_back(2);
    mul.push_back(2);

    for(int i = 3; i <= N; i+=2)
        if(isPrime[i]) {
            primes.push_back(i);
            mul.push_back(mul.back() * (ui)i);
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
 
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= n; ++i)
        ans *= getPow(primes[i], n)/primes[i];
    
    vector<int> :: iterator it = upper_bound(primes.begin(), primes.end(), n);
    --it;

    ans *= mul[int(it-primes.begin())];
    return ans;
}
 
int main() {
    primes.reserve(5761499);
    mul.reserve(5761499);

    int t, n;
    sieveGen(MAX);
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        printf("Case %d: %u\n", Case, PF(n));
    }
 
    return 0;
}