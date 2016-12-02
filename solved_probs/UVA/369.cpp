//UVa
//369 - Combinations
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
#define N 1000000

using namespace std;

bitset<N>bit;
vector<ll>prime;
int primefactor[N];

void sieve()
{
	bit.set();
	bit[0] = bit[1] = 0;
	for(ll i = 2; i <= N; i++)
	{
		if(bit[i])
		{
			for(ll j = i*i; j <= N; j+=i)
				bit[j] = 0;
			prime.pb(i);
		}
	}
}


void primefactorgen(int n)
{
	memset(primefactor, 0, sizeof(primefactor));
	register int tmp;
	for(size_t i = 0; i < prime.size() && prime[i] <= n; i++)
	{
		tmp = n;
		wh(tmp)
		{
			primefactor[prime[i]] += tmp/prime[i];
			tmp/=prime[i];
		}
	}
}

void primefactordiv(int n)
{
	register int tmp;
	for(size_t i = 0; i < prime.size() && prime[i] <= n; i++)
	{
		tmp = n;
		wh(tmp)
		{
			primefactor[prime[i]] -= tmp/prime[i];
			tmp/=prime[i];
		}
	}
}

int main()
{
	sieve();
	int n, m;
	ll sum;
	wh(sf("%d %d", &n, &m) && n)
	{
		//pf("n : %d, m : %d\n", n, m);
		if(m == 0 || n == m)
			pf("%d things taken %d at a time is 1 exactly.\n", n, m);
		else if(m - 1 == n)
			pf("%d things taken %d at a time is %d exactly.\n", n, m, n);
		else
		{
			//pf("prime size : %d\n", (int)prime.size());
			sum = 1;
			primefactorgen(n);
			primefactordiv(n-m);
			primefactordiv(m);
			for(size_t i = 0; i < prime.size() && prime[i] <= n; i++)
			{
				//pf("%d\n", primefactor[prime[i]]);
				sum *= pow(prime[i], primefactor[prime[i]]);
			}
			pf("%d things taken %d at a time is %lld exactly.\n", n, m, sum);
		}
	}
	return 0;
}
