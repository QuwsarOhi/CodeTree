//UVa
//
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

bool cmp(char x, char y)
{
    if(x > y)
        return 1;
    else
        return 0;
}

using namespace std;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    char a[1000000], en[] = "end";
    int c = 1, l;
    wh(sf(" %s", a)) {
        map<char, int>m;
        if(strcmp(a, en) == 0)
            break;
        l = strlen(a);
        bool sorted = 0;
        if(is_sorted(a, a+l, cmp))
            sorted = 1;
        else
            for(int i = 0; i < l; i++)
                m[a[i]]++;
        if(sorted)
            pf("Case %d: 1\n", c++);
        else
            pf("Case %d: %d\n", c++, m.size());
        m.clear();
    }
    return 0;
}
