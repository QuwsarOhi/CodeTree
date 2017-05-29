//UVa
// 11219 - How old are you?
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
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int d1, d2, m1, m2, y1, y2, t;
    ll t1, t2;
    sf(" %d", &t);
    for(int c = 1; c<=t; c++){
        sf(" %d/%d/%d", &d1, &m1, &y1);
        sf(" %d/%d/%d", &d2, &m2, &y2);
        //if(y1 >= y2)
          //  if(m1 >= m2)
        t1 = y1*10000+m1*100+d1;
        t2 = y2*10000+m2*100+d2;
        //pf("%lld\n%lld\n", t1, t2);
        t1 = t1 - t2;
        t2 = t1 / 10000;
        if(t1 < 0)
            pf("Case #%d: Invalid birth date\n", c);
        else if(t2 > 130)
            pf("Case #%d: Check birth date\n", c);
        else
            pf("Case #%d: %lld\n", c, t2);
    }
    return 0;
}
