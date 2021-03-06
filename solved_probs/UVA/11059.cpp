//UVa
//11059 - Maximum Product
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
#define N 100050
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int main()
{
    //frein;
    //freout;
    ll a[30], t = 1, x, mx, n;
    wh(sf("%lld", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            sf("%lld", &a[i]);
        }
        mx = -inf;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) continue;
            x = a[i];
            mx = max(x, mx);
            for(int j = i+1; j < n; j++) {
                if(x == 0) break;
                x*=a[j];
                mx = max(x, mx);
            }
            //if(n == 1) mx = a[0];
        }
        if(mx < 0) mx = 0;
        pf("Case #%lld: The maximum product is %lld.\n\n", t++, mx);
    }
    return 0;
}
