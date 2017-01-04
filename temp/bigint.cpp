
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

ll x, y, d;

void extendedEuclid(ll a, ll b)
{
    if(b == 0) {x = 1; y = 0; d = a; return; }
    extendedEuclid(b, a%b);
    ll x1 = y;
    ll y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}

int main()
{
    //frein;
    //freout;
    ll a, b, c, x1, y1, n, upper, lower, x_ans, y_ans, min_cost, cost, p1, p2, x3, y3, x2, y2;
    wh(sf("%lld", &c) && c) {
        sf("%lld %lld %lld %lld", &p1, &a, &p2, &b);
        //pf("a: %lld  b: %lld\n", a, b);
        //swap(a, b);
        //swap(p1, p2);
        extendedEuclid(a, b);
        if(c % d != 0) { pf("failed\n"); continue; }
        bool sw = 0;
        //if(x > y) {
            //swap(a, b);
            //swap(p1, p2);
            extendedEuclid(a, b);
            sw = 1;
            //pf("------swapped------\n");
        }
        x1 = x*c;
        y1 = y*c;
        //pf("x: %lld  y: %lld   c: %lld\n", x, y, c);
        //pf("x1:%lld  y1:%lld  d:%lld  c:%lld\n", x1, y1, d, c);
        lower = ((abs(x1)*d)/(long double)b + EPS);
        upper = ((abs(y1)*d)/(long double)a);
        //min_cost = 1e10;
        //swap(lower, upper);
        //pf("lower: %lld  upper:%lld\n", lower, upper);
        //for(ll i = lower; i <= upper; i++) {
            x2 = x1 + (b*upper)/d;
            y2 = y1 - (a*upper)/d;
            x3 = x1 + (b*lower)/d;
            y3 = y1 - (a*lower)/d;
        if(x2*p1 + y2*p2 < x3*p1+y3*p2) {x = x2; y = y2;}
        else {x = x3; y = y3;}
            //pf("%lld x:%lld y:%lld\n", i, x, y);
            //cost = x*p1 + y*p2;
            //if(cost < min_cost) {
               // min_cost = cost;
                //x_ans = x;
                //y_ans = y;
            //}
        //}
        if(sw) swap(x, y);
        pf("%lld %lld\n", x, y);
    }
    return 0;
}
