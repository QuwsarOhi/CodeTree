// CodeForces
// B. T-primes
// http://codeforces.com/problemset/problem/230/B
// Number Theory, Prime, Math

#include <bits/stdc++.h>
using namespace std;

bitset<1000100>isPrime;
set<long long>prime;

void sieve() {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;

    for(long long i = 2; i <= 1000000; ++i) {
        if(isPrime[i]) {
            for(int j = i+i; j <= 1000000; j+=i)
                isPrime[j] = 0;
            prime.insert(i*i);
        }
    }
}

int main() {
	//freopen("in", "r", stdin);
    sieve();
    //cout << "size : " << prime.size() << "\n" << endl;
    long long n, x;
    cin >> n;
    while(n--) {
        cin >> x;
        if(prime.find(x) == prime.end())
			printf("NO\n");
		else
			printf("YES\n");
    }
    return 0;
}

