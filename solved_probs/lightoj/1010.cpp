//Light OJ
//1010 	Knights in Chessboard
#include <bits/stdc++.h>
#define pb push_back
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

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    ll n, m, r, b, a, t;
    sf("%lld", &t);
    for(ll i =1; i <= t; i++)
    {
		sf("%lld %lld", &n, &m);
        if(n <= 1 || m <= 1)
            r = n*m;
        else if(n == 2 || m == 2)
        {
            a = min(n, m);
            b = max(n, m);
            if(b % 4 == 0)
                r = b;
            else if(b % 2 == 0)
                r = b+2;
            else
                r = b+1;
        }
        else
            r = round((n*m)/2.0);
        pf("Case %lld: %lld\n", i, r);
    }
    return 0;
}
