
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
#define vi vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define ll long long

using namespace std;

bitset<1000000>bt;
vector<ll>primes;
void sieve()
{
	ll i, j;
	bt.set();
	bt[0] = bt[1] = 0;
	for(i = 2; i <= 1000000; i++)
	{
		if(bt[i])
		for(j = i*i; j <= 1000000; j++)
			bt[j] = 0;
		primes.pb(i);
	}
}

vi primeFactors(ll N) //returns a vector of primeFactors of n
{
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	wh(PF*PF <= N)
	{
		wh(N % PF == 0)
		{
			N /= PF;
			factors.pb(PF);
		}
		PF = primes[++PF_idx];
	}
	if(N != 1)
		factors.pb(N);
	return factors;
}

ll numPF(ll n) //returns number of prime factors
{
	register ll num = 0;
	for(ll i = 0; primes[i] * primes[i] <= n; i++)
	{
		wh(n % primes[i] == 0)
		{
			n /= primes[i];
			num++;
		}
	}
	if(n > 1)
		num++;
	return num;
}

ll numDIFPF(ll n) // returns number of different prime factors
{
	register ll diff_num = 0;
	for(ll i = 0; primes[i] * primes[i] <= n; i++)
	{
		bool ok = 0;
		wh(n % primes[i] == 0)
		{
			n /= primes[i];
			ok = 1;
		}
		if(ok) diff_num++;
	}
	if(n > 1)
		diff_num++;
		
	return diff_num;
}

unsigned ll sumPF(ll n) //returns sum of prime factors
{
	unsigned ll sum = 0;
	for(ll i = 0; primes[i] * primes[i] <= n; i++)
		wh(n % primes[i] == 0)
		{
			n /= primes[i];
			sum+=primes[i];
		}
	if(n > 1)
		sum+= n;
	return sum;
}



/*inputs
 * slowest, 2147483647 is a prime
 * slow, 136117223861 = 104729*1299709
 * 142391208960 = 2^10*3^4*5*7^4*11*13
*/

int main()
{
	sieve();
	ll n;
	pf("Enter 0 to exit\n");
	wh(sf(" %lld", &n) && n)
	{
		vi result = primeFactors(n);
		pf("%lld : ", n);
		for(vi :: iterator it = result.begin(); it != result.end(); it++)
			pf("%d ", *it);
		pf("\n");
		pf("Different prime : %lld\n", numDIFPF(n));
	}
	return 0;
}
