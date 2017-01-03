
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
#define vi vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define inf std::numeric_limits<int>::max()
#define pf printf
#define wh while
#define ll long long

using namespace std;
vi nill;
int main()
{
    vector<vector<int> >v;
    //v.pb(nill);
    //v.pb(nill);
    v.resize(10);
    pf("%d", v.size());
    v[2].pb(1);
    fr(i, 0, v.size()+1) v[i].clear();
    v.clear();
    pf("\n%d", v.size());
    pf("\n%d", v[0][0]);
    return 0;
}
