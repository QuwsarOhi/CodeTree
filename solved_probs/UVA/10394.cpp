//UVa
//10394 - Twin Primes
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
#define N 20000000
using namespace std;

bitset<N+1>bit;
vector<pair<ll, ll> >vp;

void sieve()
{
	register ll i, j, a = -1;
	bit.set();
	bit[0] = bit[1] = 0;
	for(i = 2; i <= N+1; i++)
	{
		if(bit[i])
		{
			if(a == -1)
				a = i;
			else
			{
				if(i - a == 2)
				{
					vp.push_back(mp(a, i));
					//pf("%lld %lld\n", a, i);
				}
				a = i;
			}
			for(j = i*i; j <= N; j+=i)
			{
				//pf("%lld ", j);
				bit[j] = 0;
			}
		}
	}
}


int main()
{
	unsigned ll n;
	sieve();
	wh(sf("%lld", &n) != EOF)
	{
		pf("(%lld, %lld)\n", vp[n-1].first, vp[n-1].second);
	}
	return 0;
}
