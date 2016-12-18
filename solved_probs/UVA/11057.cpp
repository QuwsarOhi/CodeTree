//UVa
// 11057 - Exact Sum
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
#define N 9876543210
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

ll dis, p, q, total;

void gen(int x, int y)
{
	if(dis > abs(x - y) || dis == -1) {
		p = x;
		q = y;
		dis = abs(x- y);
	}
}

int main()
{
	ll n, a[10010];
	//bool first = 1;
	wh(sf("%lld", &n) != EOF) {
		dis = -1;
		//if(!first) pf("\n"); first = 0;
		fr(i, 0, n) sf("%lld", &a[i]);
		sf("%lld", &total);
		sort(a, a+n);
		for(register int i = 0; i < n && a[i] <= total; i++) {
			if(i > 0) {
				int x = total - a[i];
				if(binary_search(a, a+i, x))    gen(a[i], x);
				if(binary_search(a+i+1, a+n, x))	gen(a[i], x);
			}
			else {
				int x = total - a[i];
				if(binary_search(a+1, a+n, x)) gen(a[i], x);
			}
		}
		pf("Peter should buy books whose prices are %lld and %lld.\n\n", min(p, q), max(p, q));
	}
	return 0;
}
