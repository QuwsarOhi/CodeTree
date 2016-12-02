//UVa
//579 - Clock Hands
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
#define N 27;

/*Equations:
 * Number of minutes since 12 o'clock = 60 * H + M
 * Equation for the angle of hour hand = 0.5(degree) * (60 * H + M)
 * Equation for the angle of minute = 6(degree) * M
*/

int main()
{
	unsigned int h, m, ma;
	double ha, dis;
	wh(sf("%d:%d", &h, &m) && (h || m)) {
		//pf("%d %d\n", h, m);
		ha = ((60 * h) + m)/2.0;
		ma = 6 * m;
		dis = ha - ma;
		if(dis < 0) dis *= -1;
		if(360 - dis < dis) dis = 360- dis;
		pf("%.3lf\n", dis);
	}
	return 0;
}
