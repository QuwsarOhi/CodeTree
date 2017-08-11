//UVa
//10139 - Factovisors
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
#define N 50000

using namespace std;

bitset<N>bit;
vector<ll>prime;
ll primefactor[N];

void sieve()
{
	bit.set();
	bit[0] = bit[1] = 0;
	for(ll i = 0; i <= N; i++)
	{
		if(bit[i])
		{
			for(ll j = i * i; j <= N; j += i)
				bit[j] = 0;
			prime.pb(i);
		}
	}
}

bool primeFactor(ll n, ll m) //n! m
{
	memset(primefactor, 0, sizeof(primefactor));
	for(size_t i = 0; prime[i] <= m && i < prime.size(); i++)
	{
		int tmp = n;
		wh(tmp)
		{
			primefactor[prime[i]] += tmp/prime[i];
			tmp/=prime[i];
		}
	}
	for(ll i = 0; prime[i]*prime[i] <= m; i++)
	{
		wh(m % prime[i] == 0)
		{
			primefactor[prime[i]]--;
			if(primefactor[prime[i]] < 0)
				return false;
			m/=prime[i];
		}
	}
	if(m > 1)
		if(n < m)
			return false;
	return true;
}

int main()
{
	sieve();
	ll n, m;
	wh(sf("%lld %lld", &n, &m) != EOF)
	{
		if(n >= m)
			pf("%lld divides %lld!\n", m, n);
		else if(primeFactor(n, m))
			pf("%lld divides %lld!\n", m, n);
		else
			pf("%lld does not divide %lld!\n", m, n);
	}
	return 0;
}
