//UVa
//575 - Skew Binary
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

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    register int len, i, k, p;
    ll sum;
    char arr[100];
    wh(sf("%s", &arr) && arr[0] != '0')
    {
        len = strlen(arr) - 1;
        p = 1;
        sum = 0;
        for(i = len; i >= 0; i--)
        {
            sum += (arr[i] - '0') * (pow(2, p++) - 1);
           // pf("%lld\n", sum);
        }
        pf("%lld\n", sum);
    }
	return 0;
}
