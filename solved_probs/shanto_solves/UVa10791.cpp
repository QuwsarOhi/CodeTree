// UVa
// 10791 - Minimum Sum LCM

#include <bits/stdc++.h>
using namespace std;

bitset<151000>isPrime;
vector<int>prime;

void sieve() {
	isPrime.set();
	for(int i = 2; i <= 50000; ++i) {
		if(isPrime[i]) {
			prime.push_back(i);
			for(long long j = 2*i; j <= 50000LL; j += i)
				isPrime[j] = 0;
		}
	}
}

long long Calc(long long n) {
	 unordered_map<int, int>cnt;
	 for(int i = 0; i < (int)prime.size() && prime[i] <= n; ++i) {
		 while(n % prime[i] == 0) {
			n /= prime[i];
			if(cnt.find(prime[i]) == cnt.end())
				cnt[prime[i]] = prime[i];
			else
				cnt[prime[i]] *= prime[i];
		}
	}
	
	long long ans = 0;
	for(auto it : cnt)
		ans += it.second;
	
	if(n != 1)
		ans += n;
	
	return ans;
}

int main() {
	sieve();
	
	long long n;
	int Case = 1;
	
	while(scanf("%lld", &n) && n != 0) {
		long long ans = Calc(n);
		if(ans == n)
			++ans;
		else if(ans == 0)
			ans = n + 1;
		printf("Case %d: %lld\n", Case++, ans);
	}
	
	return 0;
}
