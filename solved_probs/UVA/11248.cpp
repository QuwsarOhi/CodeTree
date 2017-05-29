//UVa
//12488 - Start Grid
//in queue
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
	register int n, cnt, pos;
	int st[30], ed[30];
	wh(sf(" %d", &n) != EOF)
	{
		fr(i, 0, n) sf("%d", &st[i]);
		fr(i, 0, n) sf("%d", &ed[i]);
		cnt = 0;
		fr(i, 0, n)
		{
			fr(j, 0, n)
				if(ed[i] == st[j])
					pos = j;
			for(int j = pos; j > i; j--)
			{
				swap(st[j], st[j-1]);
				cnt++;
			}
		}
		pf("%d\n", cnt);	
	}
	return 0;
}
