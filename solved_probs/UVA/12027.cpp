//UVa
//12027 - Very Big Perfect Squares
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
	char a[1500];
	int len, tmp;
	wh(fgets_unlocked(a, 1400, stdin))
	{
		if(a[0] == '0')
			break;
		len = strlen(a) - 1;
		if(len%2 == 0)
		{
			tmp = ((a[0] - '0') * 10) + (a[1] - '0');
			pf("%d", (int)sqrt(tmp));
			tmp = len / 2;
			for(int i = 0; i < tmp-1; i++)
				pf("0");
			pf("\n");
		}
		else
		{
			tmp = (a[0] - '0');
			pf("%d", (int)sqrt(tmp));
			tmp = len-1;
			tmp /= 2;
			for(int i = 0; i < tmp; i++)
				pf("0");
			pf("\n");
		}
	}
	return 0;
}
