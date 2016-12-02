//UVa
//382 - Perfection
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

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long long int n, sum, x;
    bool first = true;
    wh(sf(" %lld", &n) && n)
    {
        if(first)
        {
            first = false;
            pf("PERFECTION OUTPUT\n");
        }
        x = sqrt(n);
        sum = 1;
        if(n == 1)
        {
            pf("%5lld  DEFICIENT\n", n);
            continue;
        }
        for(long long int i = 2; i <= x; i++)
        {
            if(n%i == 0)
            {
                //pf("%lld ", i);
                //pf("%lld ", n/i);
                sum += i;
                if(i != n/i && i != n) sum += n/i;
            }
        }
        //pf("%lld\n", sum);
        if(sum == n) pf("%5lld  PERFECT\n", n);
        else if(sum < n) pf("%5lld  DEFICIENT\n", n);
        else pf("%5lld  ABUNDANT\n", n);
    }
    pf("END OF OUTPUT\n");
    return 0;
}
