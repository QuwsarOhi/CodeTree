//UVa
//12531 - Hours and Minutes
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
bitset<190>bit;
void gen(int h, int m)
{
    if(h == 12) h = 0;
    if(m == 60) m = 0;
    int hd = (60 * h)/2;
    int md = 6 * m;
    int theta = abs(hd-md);
    if((360 - theta) < theta)
        theta = 360 - theta;
    //pf("%d:%d: %llf\n", h, m, theta);
    //if(theta - (int)theta == 0)
    bit[theta] = 0;
}

int main()
{
    //freopen("out", "w", stdout);
    bit.set();
    for(int h = 1; h <=12; h++)
        for(int m = 0; m <=60; m++)
            gen(h, m);
    int n;
    //pf("%d\n", bit.all());
    wh(sf("%d", &n) != EOF) {
        if(bit[n] == 0)
            pf("Y\n");
        else
            pf("N\n");
    }
    return 0;
}
