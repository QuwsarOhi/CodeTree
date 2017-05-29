//UVa
//11264 - Coin Collector
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

using namespace std;

int main()
{
	register int t, cnt, n;
	long long sum, a[1010];
	sf(" %d", &t);
	wh(t--)
	{
		sf(" %d", &n);
		fr(i, 0, n) sf(" %lld", &a[i]);
		cnt = 1;
		sum = a[0];
		fr(i, 1, n-1)
			if(sum+a[i] < a[i+1])
			{
				sum+=a[i];
				cnt++;
			}
		pf("%d\n", cnt+1);
	}
	return 0;
}
