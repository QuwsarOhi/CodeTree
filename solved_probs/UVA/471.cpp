//UVa
//471 - Magic Numbers
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
#define N 9876543210
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int main()
{
    //frein;
    //freout;
    bool first = 1;
    register int t;
    sf("%d", &t);
    unsigned ll ma, mb, a[12], b[12], i, j, n, lim, tmp;
    wh(t--) {
        sf("%llu", &n);
        if(!first) pf("\n"); first = 0;
        lim = N/n;
        for(i = 1; i <= lim; i++) {
            j = n*i;
            tmp = i;
            ma = 0;
            memset(a, 0, sizeof(a));
            wh(tmp) { ma = max(++a[tmp%10], ma); tmp/=10; }
            tmp = j;
            memset(b, 0, sizeof(b));
            mb = 0;
            wh(tmp) { mb = max(++b[tmp%10], mb); tmp/=10; }
            if(mb <= 1 && ma <= 1)
                pf("%llu / %llu = %llu\n", j, i, n);
        }
    }
    return 0;
}
