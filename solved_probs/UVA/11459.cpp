//UVa
//11459 - Snakes and Ladders
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
#define ull unsigned long long
#define N 50000

using namespace std;

int main()
{
	int t, a, b, c, x, y, pl, tmp;
	int m[110], p[1000010];
	sf("%d", &t);
	wh(t--) {
		bool won = 0;
		for(register int i = 0; i < 1000010; i++)
			p[i] = 1;
		memset(m, -1, sizeof(m));
		sf("%d %d %d", &a, &b, &c);
		wh(b--) {
			sf("%d %d", &x, &y);
			m[x] = y;
		}
		pl = 1;
		for(int i = 1; i <= c; i++, pl++) {
			if(pl > a) pl = 1;
			sf("%d", &x);
			if(!won) {
				tmp = p[pl];
				p[pl]+= x;
				if(m[p[pl]] != -1)
					p[pl] = m[p[pl]];
				//pf("tmp : %d, p : %d indx : %d\n", tmp, p[pl], m[p[pl]]);
				if(p[pl] == 100) won = 1;
				else if(p[pl] > 100) p[pl] = tmp;
			}
		}
		for(int i = 1; i <= a; i++)
			pf("Position of player %d is %d.\n", i, p[i]);
	}
	return 0;
}
