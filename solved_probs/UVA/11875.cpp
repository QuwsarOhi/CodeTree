//UVa
//11875 - Brick Game
#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define fr(i, x, n) for(register int i = x; i < n; i++)
#define wh while

using namespace std;

int main()
{
    register int c, t, n, x, y, p;
    sf("%d", &t);
    fr(c, 1, t+1)
    {
        sf("%d", &n);
        p = (n/2) + 1;
        fr(i, 1, n+1)
        {
            sf("%d", &x);
            if(i == p) y = x;
        }
        pf("Case %d: %d\n",c, y);
    }
    return 0;
}
