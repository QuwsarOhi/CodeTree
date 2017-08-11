//UVa
//913 - Joana and the Odd Numbers
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
	ll l, n, sum, r;
	wh(sf("%lld", &l) != EOF)
	{
		n = ((l-1)/2) + 1;
		r = -3 + (n-2);
		sum = n*l;
		pf("%lld\n", (sum+r)+(sum+r+2)+(sum+r+4));
	}
	return 0;
}
