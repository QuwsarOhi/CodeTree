//UVa
//637 - Booklet Printing
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
	register int n, p, s, b, l, r, page;
	int a[110];
	queue<pair<int, int> >q;
	wh(sf(" %d", &n) && n) {
		p = ceil(n/4.0);
		l = 1;
		r = n;
		page = 4*p;
		pf("Printing order for %d pages:\n", n);
		if(n == 1) {
			pf("Sheet 1, front: Blank, 1\n");
			continue;
		}
		for(int i = 1; ; i++) {
			//front
			//pf("Page : %d, P : %d\n", 4*p, p);
			if(r < page--) {
				pf("Sheet %d, front: Blank, %d\n", i, l++);
				//r--;
			}
			else
				pf("Sheet %d, front: %d, %d\n", i, r--, l++);
			//back
			//if(l >= r) break;
			//pf("Page : %d\n", 4*p - 1);
			if(r < page--) {
				pf("Sheet %d, back : %d, Blank\n", i, l++);
				//r--;
			}
			else
				pf("Sheet %d, back : %d, %d\n", i, l++, r--);
			if(l >= r) break;
			//--p;
		}
	}
	return 0;
}
