//UVa
//12004 - Bubble Sort
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
#define lld long long double
#define ui unsigned int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int> >
#define vvi vector<vector<int> >
#define ull unsigned long long
#define N 50000
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int main()
{
    ri t, n;
    long double sum;
    sf("%lld", &t);
    fr(c, 1, t+1) {
        sf("%d", &n);
        --n;
        if(n == 0) {pf("Case %d: 0\n", c); continue;}
        sum = n*(0.5+(n-1)*0.25);
        if(ceil(sum) == floor(sum)) pf("Case %d: %lld\n", c, (long long int)sum);
        else pf("Case %d: %lld/2\n", c, ((long long int)sum*2)+1);
    }
    return 0;
}
