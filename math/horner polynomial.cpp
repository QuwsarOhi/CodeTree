
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
#define vi vector<int>
#define ii pair<int, int>
#define iii pair<ii, int>
#define vii vector<pair<int, int> >
#define ull unsigned long long
#define N 50000
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int co_efficient[1000];

int horner(int x, int n)
{
    int ans = co_efficient[0];
    for(int i = 1; i < n; i++) {
        //printf("%d * %d + %d = ", ans, x, co_efficient[i]);
        ans = ans*x + co_efficient[i];
        //printf("%d\n", ans);
    }
    return ans;
}

int main()
{
    int n, x;
    while(scanf("%d", &x) && x) {
        for(int i = 0; i <= x; i++)
            scanf("%d", &co_efficient[i]);
        n = x+1;
        printf("%d\n", horner(x, n));
    }
    return 0;
}
