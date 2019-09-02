// UVa 
// 10168 - Summation of Four Primes

// Goldbach's conjecture

#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;
typedef long long ll;

vector<ll> primes;
bitset<MAX+10> isprime;

void sieve(ll n) {
	isprime.set();
	isprime[0] = isprime[1] = 0;
	for(ll i = 2; i <= n; ++i) {
		if(isprime[i]) {
			for(ll j = i+i; j <= n; j += i)
				isprime[j] = 0;
			primes.push_back(i);
		}
	}
}

vector<ll> ans;
bool check(ll v) {
	int idx = lower_bound(primes.begin(), primes.end(), v) - primes.begin();

	while(idx >= 0) {
		if(binary_search(primes.begin(), primes.end(), v-primes[idx])) {
			ans.push_back(primes[idx]);
			ans.push_back(v-primes[idx]);
			return 1;
		}
		--idx;
	}
	return 0;
}

int main() {
	ll n;
	sieve(MAX);

	while(scanf("%lld", &n) == 1) {
		ans.clear();
		if(n%2 and check(n-5)) {
			cout << "2 3 " << ans[0] << " " << ans[1] << "\n"; 
			continue;
		}

		if(n%2 == 0 and check(n-4)) {
			cout << "2 2 " << ans[0] << " " << ans[1] << "\n";
			continue;
		}
		
		cout << "Impossible.\n";
	}

	return 0;
}