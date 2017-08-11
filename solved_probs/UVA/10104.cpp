//UVa
//10104 - Euclid Problem
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
#define N 50000
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

ll x, y, d;

//declare x, y, z globally
void extendedEuclid(ll a, ll b) {
    if(b == 0) {x = 1; y = 0; d = a; return;}
    extendedEuclid(b, a%b);
    int x1 = y;
    int y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}


int main()
{
    register ll a, b;
    wh(sf("%lld %lld", &a, &b) != EOF) {
        extendedEuclid(a, b);
        pf("%lld %lld %lld\n", x, y, d);
    }
    return 0;
}
