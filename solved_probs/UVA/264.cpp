//UVa
//264 - Count on Cantor
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

int p[10000002], q[10000002];

inline void build()
{
	register int i, cnt = 0, tmp = 1;
	bool inc = false;
	for(i = 1; i < 10000002; i++)
	{
		if(cnt == 0 && inc)
		{
			p[i] = 1;
			q[i] = tmp;
			//pf("%d/%d inc\n", p[i], q[i]);
			cnt++;
		}
		else if(cnt == 0 && !inc)
		{
			p[i] = tmp;
			q[i] = 1;
			//pf("%d/%d dec\n", p[i], q[i]);
			cnt++;
		}
		else if(cnt != 0 && inc)
		{
			p[i] = p[i-1]+1;
			q[i] = q[i-1]-1;
			//pf("%d/%d inc\n", p[i], q[i]);
			cnt++;
		}
		else
		{
			p[i] = p[i-1]-1;
			q[i] = q[i-1]+1;
			//pf("%d/%d dec\n", p[i], q[i]);
			cnt++;
		}
		if((p[i] == tmp && inc) || (q[i] == tmp && !inc))
		{
			tmp++;
			cnt = 0;
			inc = !inc;
		}
	}
}

int main()
{
	build();
	ll n;
	wh(sf("%lld", &n) != EOF)
	{
		pf("TERM %lld IS %d/%d\n", n, p[n], q[n]);
	}
	return 0;
}
