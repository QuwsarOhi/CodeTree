//UVa
//616 - Coconuts, Revisited
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
#define ll long long

using namespace std;

int main()
{
	ll n, lim, temp, store;
	wh(sf("%lld", &n) && n >= 0)
	{
		lim = sqrt(n) + 1;
		store = -1;
		for(ll i = 1; i <= lim; i++)
		{
			temp = n;
			bool ok = true;
			for(ll j = 0; j < i; j++)
			{
				if(temp % i == 1)
					temp -= ((temp/i) + 1);
				else
				{
					//pf("broke in %lld\n", i);
					ok = false;
					break;
				}
				//pf("Left coco for %lld is %lld\n", i, temp);
			}
			if(ok && (temp % i == 0))
				store = i;
		}
		if(store != -1) pf("%lld coconuts, %lld people and 1 monkey\n", n, store);
		else pf("%lld coconuts, no solution\n", n);
	}
	return 0;
}
