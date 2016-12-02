//UVa
//278 - Chess
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

int main()
{
	register int t, n, m;
	sf("%d", &t);
	char x;
	wh(t--)
	{
		sf(" %c", &x);
		sf("%d %d", &n, &m);
		if(x == 'r')
			pf("%d\n", min(n, m));
		else if(x == 'k')
		{
			//if((m % 2 != 0) && (n%2 != 0)) m--;
			pf("%d\n", (int)round((m * n)/2.0));
		}
		else if(x == 'Q')
			pf("%d\n", min(m, n));
		else
		{
			if(m%2 != 0) m++;
			if(n%2 != 0) n++;
			pf("%d\n", (m*n)/4);
		}
	}
	return 0;
}
