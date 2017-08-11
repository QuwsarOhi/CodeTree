//UVa
//10268 - 498
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
#define ld long double
#define ui unsigned int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int> >
#define vvi vector<vector<int> >
#define N 2147483648
#define EPS 1e-9
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

vector<long long>co_efficient;
char a[10000000];

long long Power(long long x, long long y) {
    if(y == 0) return 1;
    if(y&1) return x*Power(x*x, y/2);
    else return Power(x*x, y/2);
}

int main() {
    long long x, n, c;
    while(scanf("%lld", &x) != EOF) {
		scanf(" %[^\n]", a);
        stringstream ss;
        ss << a;
        while(ss >> c) co_efficient.push_back(c);
        n = co_efficient.size() - 1;
        long long ans = 0;
        for(size_t i = 0; i < co_efficient.size(); i++, n--)
			ans += Power(x, n-1)*n*co_efficient[i];
		printf("%lld\n", ans);
		co_efficient.clear();
	}
	return 0;
}
