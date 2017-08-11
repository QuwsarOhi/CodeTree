//UVa
//10699 - Count the factors

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
#define ull unsigned long long
#define N 1000000

using namespace std;

bitset<N+2>bt;
vector<ll>primes;

void sieve()
{
	ll i, j;
	bt.set();
	bt[0] = bt[1] = 0;
	for(i = 2; i <= N; i++)
	{
		if(bt[i])
		for(j = i*i; j <= N; j++)
			bt[j] = 0;
		primes.pb(i);
	}
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
	if(n != 1)
		diff_num++;
		
	return diff_num;
}

int main()
{
	sieve();
	ll n;
	wh(sf("%lld", &n) && n)
		pf("%lld : %lld\n", n, numDIFPF(n));
	return 0;
}
