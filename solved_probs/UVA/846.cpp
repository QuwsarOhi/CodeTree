//UVa
//846 - Steps
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
	register int t;
	sf("%d", &t);
	wh(t--)
	{
		int a, b, total, sum = 0, step = 1, cnt = 0;
		sf(" %d %d", &a, &b);
		bool next = false;
		total = abs(a-b);
		wh(sum < total)
		{
			sum+=step;
			if(next) step++;
			next = !next;
			cnt++;
			//pf("sum = %d, step = %d\n", sum, step);
		}
		pf("%d\n", cnt);
	}
	return 0;
}
