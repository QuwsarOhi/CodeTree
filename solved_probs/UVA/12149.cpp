//UVa
//12149 - Feynman
#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define sp(b) if(!b)printf("\n"); b = false;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b);
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pf printf
#define sf scanf
#define wh while

using namespace std;

int main()
{
    long long int n;
    wh(sf("%lld", &n) && n)
        pf("%lld\n", (n*(n+1)*((2*n)+1)/6));
    return 0;
}
