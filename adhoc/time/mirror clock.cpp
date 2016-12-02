//UVa
//11650 - Mirror Clock
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
    int t, h, m;
    sf("%d", &t);
    wh(t--) {
        sf("%d:%d", &h, &m);
        h = 23 - h;
        m = (60 - m);
        if(m >= 60) {
            h += m/60;
            m %= 60;
        }
        if(h > 12) h %= 12;
        pf("%02d:%02d\n", h, m);
    }
    return 0;
}
