
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

int c[510][510];
ll x,  y;

inline void mark(int n, int m)
{
	if(m+2 < x && n+1 < y) //{
		c[m+2][n+1] = -1; //pf("1 %d %d, set: %d %d\n", m, n, m+2, n+1); }
	if(m+1 < x && n+2 < y) //{
		c[m+1][n+2] = -1; //pf("2 %d %d, set: %d %d\n", m, n, m+1, n+2); }
	if(m-1 >= 0 && n+2 < y) //{
		c[m-1][n+2] = -1; //pf("3 %d %d, set: %d %d\n", m, n, m-1, n+2); }
	if(m-2 >= 0 && n+1 < y) //{
		c[m-2][n+1] = -1; //pf("4 %d %d, set: %d %d\n", m, n, m-2, n+1); }
	if(m-2 >= 0 && n-1 >= 0) //{
		c[m-2][n-1] = -1; //pf("5 %d %d, set: %d %d\n",m ,n, m-2, n-1); }
	if(m-1 >= 0 && n-2 >= 0)// {
		c[m-1][n-2] = -1; //pf("6 %d %d, set: %d %d\n", m, n, m-1, n-2); }
	if(m+1 < x && n-2 >= 0) //{
		c[m+1][n-2] = -1; //pf("7 %d %d, set: %d %d\n", m, n, m+1, n-2); }
	if(m+2 < x && n-1 >= 0) //{
		c[m+2][n-1] = -1; //pf("8 %d %d, set: %d %d\n", m, n, m+2, n-2); }
}

int main()
{
    ll t, cnt;
    //register int x, y;
    sf("%lld", &t);
    for(ll k = 1; k <= t; k++) {
        sf("%lld %lld", &x, &y);
        if(x >= 3 && y >= 3) {
			pf("Case %lld: %lld\n", k,  (ll)ceil((x*y)/2.0));
			continue;
		}
		else {
			cnt = 0;
			memset(c, 0, sizeof(c));
			//if(x < y) swap(x, y);
			//if(x > y) swap(x, y);
			fr(i, 0, y)
				fr(j, 0, x)
					if(c[j][i] == 0) {
						mark(i, j);
						//pf("i: %d, j: %d\n", j, i);
						cnt++;
					}
					//else
						//pf("i: %d, j: %d is %d\n", i, j, c[j][i]);
		}
		pf("Case %lld: %lld\n", k,  cnt);
    }
    return 0;
}
