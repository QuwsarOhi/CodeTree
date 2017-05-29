//UVa
//10102 - The path in the colored field
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
    int x, y, p_max, t_max, n, lim1, lim3;
    wh(sf("%d", &n) != EOF) {
        vector<pair<int, int> >v1, v3;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                sf("%1d", &x);
                if(x == 1)
                    v1.pb(mp(i, j));
                else if(x == 3)
                    v3.pb(mp(i, j));
            }
        lim1 = v1.size();
        lim3 = v3.size();
        t_max = 0;
        for(int i = 0; i < lim1; i++) {
            p_max = inf;
            x = v1[i].first;
            y = v1[i].second;
            for(int j = 0; j < lim3; j++) {
                p_max = min(p_max, abs(x - v3[j].first)+abs(y-v3[j].second));
                //pf("i: %d, j: %d p_max : %d\n", i, j, p_max);
            }
            t_max = max(p_max, t_max);
        }
        pf("%d\n", t_max);
    }
    return 0;
}
