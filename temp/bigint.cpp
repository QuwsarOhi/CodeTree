//UVa
//11356 - Dates
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
#define N 20000000

using namespace std;

map<string, int>mp1;

bool isleap(ll n)
{
    if(n % 4 == 0 && n % 100 != 0)
        return 1;
    else if(n % 400 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    mp1["January"] = 1;
    mp1["February"] = 2;
    mp1["March"] = 3;
    mp1["April"] = 4;
    mp1["May"] = 5;
    mp1["June"] = 6;
    mp1["July"] = 7;
    mp1["August"] = 8;
    mp1["September"] = 9;
    mp1["October"] = 10;
    mp1["November"] = 11;
    mp1["December"] = 12;
    int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int t, n, d, mn, y, lim;
    char m[20];
    ll l;
    sf("%d", &t);
    fr(k, 1, t+1) {
        sf("%d-%[a-z & A-Z]-%d", &y, m, &d);
        sf(" %lld", &l);
        string x = m;
        mn = mp1[x];
        for(ll i = 1; i <=l; i++) {
            lim = a[mn];
            if(mn == 2)
                if(isleap(y))
                    lim = 29;
            d++;
            if(d > lim) {
                d = 1;
                mn++;
            }
            if(mn > 12) {
                mn = 1;
                y++;
            }
        }
        for(map<string, int>::iterator it = mp1.begin(); it != mp1.end(); it++) {
            if(it->second == mn) {
                x = it->first;
                const char *c = x.c_str();
                //cout << x << endl;
                pf("Case %d: %d-%s-%02d\n", k, y, c, d);
                break;
            }
        }

    }
    return 0;
}
