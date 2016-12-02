//UVa
// 11947 - Cancer or Scorpio
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
#define N 20000000
using namespace std;


struct astro {
	int s_m, s_d, e_m, e_d;
	char n[20];
}astro[20];

bool isleap(ll n)
{
	if(n % 4 == 0 && n % 100 != 0)
		return 1;
	else if(n % 400 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	strcpy(astro[0].n, "aquarius");
	astro[0].s_d = 21;
	astro[0].s_m = 1;
	astro[0].e_d = 19;
	astro[0].e_m = 2;
	strcpy(astro[1].n, "pisces");
	astro[1].s_d = 20;
	astro[1].s_m = 2;
	astro[1].e_d = 20;
	astro[1].e_m = 3;
	strcpy(astro[2].n, "aries");
	astro[2].s_d = 21;
	astro[2].s_m = 3;
	astro[2].e_d = 20;
	astro[2].e_m = 4;
	strcpy(astro[3].n, "taurus");
	astro[3].s_d = 21;
	astro[3].s_m = 4;
	astro[3].e_d = 21;
	astro[3].e_m = 5;
	strcpy(astro[4].n, "gemini");
	astro[4].s_d = 22;
	astro[4].s_m = 5;
	astro[4].e_d = 21;
	astro[4].e_m = 6;
	strcpy(astro[5].n, "cancer");
	astro[5].s_d = 22;
	astro[5].s_m = 6;
	astro[5].e_d = 22;
	astro[5].e_m = 7;
	strcpy(astro[6].n, "leo");
	astro[6].s_d = 23;
	astro[6].s_m = 7;
	astro[6].e_d = 21;
	astro[6].e_m = 8;
	strcpy(astro[7].n, "virgo");
	astro[7].s_d = 22;
	astro[7].s_m = 8;
	astro[7].e_d = 23;
	astro[7].e_m = 9;
	strcpy(astro[8].n, "libra");
	astro[8].s_d = 24;
	astro[8].s_m = 9;
	astro[8].e_d = 23;
	astro[8].e_m = 10;
	strcpy(astro[9].n, "scorpio");
	astro[9].s_d = 24;
	astro[9].s_m = 10;
	astro[9].e_d = 22;
	astro[9].e_m = 11;
	strcpy(astro[10].n, "sagittarius");
	astro[10].s_d = 23;
	astro[10].s_m = 11;
	astro[10].e_d = 22;
	astro[10].e_m = 12;
	strcpy(astro[11].n, "capricorn");
	astro[11].s_d = 23;
	astro[11].s_m = 12;
	astro[11].e_d = 20;
	astro[11].e_m = 1;
	
	int t, d, m, y, lim, a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	sf("%d", &t);
	fr(k, 1, t+1) {
		sf("%2d %2d %4d", &m, &d, &y);
		//pf("%d %d %d\n", d, m, y);
		for(int i = 1; i <= 280; i++) {
			lim = a[m];
			if(m == 2)
				if(isleap(y))
					lim = 29;
			d++;
			if(d > lim) {
				d = 1;
				m++;
			}
			if(m > 12) {
				m = 1;
				y++;
			}
		}
		//pf("%d %02d/%02d/%04d\n", k, m, d, y);
		for(int i = 0; i < 12; i++) {
			if((d >= astro[i].s_d && m == astro[i].s_m) || (d <= astro[i].e_d && m == astro[i].e_m)) {
				pf("%d %02d/%02d/%04d %s\n", k, m, d, y, astro[i].n);
				break;
			}
			//pf("%d %02d/%02d/%04d %s\n", k, m, d, y, astro[i].n);
			//pf("%s : %d %d -- %d %d\n",astro[i].n, astro[i].s_m, astro[i].s_d, astro[i].e_m, astro[i].e_d);
		}
	}
	return 0;
		
}
