//UVa
//10892 - LCM Cardinality
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

using namespace std;

ll lcm(ll a, ll b)
{
    return a*(b/__gcd(a, b));
}

int main()
{
    ll n, lim, cnt, half, i, x, siz, v[1000], p;
    register int j;
    wh(sf("%lld", &n) && n)
    {
        j = 0;
        lim = sqrt(n);
        cnt = 0;
        for(i = 1; i <= lim; i++)
        {
            if(n % i == 0)
            {
                v[j++] = i;
                x = n/i;
                if(x != i)
                    v[j++] = x;
            }
        }
        siz = j;
        for(i = 0; i < siz ; i++)
        {
            for(j = i + 1; j < siz; j++)
                if(lcm(v[i], v[j]) == n)
                    cnt++;
        }
        pf("%lld %lld\n", n, ++cnt);
    }
    return 0;
}
