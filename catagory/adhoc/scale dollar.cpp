//UVa
//608 - Counterfeit Dollar
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

//-10 if even
//if up then increasing the weight by one
//if down then decreasing the weight by one
//the last ans would be the 

int main()
{
	int a[20], n, len, t;
	char x[50], y[50], z[10];
	sf(" %d", &n);
	wh(n--) {
		memset(a, 0, sizeof(a));
		t = 3;
		wh(t--) {
			sf(" %s %s %s", x, y, z);
			if(z[0] == 'e') {
				len = strlen(x);
				for(int i = 0; i < len; i++)
					a[x[i] - 'A'] = -10;
				len = strlen(y);
				for(int i = 0; i < len; i++)
					a[y[i] - 'A'] = -10;
			}
			else if(z[0] == 'u') {
				len = strlen(x);
				for(int i = 0; i < len; i++)
					if(a[x[i] - 'A'] != -10)
						a[x[i] - 'A']++;
				len = strlen(y);
				for(int i = 0; i < len; i++)
					if(a[y[i] - 'A'] != -10)
						a[y[i] - 'A']--;
			}
			else {
				len = strlen(x);
				for(int i = 0; i < len; i++)
					if(a[x[i] - 'A'] != -10)
						a[x[i] - 'A']--;
				len = strlen(y);
				for(int i = 0; i < len; i++)
					if(a[y[i] - 'A'] != -10)
						a[y[i] - 'A']++;
			}
		}
		int m = 0, p, h = 0;
		for(int i = 0; i < 20; i++) {
			if(a[i] != -10)
				if(abs(a[i]) > m) {
					m = abs(a[i]);
					p = i;
					h = (a[i] < 0)? 0 : 1;
				}
		}
		//pf("h : %d\n", h);
		if(!h) pf("%c is the counterfeit coin and it is light.\n", 'A'+p);
		else pf("%c is the counterfeit coin and it is heavy.\n", 'A'+p);
		//pf("\n\n");
	}
	return 0;
}
