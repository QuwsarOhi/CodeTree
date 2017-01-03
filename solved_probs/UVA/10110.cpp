//UVa
//10110 Light, more light
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
    //frein;
    //freout;
    ull n, lim;
    wh(sf("%lld", &n) && n) {
        lim = sqrt(n);                      //the sqrt(n) generates same number twice if n is a full square number
        if(lim * lim == n) pf("yes\n");     //as every division generates a pair of distinct number, full square of a number dose not generate
        else pf("no\n");                    //a pair of number (as the last number is same)
    }                                       //so every full square number has an odd number of divisors!
    return 0;
}
