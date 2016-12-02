//UVa
//10684 - The jackpot
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
#define vi vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define ll long long

int main()
{
	ll n, a[10010], sum, mx;
	wh(sf(" %lld", &n) && n) {
		fr(i, 0, n) sf("%lld", &a[i]);
		sum = mx = 0;
		for(int i = 0; i < n; i++) {
			sum += a[i];
			if(sum < 0) sum = 0;
			else if(sum > mx) mx = sum;
		}
		if(mx > 0) pf("The maximum winning streak is %lld.\n", mx);
		else pf("Losing streak.\n");
	}
	return 0;
}
