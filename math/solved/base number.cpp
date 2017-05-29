//UVa
//10176 - Ocean Deep! - Make it shallow!!
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
#define ui unsigned int
#define ull unsigned long long
#define N 500000
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int main()
{
	//char a[10050];
	char c;
	ull tmp, m = 131071;
	wh(sf(" %c", &c) != EOF) {
		tmp = 0;
		tmp = c - '0';
		wh(1) {
			sf(" %c", &c);
			if(c == '#') break;
			tmp <<= 1;
			tmp += c - '0';
			tmp %= m;
		}	
		if(tmp == 0) pf("YES\n");
		else pf("NO\n");	
	}
	return 0;
}
