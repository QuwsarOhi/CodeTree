
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define N 500000
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

bitset<N>bit;
vector<ll> factors, prime;
ll power[N];
void sieve() {
	bit.set();
	bit[0] = bit[1] = 0;
	for(ll i = 0; i <= N; i++) {					//it can be limited to sqrt(N)
		if(bit[i]) {								//here it is not used as we want to0
			for(ll j = i * i; j <= N; j += i)		//save the primes in prime vector
				bit[j] = 0;
			prime.pb(i);
} } }

void primeFactor_of_factorial(ll n) {
	memset(power, 0, sizeof(power));
	for(size_t i = 0; prime[i] <= n && i < prime.size(); i++) {
		int tmp = n;
		wh(tmp) {
			power[prime[i]] += tmp / prime[i];		//if we want to generate powers and numbers
			//factors.pb(prime[i]);					//if we only to genetare all the numbers
			tmp /= prime[i];
} } }

void primeFactor(ll n) {
	memset(power, 0, sizeof(power));
	if(prime[n]) {									//First determine if n is a prime number
		power[n]++;
		//factors.pb(n);
	}
	else {
	for(size_t i = 0; prime[i]*prime[i] <= n && i < prime.size(); i++) {
		wh(n % prime[i] == 0) {
			power[prime[i]]++;
			//factors.pb(prime[i]);
			n/=prime[i];
	} }
	if(n > 1) {									//Must be a prime number which is not in prime[i]
		power[n]++;								//it would happen if n is a large number
		//factors.pb(n);
} } }

int main()
{
	sieve();
	//primeFactor(12);
	primeFactor(13);
	//for(size_t i = 0; i < factors.size(); i++)
		//pf("%lld ", factors[i]);
	//factors.clear();
	//pf("\n");
	ll p = 1;
	//primeFactor_of_factorial(12);
	/*for(size_t i = 0; i < power.size(); i++) {
		if(i == power.size()-1) pf("%lld ^ %lld\n", factors[i], power[i]);
		else pf("%lld ^ %lld * ", factors[i], power[i]);
	}*/
		for(size_t i = 0; prime[i] <= 13; i++) {
		if(power[prime[i]] > 0) {
			pf("%lld ^ %lld * ", prime[i], power[prime[i]]);
			p*= pow(prime[i], power[prime[i]]);
		}
	}
	pf("\n%lld\n", p);

	return 0;
}				
