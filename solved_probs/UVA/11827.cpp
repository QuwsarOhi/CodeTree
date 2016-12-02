//UVa
//11827 - Maximum GCDfire
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
	ll arr[110];
	ll in, i, mx;
	int t;
	string str;
	sf("%d", &t);
	getchar_unlocked();
	wh(t--)
	{
		i = in = mx = 0;
		stringstream ss;
		getline(cin, str);
		ss << str;
		wh(ss >> in)
			arr[i++] = in;
		for(int j = 0; j < i; j++)
		{
			for(int k = j+1; k < i; k++)
				mx = max(mx, __gcd(arr[j], arr[k]));
		}
		pf("%lld\n", mx);
	}
	return 0;
}
