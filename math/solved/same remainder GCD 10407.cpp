//UVa
//10407 - Simple division
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

int gcd(int a, int b)
{
	return b == 0 ? a: gcd(b, a%b);
}

int main()
{
	register ll n, x, tmp;
	register int i;
	wh(sf("%lld", &n) && n)
	{
		i = 0;
		wh(sf("%lld", &x) && x)
		{
			x -= n;
			if(i != 0)
				tmp = gcd(tmp, x);
			else
			{
				tmp = x;
				i = 1;
			}
		}
		if(tmp < 0) tmp *= -1;
		pf("%lld\n", tmp);
	}
	return 0;
}
