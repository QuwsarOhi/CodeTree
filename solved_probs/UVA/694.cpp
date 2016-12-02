//UVa
//694 - The Collatz Sequence
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

using namespace std;

int main()
{
	ll n, lim, tmp, cnt, c = 1;
	wh(sf("%lld %lld", &n, &lim) && (n > 0) && (lim > 0))
	{
		tmp = n;
		cnt = 1;
		//pf("n is %lld\nlim is %lld\n", n, lim);
		wh(1)
		{
			if(tmp % 2 == 0)
				tmp /= 2;
			else
				tmp = (tmp*3) + 1;
			if(tmp == 1)
			{
				cnt++;
				break;
			}
			if(tmp > lim)
				break;
			cnt++;
			//pf("Val is %lld\n", tmp);
		}
		pf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", c++, n, lim, cnt);
		//pf("done\n");
	}
	return 0;
}
