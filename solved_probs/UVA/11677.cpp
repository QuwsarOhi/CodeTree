//UVa
//11677 - Alarm Clock
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

int main()
{
    ll h1, m1, h2, m2, t1, t2, m;
    wh(sf("%lld %lld %lld %lld", &h1, &m1, &h2, &m2) && (h1 || h2 || m1 || m2)) {
        t1 = h1 * 60 + m1;
        t2 = h2 * 60 + m2;
        if(h1 < h2)
            m = t2 - t1;
        else if((h1 == h2) && (m1 < m2))
            m = m2 - m1;
        else {
            m = 1440 - t1;
            m += t2;
        }
        pf("%lld\n", m);
    }
    return 0;
}
