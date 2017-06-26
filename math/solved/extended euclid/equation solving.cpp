//UVa
// 10090 - Marbles
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

long long x, y, d;

void extendedEuclid(long long a, long long b) {
    if(b == 0) {x = 1; y = 0; d = a; return;}
    extendedEuclid(b, a%b);
    long long x1 = y;
    long long y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}


int main()
{
    //frein;
    //freout;
    long long total, c1, c2, a, b, c, x1, y1, upper, lower, cost_lower, cost_upper;
    while(scanf("%lld", &total) && total)
    {
        bool found = 1;
        scanf("%lld %lld %lld %lld", &c1, &a, &c2, &b);
        extendedEuclid(a, b);							//
        //printf("D : %lld x: %lld y: %lld\n", d, x, y);
        if(total % d == 0) {
            x1 = x * (total/d);
            y1 = y * (total/d);
            //printf("x1: %lld y1: %lld\n", x1, y1);
            lower = ceil((-x1*d)/(double)b);
            upper = floor((y1*d)/(double)a);
            if(upper < lower) found = 0;
            //printf("upper : %lld  lower: %lld\n", upper, lower);
            cost_lower = (x1 + (b/d)*lower)*c1 + (y1 - (a/d)*lower)*c2;
            cost_upper = (x1 + (b/d)*upper)*c1 + (y1 - (a/d)*upper)*c2;
            if(cost_lower < cost_upper) {
                x = x1 + (b/d)*lower;
                y = y1 - (a/d)*lower;
            }
            else {
                x = x1 + (b/d)*upper;
                y = y1 - (a/d)*upper;
            }
            //printf("cost_low: %lld cost_high: %lld\n", cost_lower, cost_upper);
        }
        else found = 0;

        if(found) printf("%lld %lld\n", x, y);
        else printf("failed\n");
    }
    return 0;
}
