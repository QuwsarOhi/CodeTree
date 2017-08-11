//UVa
//10916 - Factstone Benchmark
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

double lim[257590];

void gen()
{
	lim[0] = 0;
	for(int i = 1; i <= 257582; i++)
		lim[i] = lim[i-1] + log(i)/log(2);
}
int main()
{
	int n;
	gen();
	ll up, down, val, mid;
	wh(sf("%d", &n) && n)
	{
		n = (n - 1960) / 10 + 2;
		val = 1 << n;
		down = 0;
		up = 257582;
		wh(1)
		{
			mid = (up+down)/2;
			if(lim[mid] < val)
				down = mid;
			else if(lim[mid] == n)
				break;
			else
				up = mid;
			if(up == down || down+1 == up)
				break;
		}
		if(lim[up] < val)
			pf("%lld\n", up);
		else
			pf("%lld\n", down);
	}
	return 0;
}
