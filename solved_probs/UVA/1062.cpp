//UVa
//1062 - Containers
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
#define N 200000

using namespace std;

stack<char>empty;
vector<stack<char>>containter;
char a[1000000], e[] = "end";

int add(int i)
{
    for(int j= 0; j < containter.size(); j++)
        if(a[i] <= containter[j].top()) {
            containter[j].push(a[i]);
            return 0;
        }
    containter.pb(empty);
    containter[containter.size()-1].push(a[i]);
    return 1;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int len, t = 1, cnt;
    wh(sf( " %s", a) && strcmp(a, e) != 0) {
        len = strlen(a);
        cnt = 0;
        containter.clear();
        for(int i = 0; i < len; i++)
            cnt += add(i);
        pf("Case %d: %d\n", t++, cnt);
    }
    return 0;
}
