//UVa
//10940 - Throwing cards away II
//Pattern (Math)
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
	ll n, temp, x, t;
	register int i;
	wh(sf(" %lld",&n) && n)
	{
		for(i = 1; ; i++)
		{
			if((temp = pow(2, i)) == n)
				break;
			else if(pow(2, i) > n)
			{
				--i;
				temp = pow(2,i);
				break;
			}
		}
		t = n - temp;
		if(temp != n)
			x = 2 + (t-1)*2;
		else if(n == 1)
			x = 1;
		else
			x = temp;
		//pf("t : %lld\ntemp : %lld\n val : %lld\n", t, temp, x);
		pf("%lld\n", x);
	}
	return 0;
}
